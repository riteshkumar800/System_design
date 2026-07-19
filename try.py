def solve(reference_day, shipments, route_profiles, tracking_events, weather_alerts, warehouse_logs):
    from collections import defaultdict
    
    reference_day = int(reference_day)
    
    valid_routes = set()
    route_profile_dict = {}
    for route in route_profiles:
        routeId = str(route[0])
        standardTransitDays = int(route[1])
        maxWarehouseProcessingHours = int(route[2])
        valid_routes.add(routeId)
        route_profile_dict[routeId] = (standardTransitDays, maxWarehouseProcessingHours)
        
    valid_shipments = set()
    shipment_dispatch_day = {}
    for shipment in shipments:
        shipmentId = str(shipment[0])
        dispatchDay = int(shipment[3])
        valid_shipments.add(shipmentId)
        shipment_dispatch_day[shipmentId] = dispatchDay

    routeWeatherAlertScore = defaultdict(int)
    severity_weights = {'LOW': 1, 'MEDIUM': 2, 'HIGH': 3}
    for alert in weather_alerts:
        routeId = str(alert[1])
        alertDay = int(alert[2])
        severity = str(alert[3])
        
        if routeId in valid_routes and 1 <= alertDay <= reference_day and severity in severity_weights:
            routeWeatherAlertScore[routeId] += severity_weights[severity]

    shipment_events = defaultdict(list)
    valid_statuses = {'IN_TRANSIT', 'DELAYED', 'DELIVERED'}
    for event in tracking_events:
        shipmentId = str(event[1])
        eventDay = int(event[2])
        status = str(event[3])
        
        if shipmentId in valid_shipments:
            dispatchDay = shipment_dispatch_day[shipmentId]
            if dispatchDay <= eventDay <= reference_day and status in valid_statuses:
                shipment_events[shipmentId].append((eventDay, status))

    shipment_warehouse_hours = defaultdict(int)
    for log in warehouse_logs:
        shipmentId = str(log[1])
        processDay = int(log[2])
        processingHours = int(log[3])
        
        if shipmentId in valid_shipments:
            dispatchDay = shipment_dispatch_day[shipmentId]
            if dispatchDay <= processDay <= reference_day and processingHours >= 0:
                shipment_warehouse_hours[shipmentId] += processingHours

    route_shipment_count = defaultdict(int)
    route_delay_events_total = defaultdict(int)
    shipment_stats = {}

    for i, shipment in enumerate(shipments):
        shipmentId = str(shipment[0])
        shipmentName = str(shipment[1])
        routeId = str(shipment[2])
        dispatchDay = int(shipment[3])
        
        route_shipment_count[routeId] += 1
        
        events = shipment_events[shipmentId]
        validTrackingEventCount = len(events)
        delayEventCount = sum(1 for e in events if e[1] == 'DELAYED')
        
        route_delay_events_total[routeId] += delayEventCount
        
        isDelivered = any(e[1] == 'DELIVERED' for e in events)
        
        if validTrackingEventCount > 0:
            latestTrackingDay = max(e[0] for e in events)
            daysWithoutUpdate = reference_day - latestTrackingDay
        else:
            daysWithoutUpdate = reference_day + 1
            
        totalWarehouseProcessingHours = shipment_warehouse_hours[shipmentId]
        
        shipment_stats[shipmentId] = {
            'shipmentName': shipmentName,
            'routeId': routeId,
            'dispatchDay': dispatchDay,
            'validTrackingEventCount': validTrackingEventCount,
            'delayEventCount': delayEventCount,
            'isDelivered': isDelivered,
            'daysWithoutUpdate': daysWithoutUpdate,
            'totalWarehouseProcessingHours': totalWarehouseProcessingHours,
            'input_index': i
        }

    routeAverageDelayEventCount = {}
    for routeId in valid_routes:
        count = route_shipment_count[routeId]
        if count > 0:
            routeAverageDelayEventCount[routeId] = route_delay_events_total[routeId] // count
        else:
            routeAverageDelayEventCount[routeId] = 0

    eligible_shipments = []
    
    for shipmentId, stats in shipment_stats.items():
        if stats['isDelivered']:
            continue
            
        routeId = stats['routeId']
        standardTransitDays, maxWarehouseProcessingHours = route_profile_dict[routeId]
        expectedDeliveryDay = stats['dispatchDay'] + standardTransitDays
        
        riskScore = 0
        if stats['daysWithoutUpdate'] >= 5:
            riskScore += 4
        if stats['validTrackingEventCount'] == 0:
            riskScore += 3
        if stats['delayEventCount'] >= 2:
            riskScore += 3
        if routeWeatherAlertScore.get(routeId, 0) >= 4:
            riskScore += 2
        if stats['totalWarehouseProcessingHours'] > maxWarehouseProcessingHours:
            riskScore += 3
        if stats['delayEventCount'] > routeAverageDelayEventCount.get(routeId, 0):
            riskScore += 2
        if reference_day > expectedDeliveryDay:
            riskScore += 4
            
        if riskScore >= 10:
            riskLevel = 'HIGH'
        elif riskScore >= 6:
            riskLevel = 'MEDIUM'
        else:
            riskLevel = 'LOW'
            
        if riskLevel in ('HIGH', 'MEDIUM'):
            eligible_shipments.append({
                'shipmentName': stats['shipmentName'],
                'riskLevel': riskLevel,
                'riskScore': riskScore,
                'daysWithoutUpdate': stats['daysWithoutUpdate'],
                'input_index': stats['input_index']
            })

    if not eligible_shipments:
        return "NA"
        
    eligible_shipments.sort(key=lambda x: (
        0 if x['riskLevel'] == 'HIGH' else 1,
        -x['riskScore'],
        -x['daysWithoutUpdate'],
        x['input_index']
    ))
    
    final_output = "#".join(
        f"{s['shipmentName']}-{s['riskLevel']}-{s['riskScore']}-{s['daysWithoutUpdate']}" 
        for s in eligible_shipments
    )
    
    return final_output