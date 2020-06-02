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

        for(i = 0;i<m;i++)     //all the numbers before m will be 0
            x[i] = int(0);
        for(i = m;i<=n;i++)    //all the numbers from m to n will be 1.
        {
            x[i] = int(1);
        }
        x[0] = x[1] = int(0);              // the index of bitset will denote the series of number 
        for(k = m; k<=n;k++) {             //numbers will be checked from m to n
            for (i = 2; i <= k/2; i++) {   // i will be one of the checker 
                if (x[k] == 1) {           // 1 denotes the number is prime
                    for (j = 2; i * j <= n; j++) {
                        if (i*j==k)        // if it becomes 0 then the number will be prime
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
