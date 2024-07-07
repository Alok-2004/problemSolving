#include<bits/stdc++.h>
using namespace std;

class ListNode{
  public:
  	int val;
  	ListNode* next;
  	
  	ListNode(int data){
  	  val = data;
	  next = nullptr;	
	}
};
/*
class Solution{
  public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      vector<int>res(2, -1);
      if(!head || !head->next || !head->next->next) return res;
        
      vector<int>idx;
      int sz = 1;
      
      ListNode* prev = head;
      ListNode* curr = prev->next;
      ListNode* nt = curr->next;
      
      while(prev && curr && nt){
      	if( (curr->val > prev->val && curr->val > nt->val) || (curr->val < prev->val && curr->val < nt->val)){
		  idx.push_back(sz);
		}
		prev = curr;
		curr = nt;
		nt = nt->next;
		sz++; 
	  }
	  
	  if(idx.size() > 1){
	    res[1] = idx[idx.size() - 1] - idx[0]; // Max distance
	    int mn = INT_MAX;
	    for(int i = 1; i<idx.size(); i++){
	  	  mn = min(mn, ( idx[i] - idx[i - 1]));
	    }
	    res[0] = mn; // Min distance
	  }
	  return res;
    }
};
*/


// bit optimized
class Solution{
  public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      vector<int>res(2, -1);
      if(!head || !head->next || !head->next->next) return res;
      
      int firstCritical = -1;
      int lastCritical = -1;
      int mn = INT_MAX; // minimum difference between citical points 

      ListNode* prev = head;
      ListNode* curr = prev->next;
      ListNode* nt = curr->next;
      int sz = 1; //position of curr node
      
      while(prev && curr && nt){
      	if( (curr->val > prev->val && curr->val > nt->val) || (curr->val < prev->val && curr->val < nt->val)){
		  if(firstCritical == -1)  firstCritical = sz;
          else  mn = min(mn, sz - lastCritical);
          lastCritical = sz;
        }
		prev = curr;
		curr = nt;
		nt = nt->next;
		sz++; 
	  }
	  
	  if(firstCritical != -1 && firstCritical != lastCritical){
        res[0] = mn;
        res[1] = lastCritical - firstCritical;
      }
	  return res;
    }
};
