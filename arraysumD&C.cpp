#include<iostream>
void add(int [], int [], int, int);
int operation(int, int);
void combine(int [], int [], int, int, int, int);
using namespace std;
int main(){
    int x[10], y[10];
    int i, size = 10;
    for(i= 0;i<10;i++){
        cin>>x[i];
    }
    for(i= 0;i<10;i++){
        cin>>y[i];
    }
    add(x,y, 0, size-1);
    return 0;
}

void add(int x[], int y[], int start, int end){
    int mid;
    if(start<end){
        mid = start + (end-start)/2;
        add(x, y,start, mid);
        add(x,y,mid+1, end);
        combine(x, y, start, mid, mid+1, end);
    }
}

void combine(int x[], int y[], int start, int end1, int start2, int end2)
{
    bool flag1 = false, flag2 = false;
    int sum[10], ans, ans2;
    if(start<=end1){
        ans = operation(x[start], y[start]);
        sum[start] = ans;
        start++; //start is getting incremented
        combine(x,y,start, end1, start2, end2); //recursion. I think error is coming because of this part.
        if(start==end1)
            flag1 = true;
    }
    if(start2<=end2){
        ans2 = operation(x[start2], y[start2]);
        sum[start2] = ans2;
        start2++;
        combine(x,y,start, end1, start2, end2); //recursion again.
        if(start2 == end2)
            flag2 = true;
    }
    if(!flag1 && !flag2) //when both the function has went through all the elements, this will turn true and this part will be executed.
    {
        for (int i : sum) {
            cout<<i;
        }
    }
}

int operation(int a, int b){ //operation that will add isolated elements
    return a+b;
}
