Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.


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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        if(!head)
            return NULL;
        
        ListNode * p = head;
        ListNode * q = head;
        
        for(int i=0;i<n;i++)  // q first move n step before p;
        {
            if(q)
                q = q->next;
            else
                return NULL;
        }
        
        if(!q)  // remove the head node;
        {
            ListNode * head= p->next;
            delete p;
            return head;
        }
        
        while(q->next)
        {
            q = q->next;
            p = p->next;
        }
        
        ListNode * temp = p->next;
        p->next = temp->next;
        delete temp;
        
        return head;
        
    }
};
