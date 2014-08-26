Sort a linked list in O(n log n) time using constant space complexity.


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
    ListNode *sortList(ListNode *head) {
        int l = len(head);
        return sortList(head,l);
    }
    
    
    ListNode *sortList(ListNode *head,int len)
    {
        if(len<=1||!head) return head;
        
        ListNode * mid = head;
        ListNode * pre = NULL;
        int n = len/2;
        while(n--)
        {
            pre = mid;
            mid = mid->next;
        } 
        pre->next = NULL;  //将链表分成两部分，因为接下来的操作依赖于指针的末尾为空这个判断；
        
        
        ListNode * left = sortList(head,len/2);
        ListNode * right = sortList(mid,len-len/2);
        
        ListNode * re = merge(left,right);
        return re;
    }
    
    
    ListNode * merge(ListNode * left, ListNode * right)
    {
        ListNode * re = NULL;
        
        ListNode * tail = NULL;
        while(left && right)
        {
            if(left->val<right->val)
            {
                
                if(re==NULL)
                {
                    re = left;
                    tail = re;
                }
                else
                {
                    tail->next = left;
                    tail = tail->next;
                }
                left = left->next;
            }
            else
            {
                
                if(re==NULL)
                {
                    re = right;
                    tail = re;
                }
                else
                {
                    tail->next = right;
                    tail = tail->next;
                }
                right = right->next;
                
            }
        }
        
        if(tail)
            tail->next = left==NULL ? right:left;
        
        return re;
    }


    int len(ListNode * head)
    {
        int l = 0;
        while(head)
        {
            l++;
            head = head->next;
        }
        return l;
    }
};
