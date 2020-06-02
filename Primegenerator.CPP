#include<iostream>
#include<bitset>
#include<algorithm>
#define ull unsigned long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        bitset<1000000000> x;
        ull int m,n,i,j,k;
        cin>>m>>n;

        for(i = 0;i<m;i++)
            x[i] = int(0);
        for(i = m;i<=n;i++){
            x[i] = int(1);
        }
        x[0] = x[1] = int(0);
        for(k = m; k<=n;k++) {
            for (i = 2; i <= n/2; i++) {
                if (x[k] == 1) {
                    for (j = 2; i * j <= n; j++) {
                        if (i*j==k)
                            x[i*j]=int(0);
                    }
                }
            }
        }
        for(i = m;i<=n;i++){
            if(x[i]==1)
                cout<<i<<endl;
        }
    }
    return 0;
}
