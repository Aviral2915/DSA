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
        ListNode*merge(ListNode* l1, ListNode* l2){
            if(!l1) return l2;
            if(!l2) return l1;

            if(l1->val<l2->val){
                l1->next=merge(l1->next,l2);
                return l1;
            }
            else{
                 l2->next = merge(l1, l2->next);
                return l2;
            }
        }

        ListNode* getMiddle(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head->next; // start fast one step ahead

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode*mid=getMiddle(head);
    ListNode*secondhalf= mid->next;
    mid->next=nullptr;

     ListNode* left = sortList(head);
    ListNode* right = sortList(secondhalf);

    return merge(left, right);
}

        
    
};