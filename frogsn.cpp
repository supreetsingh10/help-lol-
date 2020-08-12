//Trying to apply divide and conquer approach. What I have done is very similar to merge sort. 
//CODECHEF QUESTION      ***********************      https://www.codechef.com/problems/FROGV      *************************************
// I am trying to isolate the coordinates of the frog so that and check for the individual next to them and combine the answer. 
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
bool div(int64_t [],int64_t ,int64_t);
bool conq(int64_t [], int64_t, int64_t, int64_t, int64_t);
bool checks(int64_t [], int64_t, int64_t);
int64_t n, k, p, last;
int main(){
    int64_t frogs[100001];
    bool flag; 
    cin>>n>>k>>p;
    for(int i = 0; i<n; i++){
        cin>>frogs[i];
    }
    sort(frogs, frogs+n);       // Sorting the frogs on the basis of their value I input in the array frogs[] array. 
    int64_t s = 0;
    last = n-1;
    while(p--){
    int64_t a, b; cin>>a>>b;
    s = a; last = b; 
    flag = div(frogs,s,last);
    if (flag == true){
        cout<<"Yes"<<endl;
        }
    else{
        cout<<"No"<<endl;
        }
    }
    return 0; 
}
bool div(int64_t f[], int64_t first, int64_t last){
    int64_t mid;
    bool flag;
    if(first<last){                     //Recursive function as long as only first and last are same. 
        mid = first + (last-first)/2;
        div(f, first, mid);
        cout<<"Phase 1: "<<f[first]<<" "<<f[mid]<<endl;
        div(f, mid+1, last);            
        cout<<"Phase 2: "<<f[first]<<" "<<f[mid]<<endl;
        flag = conq(f, first,mid, mid+1, last); //
    } 
    return flag;  
}
bool conq(int64_t f[],int64_t fb, int64_t fl, int64_t lb, int64_t ll){
    int64_t na, nb, nc, k; 
    bool flag = true;
    na = fb;                                            // I believe error lies in this code. I don't understand what it is 
    nb = lb; 
    nc = fb; 
    while((na<=fl)&&(nb<=ll)){
       flag = checks(f,na, nb);
       if (flag == false){
            break; 
       } 
       na++, nb++;
    } 
    return flag;
}
bool checks(int64_t f[], int64_t c1, int64_t c2){
    if((c2-c1)<=k){
        cout<<f[c2]<<" "<<f[c1]<<endl;                          
        return true;                                    // I want to check for individual frogs here. This program is running but it is wrong. 
    }else{
        return false;
    }
}
