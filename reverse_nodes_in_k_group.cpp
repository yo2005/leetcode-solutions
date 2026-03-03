/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        ListNode* temp=head;
        for(int i=1;i<=k;i++){
            if(!temp){
                return head;
            }
            temp=temp->next;
        }
        ListNode* prev=NULL;
        temp=head;
        for(int i=1;i<=k;i++){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        head->next=reverseKGroup(temp,k);
        return prev;

        
    }
};
