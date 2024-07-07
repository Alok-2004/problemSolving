#include<iostream>
#include<string>
#include<vector>

using namespace std;

void creatingWords(string &s1, string &s2){
	
	char ch1 = s1[0];
	char ch2 = s2[0];
	s1[0] = ch2;
	s2[0] = ch1;
	
	return;
}

int main(){
	int n; // number of words
	cin>>n;
	cin.ignore();
	
	vector<string> values;
	string s1, s2;
		
	for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        values.push_back(s1);
        values.push_back(s2);
    }
	
	for(int i = 0; i < n * 2; i += 2){
		creatingWords(values[i], values[i+1]);
	}
	
	// printing
	for(int i = 0; i < n * 2; i += 2){
		cout<<values[i]<<" "<< values[i + 1]<<endl;
	}
	return 0;
}
