#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--){
      int a, b, xk, yk, xq, yq;
      cin>>a>>b>>xk>>yk>>xq>>yq;
      if(abs(yq-yk)==2*a &&abs(xq-yk)==0){
        cout<<2<<endl;
        goto func;
      }
      if(abs(xq-xk)==2*a &&abs(yq-yk)==0){
        cout<<2<<endl;
         goto func;
        
      }
       if(abs(yq-yk)==2*b &&abs(xq-yk)==0){
        cout<<2<<endl;
         goto func;

      }
      if(abs(xq-xk)==2*b &&abs(yq-yk)==0){
        cout<<2<<endl;
         goto func;
        
      }
      if(abs(xk-xq)==abs(yk-yq)==abs(b-a)){
        cout<<2<<endl;
         goto func;

      }
      //
      if(abs(yq-yk)==a &&abs(xq-yk)==a+b){
        cout<<2<<endl;
         goto func;

      }
      if(abs(xq-xk)==a &&abs(yq-yk)==a+b){
        cout<<2<<endl;
         goto func;
        
      }
       if(abs(yq-yk)==b &&abs(xq-yk)==a+b){
        cout<<2<<endl;
         goto func;

      }
      if(abs(xq-xk)==b &&abs(yq-yk)==a+b){
        cout<<2<<endl;
         goto func;
        
      }
      //
      if(abs(xq-xk)==2*a && abs(yq-yk)==2*b){
        cout<<1<<endl;
         goto func;

      }
      if(abs(xq-xk)==2*b&& abs(yq-yk)==2*a){
        cout<<1<<endl;
         goto func;
        
      }
      cout<<0<<endl;
      func:
      ;

  



    }








    return 0;
}