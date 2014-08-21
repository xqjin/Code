Flatten Binary Tree to Linked List


Given a binary tree, flatten it to a linked list in-place.

For example,Given

         1
        / \
       2   5
      / \   \
     3   4   6


The flattened tree should look like:
   
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6


Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode*> parent;
        parent.push(NULL);
        
        TreeNode * top = root;
        TreeNode * tail = root;
        while(top!=NULL)
        {
            if(top!=tail)
            {
                tail->left = NULL;    
                tail->right = top;
                tail = top;
            }
            
            if(top->right)
                parent.push(top->right);
            
            if(top->left)
                parent.push(top->left);
                
            top = parent.top();
            parent.pop();
        }
    }
};
