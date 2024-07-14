class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == nullptr) return nullptr;
        unordered_set<int>us;
        for(auto ele : nums){
            us.insert(ele);
        }

        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = dummy->next;
        while(prev && curr){
            if(us.find(curr->val) != us.end()){
                curr = curr->next;
                prev->next = curr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        } 
        return dummy->next;
    }
};
