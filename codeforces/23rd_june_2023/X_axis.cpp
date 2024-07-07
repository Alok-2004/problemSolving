#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

int axis(vector<int> arr){
    int sum = arr[0] + arr[1] + arr[2];

    int sub = INT_MAX;
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());

    for(int i = mn; i <= mx; i++){
        int f= abs(arr[0] - i) + abs(arr[2] - i) + abs(arr[1] - i);
        sub = min(f, sub);
    }
    
    return sub;
}

int main(){
    int n; 
    cin>>n;

    vector<int>ans(n);
    vector<int>temp(3, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin>>temp[j];
        }
        int a = axis(temp);
        ans[i] = a;
    }

    for(auto& i: ans)  cout<<i<<endl;

}