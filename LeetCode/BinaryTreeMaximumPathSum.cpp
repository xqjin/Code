Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.



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
    int maxPathSum(TreeNode *root) {
        int value = 0;
        return maxPath_Sum(root,&value);
    }
    
    
    //函数的返回值记录着最大的路径，root代表这跟节点，value代表着从根开始的最长路径；
    int maxPath_Sum(TreeNode *root,int * value)
    {
        if(root==NULL) 
        {
            *value = INT_MIN;
            return INT_MIN;
        }
        
        int l=0,r=0,rl=0,rr=0;
        
        rl = maxPath_Sum(root->left,&l);
        rr = maxPath_Sum(root->right,&r);
        
        int temp = l>r?l:r;
        
        if(temp>0)
            *value = temp + root->val;
        else
            *value = root->val;
            
        
        int re = root->val;  //initial to the root value;
        
        
        //最长的路径：跟节点（如果跟节点左孩子的路径大于零或者右孩子开始的路径大于零，可能会加上路径值）   左子树中最长的路径  右子树中最长的路径
        
        if(l>0) 
            re += l;
        
        if(r>0)
            re += r;
        
        if(re<rl)
            re = rl;
        
        if(re<rr)
            re = rr;
            
        return re;
    }
};
