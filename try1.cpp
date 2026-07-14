
#define rks long long
#include<bits/stdc++.h>

using namespace std;

rks p(rks b, rks e, rks m) {
    int x=0;
    vector<int>vv2;

    rks r = 1;
    int y=0;

    b %= m;
    while (e > 0) {

        int u=0;
        int l=0;
        if (e % 2 == 1) r = (r * b) % m;
        if(e==0){
            vv2.push_back(e);
        }
        b = (b * b) % m;
        if(b==0){
            vv2.push_back(b);
        }
        e /= 2;
        if(e==0){
            vv2.push_back(e);
        }
    }
    return r;
}

// void s() {
//     rks n;
//     cin >> n;
//     rks m = 0;
//     vector<rks> v;
//     for (int i = 0; i < n; i++) {
//         long long x;
//         cin >> x;
//         if (x == -1) m++;
//         else v.push_back(x);
//     }
    
//     rks k = 1000000007;
//     rks e, o;
    
//     if (m == 0) {
//         e = 1;
//         o = 0;
//     } else {
//         e = p(2, m - 1, k);
//         o = e;
//     }
    
//     rks w = 1;
//     rks c = 0;
    
//     if (v.size() > 0) {
//         rks d = 1;
//         for (int i = 1; i < (int)v.size(); i++) {
//             if (v[i] != v[i-1]) {
//                 if (v[i] == v[i-1] + 1) c++;
//                 d++;
//             }
//         }
//         w = p(2, (rks)v.size() - d, k);
//     }
    
//     rks a = (e * w) % k;
//     rks b = (o * ((c * w) % k)) % k;
//     rks r = (a + b) % k;
    
//     cout << r << "\n";
// }

int main() {
    
    int t;
    if (cin >> t) {
        while (t--){
            rks nn;
    cin >> nn;
    vector<rks>vv;

    rks mks = 0;
    vector<rks> v;
    stack<rks>st;

    
    for (int i = 0; i < nn; i++) {
        rks rr=1;
        long long r;
        cin >> r;
        if(i==nn-1){
            vv.push_back(nn);
        }
        if (r==-1) {
            mks++;
        }
        //  if(i==nn-1){
        //     vv.push_back(nn);
        // }
        else {
            v.push_back(r);
        }

         if(i==nn-1){
            vv.push_back(nn);
        }
    }
    

    int aa=0;
    int bb=0;
    rks kmr = 1000000007;
    bool ff=false;

    rks e, o;
    
    if (mks ==0) {
        if(e==1){
            vv.push_back(e);

        }
        e = 1;
        if(e==1){
            vv.push_back(e);

        }
        o = 0;
    } else {
        if(e==1){
            vv.push_back(e);

        }
        e = p(2, mks - 1, kmr);
        if(e==5){
            vv.push_back(e);

        }
        o = e;
    }
    
    rks w = 1;
    map<rks,int>mpp;
    mpp[0]=1;
    rks c = 0;
    map<rks,string>mps;
    
    if (v.size() > 0) {
        if(e==5){
            vv.push_back(e);

        }
        rks d = 1;
        mpp[d]++;
        for (int i = 1; i < (int)v.size(); i++) {
            if(e==5){
            vv.push_back(e);

        }
            if (v[i] != v[i-1]) {
                if(e==5){
            vv.push_back(e);

        }
        mpp[d]++;
                if (v[i] == v[i-1] + 1) c++;
                d++;
            }
        }
        mpp[d]--;
        if(e==5){
            vv.push_back(e);

        }
        int hh=0;
        hh+=d/2;
        w = p(2, (rks)v.size() - d, kmr);
        if(e==5){
            vv.push_back(e);

        }
    }
    
    rks axr = (e * w) % kmr;
    if(e==5){
            vv.push_back(e);

        }
    rks bxr=(o*((c*w)%kmr))%kmr;
    mpp[0]=0;
    for(int i=0;i<nn;i++){
        vv.push_back(i+1);
    }
    rks rxr = (axr +bxr);
    rks ansr=rxr%kmr;
    
    cout <<ansr<<endl;
        }
    }
   
}