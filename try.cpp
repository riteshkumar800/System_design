#include<bits/stdc++.h>
using namespace std;

#define rkm long long
rkm get_gcd(rkm a, rkm b){
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
        rkm nnn;
        rkm xxx;
        rkm yyy;
        cin>>nnn;
        // cin>>xx;
        // cin>>yy;
        vector<int>vv;
        for(int i=0;i<nnn;i++){
            vv.push_back(i);
        }
        int a=0;
        int b=0;
        // cin>>xxx;


        vector<rkm>rit;
        for(int i=0;i<nnn;i++){
           rit.push_back(i);

        }
        // cin>>yyy;

       

        // cin>>yy;
        // stack<int>st;
        // for(int i=1;i<n;i++){
        //     cout<<i+1<<" ";

        // }
        // cout<<1<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<i*3<<" ";

        // }
        // cout<<endl;
        if(nnn==1){
             if(b>0){
        a=1;
        // cm+=y;
    }
}
    vector<rkm>v12=rit;
    // cout<<endl;
       
    vector<rkm>v13=rit;

    rkm pkr=0;
    // cout<<endl;
        if(nnn==1){
             if(b>0){
        a=1;
        // cm+=y;
    }
}
    rkm bkr=nnn;


    rkm rrc=0;
      if(b>0){
        a=1;
        // cm+=y;
    }
    for(int i=0;i<nnn;i++){
          if(b>0){
        a=1;
        // cm+=y;
    }
        rkm svr;
        cin>>svr;
          if(b>0){
        a=1;
        // cm+=y;
    }
        if(svr==-1) rrc++;
          if(b>0){
        a=1;
        // cm+=y;
    }
    }

    for(int i=0;i<nnn;i++){
           rit.push_back(i);

        }

    if(nnn%2!=0){
          if(b>0){
        a=1;
        // cm+=y;
    }
        cout<<"NO"<<endl;
    }
    else{
        for(int i=0;i<nnn;i++){
           rit.push_back(i);

        }
        if(rrc%2==(nnn/2)%2){
              if(b>0){
        a=1;
        // cm+=y;
    }
            cout<<"YES"<<endl;
        }
        else{
              if(b>0){
        a=1;
        // cm+=y;
    }
            cout<<"NO"<<endl;
        }
    }

   
        
// string sn="###";
// // cin>>sn;
// // cout<<sn<<endl;
// rkm cm=0;
//  rkm y=1;
//   vector<rkm>rk;
//   vector<rkm>rkr;
//   for(int i=1;i<=nnn;i++){
//     // rkm y=1;
//     // cin>>y;
//     if(y>0){
//         a=1;
//         // cm+=y;
//     }
//     cm^=i;
    
//     rk.push_back(y);

//   }


// string ss="##";
// if(xxx==nnn){
//     cout<<"NO"<<endl;
//     continue;
// }
// cin>>ss;
// rkm cm=0;
rkm jj=0;
rkm msn=0;

// if(cm==xxx){
//     if(y>0){
//         a=1;
//         // cm+=y;
//     }
//     cout<<"YES"<<endl;
//     for(int i=0;i<nnn;i++){
//         cout<<i<<" ";
//     }
//     if(y>0){
//         a=1;
//         // cm+=y;
//     }
//     cout<<endl;
//     continue;
// }
// if(xxx>nnn/2) {
//     cout<<-1<<endl;
//     continue;
// cout<<"YES"<<endl;
// }
// sort(rk.rbegin(),rk.rend());
// rkm cnt=0;
// rkm lln=0;


// for(int i=0;i<10;i++){
//     // cout<<rk[i]<<" ";
//     // cm+=rk[i];
//     lln+=(rk[i]-xxx);
    


// }
// cnt=xxx^nnn;
// if(nnn%2!=0){
//     // cm+=rk[nnn/2];
//     lln+=(rk[nnn/2]-xxx);
// }
// msn=lln;
// if(xxx==0){

// for(int i=0;i<nnn;i++){
//     // cout<<rk[i]<<" ";
    
//     cm+=rk[i];
//     // lln+=(rk[i]-xxx);
    


// }
// int ls=nnn-1;
// vector<rkm> ud(nnn,0);
// int str=0;
// while(str<=ls){
//     if(rk[ls]-xxx<0){
//         cm+=(rk[str]-xxx);
//         str++;
//         ls--;
//     }
//     else{
//         cm+=(rk[str]-xxx);
//         str++;

//     }
// }

// if(cnt<nnn){
//     ud.push_back((int)cnt);
//     ud[cnt]=1;
//     for(int i=0;i<nnn;i++){
//         if(!ud[i]){
//             rkr.push_back(i);
//         }
//     }
// }
// else{
//     rkm aaa=1;
//     while((aaa<<1)<nnn){
//         aaa<<=1;

//         // rkm bbb=cnt^aaa;

//     }

//      rkm bbb=cnt^aaa;

//      if(bbb>=nnn || b<0){
//         cout<<"NO"<<endl;
//         continue;
//      }

//      rkr.push_back(aaa);
//      rkr.push_back(bbb);
//      ud[aaa]=1;
//      ud[bbb]=1;

//      for(int i=0;i<nnn;i++){
//         if(!ud[i]){
//             rkr.push_back(i);
//         }
//      }

//      for(int f:rkr){
//         cout<<f<<" ";
//      }
//      cout<<endl;
// }
// return 0;
// if(cnt<nnn && cnt >0){
//     if(y>0){
//         a=1;
//         // cm+=y;
//     }
//     cout<<"YES"<<endl;
//     for(int i=0;i<nnn;i++){
//         if(y>0){
//         a=1;
//         // cm+=y;
//     }
//         if(i==0) cout<<cnt<<" ";
//         else if(i==cnt) cout<<0<<" ";
//         else cout<<i<<" ";
//     }
//     if(y>0){
//         a=1;
//         // cm+=y;
//     }
//     cout<<endl;
//     continue;
// }
// if(y>0){
//         a=1;
//         // cm+=y;
//     }
// cout<<"NO"<<endl;
// cout<<endl;
// for(int i=nnn-xxx;i<nnn;i++){
//     if(sn[i]=='R') msn++;
//     // else{
//     //     if(messi<=xxx) cnt++;
//     // }

//     // cout<<cnt<<endl;
// }
// for(int i=0;i<nnn;i++){
//     if(sn[i]=='R') cnt++;
//     else{
//         if(cnt<xxx) {
//             cnt++;
//             msn++;
//         }
//     }

//     // cout<<cnt<<endl;
// }
// if(nnn%2!=0){
//     // cm+=rk[nnn/2];
//     lln+=(rk[nnn/2]-xxx);
// }
// msn=lln;
// if(xxx==0){
//     cout<<cm<<endl;
// }
// else
//  cout<<max(cm,msn)<<endl;

// bool uh=true;
// for(int i=0;i<nnn;i++){
//     rkm o=abs(i+1-rk[i]);
//     rkm rr=abs(xxx-yyy);
//     rkm tt=xxx%yyy;
//     rkm ii=yyy%xxx;
//     // rkm aa=get_gcd(tt,ii);
//     if(tt==0) continue;
// if(ii==0) continue;
//     if(tt!=0 && o%tt==0) continue;
    
//     if(ii!=0 && o%ii==0) continue;
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
    // if(rr!=0){
    //     if(rr!=0 && o%rr==0) continue;

    //     rkm ss=xx%rr;
    //             if(ss!=0 && o%ss==0) continue;

    //     rkm pp=yy%rr;
    //             if(pp!=0 && o%pp==0) continue;

    // }
    // if(rr==0) continue;

    // if(o%xx!=0 && o%yy!=0){
    //     uh=false;
    //     break;
    // }
    // uh=false;

// }
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

//   rkm cp=0;
//   bool ff=true;
//   for(int i=0;i<nn;i++){
//     rkm hp=i+1;
//      if(cp<0){
//         ff=false;
//         break;
//      }
//      if(rk[i]<hp){
//         cp-=(hp-rk[i]);
//      }
//      else{
//         if(rk[i]>0){
//             b=1;
//         }
//         cp+=(rk[i]-hp);
//      }

//   }
//   if(cp<0) ff=false;

//   vv.push_back(0);
// //   cout<<(jj+1)/2<<endl;

// //   if(uh==false) cout<<"NO"<<endl;
// //   else cout<<"YES"<<endl;
// cout<<cnt<<endl;

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