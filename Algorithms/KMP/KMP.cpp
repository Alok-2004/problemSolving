// KMP (Knuth-Morris-Pratt) algorithm

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(vector<int>& lps , string& p){
	int i = 0;
	int j = 1;
	int n = lps.size();
	while(j < n){
		if(p[i] == p[j]){
			lps[j] = i+1;
			i++;
		}else{
			if(i>0) i = lps[i-1]; // Backtracking to i-1
			else {
				lps[j] = 0;
				j++;
			}
		}
	}
	return;
}

int main(){
	string searchSpace = "vfkjvfbvfbknlvalvnvjnjv";
	string pattern = "bknl";
	
	vector<int>lps(pattern.size() , 0);
	solve(lps , pattern);
	
	// Now searching
	
	int i = 0;
	int j = 0;
	while(i < searchSpace.size()){
		if(searchSpace[i] == pattern[j]) {
            i++;
            j++;
        }
		
		if (j == pattern.size()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j-1];
        } else if (i < searchSpace.size() && searchSpace[i] != pattern[j]) { // Mismatch
            if (j > 0) {
                j = lps[j - 1];
            }else{
				i++;
			}
        }
		
	}
	
}
