Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.




class Solution {
public:
    int search(int A[], int n, int target) {
        int index = -1;
        
        int high = n-1;
        int low = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(A[mid]==target)
            {
                index = mid;
                break;
            }
            else if(A[mid]<target)
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
            else  //  mid > target
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
