#include<iostream>
#include<string>
#include<climits>
#include<vector>

using namespace std;
// Y ka suffix sum and N ka prefix sum ka sum
int bestClosingTime(string customers){
    int n = customers.length();
    int pre[n+1];// number of N before kth hour
    int suf[n+1];// number of y after and including kth hour
    pre[0] = 0;
    for(int i = 1; i<=n; i++){
        if(customers[i - 1] == 'N')  pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1];
    }

    cout<<"Prefix sum: "<<endl;
    for (size_t i = 0; i <= n; i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    

    suf[n] = 0;
    for(int i = n-1; i>=0; i--){
        if(customers[i] == 'Y')  suf[i] = suf[i+1] + 1;
        else  suf[i] = suf[i+1]; 
    }

    cout<<"suffix sum: "<<endl;
    for (size_t i = 0; i <= n; i++)
    {
        cout<<suf[i]<<" ";
    }
    cout<<endl;

    

    int mini = INT_MAX;
    int j = -1;
    for(int i = 0; i<=n; i++){
        int x = suf[i] + pre[i];
        if(mini > x){
            swap(mini, x);
            j = i;
        }
    }

    return j;
}

int main(){
    string str = "YYNY";
    cout<<bestClosingTime(str);
}