Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }



Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL


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
    
    //q1不空，q2为空，将q1队列中的元素，链接；并且将其子节点放进去q2中；
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
