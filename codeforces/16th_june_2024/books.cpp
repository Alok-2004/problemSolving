#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> pages(n);
        for (int i = 0; i < n; ++i) {
            cin >> pages[i];
        }
        int x = pages[n-1];
        int sum = pages[n-1];

        sort(pages.begin(), pages.end());

        if(pages[n-1] != x){
            sum += pages[n-1];
        }else{
            sum+=pages[n-1];
        }
        cout << sum << endl;
    }
    
    return 0;
}
