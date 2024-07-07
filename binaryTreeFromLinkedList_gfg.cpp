//Binary tree from linked list
class Solution {
  public:
    void convert(Node *head, TreeNode *&root) {
        if(head == nullptr){ 
            root = nullptr;
            return;
        }
        root = new TreeNode(head->data);
        Node* temp = head->next;
        queue<TreeNode*> q;
        q.push(root);
        
        while(temp){
            TreeNode* curr = q.front();
            q.pop();
            
            if(temp){
                curr->left = new TreeNode(temp->data);
                q.push(curr->left);
            }
            temp = temp->next;
            if(temp){
                curr->right = new TreeNode(temp->data);
                q.push(curr->right);
            }
            temp = temp ? temp->next : nullptr;  // take care of this point first check whether temp in null of not if not then only point to next node
// or this            if(temp)  temp = temp->next;
//            else temp
        }
    }
};
