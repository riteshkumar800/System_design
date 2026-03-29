from graphviz import Digraph

dot = Digraph()

# Start arrow (🔥 makes diagram better)
dot.node('', shape='none')
dot.edge('', 'q0')

# States
dot.node('q0', 'q0 (Start)')
dot.node('q1', 'q1 (Final)', shape='doublecircle')

# Transitions
dot.edge('q0', 'q0', label='a')
dot.edge('q0', 'q1', label='b')

# Render
dot.render('dfa_a_star_b', format='png', view=True)