#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=-1;
        for(long long x=2;x<=50;x++){
            for(int i=0;i<n;i++){
                if(gcd(a[i],x)==1){
                    ans=x;
                    break;
                }
            }
            if(ans!=-1){
                break;
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}