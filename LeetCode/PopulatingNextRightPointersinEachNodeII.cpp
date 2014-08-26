Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL




/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        queue<TreeLinkNode*> q1,q2;
        
        if(root==NULL)
            return;
            
        q1.push(root);
        
        while(!q1.empty() || !q2.empty())
        {
            if(!q1.empty() && q2.empty())
                connectQueue(q1,q2);
                
            if(q1.empty() && !q2.empty())
                connectQueue(q2,q1);
        }
    }
    
    void connectQueue(queue<TreeLinkNode *> & q1,queue<TreeLinkNode *> & q2)
    {
        TreeLinkNode * pre=NULL;
        TreeLinkNode * cur=NULL;
        
        while(!q1.empty())
        {
            cur = q1.front();
            q1.pop();
            
            if(cur->left)
                q2.push(cur->left);
            if(cur->right)
                q2.push(cur->right);
            
            
            if(pre!=NULL)
            {
                pre->next = cur;
            }
            
            pre = cur;
        }
    }
};
