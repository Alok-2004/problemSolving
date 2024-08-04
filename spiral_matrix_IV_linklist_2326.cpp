#include<iostream>
#include<vector>

using namespace std;

// Assuming ListNode is defined as follows
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>> arr(m, vector<int>(n, -1)); // Initialize all cells to -1
        int minr = 0;
        int maxr = m - 1;
        int minc = 0;
        int maxc = n - 1;
        ListNode* temp = head;
        
        while (minr <= maxr && minc <= maxc && temp != nullptr) {
            // Right
            for (int j = minc; j <= maxc && temp != nullptr; j++) {
                arr[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++;
            
            if(minr > maxr || minc > maxc)  break;
            // Down
            for (int i = minr; i <= maxr && temp != nullptr; i++) {
                arr[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;
            
            // Left
            if (minr <= maxr && temp != nullptr) {
                for (int j = maxc; j >= minc; j--) {
                    arr[maxr][j] = temp->val;
                    temp = temp->next;
                }
                maxr--;
            }
            
            // Up
            if (minc <= maxc && temp != nullptr) {
                for (int i = maxr; i >= minr; i--) {
                    arr[i][minc] = temp->val;
                    temp = temp->next;
                }
                minc++;
            }
        }
        
        return arr;
    }
};

int main(){
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    vector<vector<int>> result = sol.spiralMatrix(2, 2, head);

    // Display the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

