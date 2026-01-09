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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dum=new ListNode(-1);
        ListNode* cur=dum;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1!=NULL){
            cur->next=l1;
        }
        else{
            cur->next=l2;
        }
        return dum->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left,right);
    }
};