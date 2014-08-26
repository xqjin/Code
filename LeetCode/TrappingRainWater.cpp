Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

class Solution {
public:
    int trap(int A[], int n) {
        
        int index = 0;
        int sum = 0;
        while(index<n-1)
        {
            int high = index+1;
            while(A[high]<A[index] && high<n) high++;   //注意这里的判断条件是小于；
            
            if(high==n) break;
            
            int temp = A[index];
            for(;index<high;index++)
                sum += temp-A[index];
        }
        
        index = n-1;
        while(index>0)
        {
            int low = index -1;
            while(A[low]<=A[index] && low >=0) low--;  //注意这里的判断条件是：小于等于；  两个判断条件不同，为了防止相等的两个竹子计算两遍；   
            
            if(low<0) break;
            
            int temp = A[index];
            for(;index>low;index--)
                sum += temp - A[index];
        }
        
        return sum;
    }
};
