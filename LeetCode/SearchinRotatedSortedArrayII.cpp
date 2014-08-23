Follow up for "Search in Rotated Sorted Array":

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.


class Solution {
public:
    bool search(int A[], int n, int target) {
        int index = false;
        
        int high = n-1;
        int low = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(A[mid]==target)
            {
                index = true;
                break;
            }
            
            
            if(A[low]==A[high] && A[low]==A[mid])
            {
                for(int i=low;i<=high;i++)
                {
                    if(A[i]==target)
                    {
                        index = true;
                        break;
                    }
                }
            }
            
            
            if(A[mid]<target)
            {
                if(A[mid]>=A[low])
                {
                    low = mid+1;
                }
                else
                {
                    if(target<=A[high])
                    {
                        low = mid+1;
                    }
                    else
                    {
                        high = mid-1;
                    }
                }
                
            }
            
            if(A[mid]>target)  //  mid > target
            {
                if(A[mid]>=A[low])
                {
                    if(target>=A[low])
                    {
                        high = mid -1;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
                else
                {
                    high = mid-1;
                }
            }
        }
        
        return index;
    }
};
