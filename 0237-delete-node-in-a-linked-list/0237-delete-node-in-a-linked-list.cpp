/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      // we are not given the head of the ll 
      // we cant delet ir directly we can skip it 

      node->val=node->next->val;
      node->next=node->next->next;
        
    }
};