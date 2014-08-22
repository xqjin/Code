Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].


//相比移除排序数组的第一个版本而言，只需要设置一个标志即可；

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2)
            return n;
        
        int tail = 0;
        int cur = 1;
        bool flag = false;
        for(;cur<n;cur++)
        {
            if(!flag && A[cur]==A[tail])
            {
                flag = true;
                tail++;
                A[tail] = A[cur];
            }
            
            if(A[cur]!=A[tail])
            {
                flag = false;
                tail ++;
                A[tail] = A[cur];
            }
        }
        return tail+1;
    }
};
