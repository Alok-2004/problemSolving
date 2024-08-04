#include<iostream>

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // find the length
		ListNode *temp = head;
		int n = 0;
		while(temp){
			temp = temp->next;
			n++;
		}
		
		temp = head;
		
		vector<ListNode*>ans;
        int size = n / k;
        int remaining = n % k;
        while(temp){
        	ListNode* c = new ListNode(100);
        	ListNode* tempc = c;
        	int s = size;
        	if(remaining > 0) {
                s++;
                remaining--;
            }
        	for(int i = 1; i<=s; i++){
        		tempc->next = temp;
        		temp = temp->next;
        		tempc = tempc->next;
			}
			tempc->next = NULL;
			ans.push_back(c->next);
		}
		
		if(ans.size() < k){
			int extra = k - ans.size();
			for(int i = 0; i<extra; i++){
				ans.push_back(NULL);
			}
		}
		return ans;
    }
};


int main(){
	
}
