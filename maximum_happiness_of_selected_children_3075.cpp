#include<iostream>
#include<vector>
#include<algorithm>

long long maximumHappinessSum(std::vector<int>& happiness, int k) {
    std::sort(happiness.begin(),happiness.end(), std::greater<int>());
    long long ans = 0;
    int idx = 0;
    while(idx < happiness.size() && k > 0){  
        ans += std::max(happiness[idx] - idx, 0);
        k--;
        idx++;
    }
    return ans;
}

int main(){
	std::vector<int> happiness = {2, 3, 4, 5, 6, 7};
	int k;
	std::cin>>k;
	long long ans = maximumHappinessSum(happiness, k);
	std::cout<<ans;
	return 0;
}
