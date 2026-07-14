#include<bits/stdc++.h>
using namespace std;

#define rkm long long
rkm get_gcd(rkm a, rkm b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int nn;
        int xx;
        int yy;
        cin>>nn;
        // cin>>xx;
        // cin>>yy;
        vector<int>vv;
        for(int i=0;i<nn;i++){
            vv.push_back(i);
        }
        int a=0;
        int b=0;
        cin>>xx;
        cin>>yy;
        // stack<int>st;
        // for(int i=1;i<n;i++){
        //     cout<<i+1<<" ";

        // }
        // cout<<1<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<i*3<<" ";

        // }
        // cout<<endl;

  vector<rkm>rk;
  for(int i=0;i<nn;i++){
    rkm y;
    cin>>y;
    if(y>0){
        a=1;
    }
    rk.push_back(y);

  }
string ss="##";
// cin>>ss;
rkm cm=0;
rkm jj=0;

bool uh=true;
for(int i=0;i<nn;i++){
    rkm o=abs(i+1-rk[i]);
    rkm rr=abs(xx-yy);
    rkm tt=xx%yy;
    rkm ii=yy%xx;
    // rkm aa=get_gcd(tt,ii);
    if(tt==0) continue;
if(ii==0) continue;
    if(tt!=0 && o%tt==0) continue;
    
    if(ii!=0 && o%ii==0) continue;
    // if(aa!=0 && o%aa==0) continue;
    

    // if(i+1-yy>=0){
    //      rkm j=abs(i+1-yy);
    // rkm m=abs(j-rk[i]);
    // if(m%xx==0 || m%yy==0) continue;

    // }
    // // if(i+1-yy>=0){
    // //      rkm j=abs(i+1-yy);
    // // rkm m=abs(j-rk[i]);
    // // if(m%xx==0 || m%yy==0) continue;

    // // }
    // // if(i+1+yy<=nn){
    // //      rkm j=abs(i+1-yy);
    // // rkm m=abs(j-rk[i]);
    // // if(m%xx==0 || m%yy==0) continue;


    // // }
    // if(i+1+yy<=nn){
    //      rkm j=abs(i+1+yy);
    // rkm m=abs(j-rk[i]);
    // if(m%xx==0 || m%yy==0) continue;


    // }
    // if(i+1-xx>=0){
    //      rkm j=abs(i+1-xx);
    // rkm m=abs(j-rk[i]);
    // if(m%xx==0 || m%yy==0) continue;


    // }
    // if(i+1+xx<=nn){
    //      rkm j=abs(i+1+xx);
    // rkm m=abs(j-rk[i]);
    // if(m%xx==0 || m%yy==0) continue;


    // }
    // if(i+1+xx<=nn){
    //      rkm j=abs(i+1-xx);
    // rkm m=abs(j-rk[i]);
    // if(m%xx==0 || m%yy==0) continue;


    // }
    // rkm j=abs(i+1-yy);
    // rkm m=abs(j-rk[i]);
    // if(o==0) continue;
    // if(rr!=0 && o%rr==0) continue;
    if(rr!=0){
        if(rr!=0 && o%rr==0) continue;

        rkm ss=xx%rr;
                if(ss!=0 && o%ss==0) continue;

        rkm pp=yy%rr;
                if(pp!=0 && o%pp==0) continue;

    }
    if(rr==0) continue;

    if(o%xx!=0 && o%yy!=0){
        uh=false;
        break;
    }
    // uh=false;

}
// cout<<ss<<endl;

// for(int i=0;i<nn;i++){
//     if(ss[i]=='#'){
//         if(cm>0){
//             vv.push_back(0);
//         }

//      cm++;
//      if(cm>0){
//             vv.push_back(0);
//         }
//      jj=max(jj,cm);
//     }
//     else{
//         // if(cm>1){
//         //     jj+=(cm+1)/2;

//         // }
//         if(cm>0){
//             vv.push_back(0);
//         }
//         cm=0;

//     }
//     // if(cm>1) jj+=(cm+1)/2;

// }
//  if(cm>1) jj+=(cm+1)/2;

  rkm cp=0;
  bool ff=true;
  for(int i=0;i<nn;i++){
    rkm hp=i+1;
     if(cp<0){
        ff=false;
        break;
     }
     if(rk[i]<hp){
        cp-=(hp-rk[i]);
     }
     else{
        if(rk[i]>0){
            b=1;
        }
        cp+=(rk[i]-hp);
     }

  }
  if(cp<0) ff=false;

  vv.push_back(0);
//   cout<<(jj+1)/2<<endl;

  if(uh==false) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;

// if(nn==1){
//     cout<<1<<endl;
//     continue;
// }

// int x=0;
// int y=0;
// vector<int>v2;
//         if(nn==2){
            
//             cout<<-1<<endl;
//             continue;
//         }

//         vector<rkm> rkts;
//         rkm sd=0;
//         rkm smm=6;
//         rkm cnt=1;

//         if(nn==3){
//             cout<<1<<" "<<2<<" "<<3<<endl;
//             continue;
//         }

//         rkts.push_back(1);
//         rkts.push_back(2);
//         rkts.push_back(3);




//         for(int i=4;i<=nn;i++){

//             if(i==nn-2){
//                 v2.push_back(nn);
//             }
            
//             rkts.push_back(smm);
//             // smm+=cnt;
//             smm+=smm;
            
//             if(i==nn-3){
//                 v2.push_back(nn);
//             }
//             cnt*=2;
//             // sd+=u;
//         }
//         // rkts.push_back(smm);
//         int f=0;
//         int g=0;
//         for(int i=0;i<nn;i++){
//             if(i==nn-3){
//                 v2.push_back(nn);
//             }
//             cout<<rkts[i]<<" ";


//         }
//         cout<<endl;
        
//     }
}
}