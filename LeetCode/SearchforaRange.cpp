Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].




class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> re;
        
        int low = findpre(A,n,target);
        int high = findpost(A,n,target);
        
        re.push_back(low);
        re.push_back(high);
        
        return re;
    }
    
    int findpre(int A[],int n,int target)
    {
        int low = 0;
        int high = n-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(A[mid]==target)
            {
                if(mid==low)
                    return mid;
                else
                {
                    if(A[mid-1]<target)
                        return mid;
                    else
                        high = mid - 1;
                }
            }
            else if(A[mid]>target)
            {
                
                high = mid - 1;
            }
            else
            {
                
                low = mid + 1;
            }
        }
        
        return -1;
    
    }
    
    
    int findpost(int A[],int n,int target)
    {
        int low = 0;
        int high = n-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(A[mid]==target)
            {
                if(mid==high)
                    return mid;
                else
                {
                    if(A[mid+1]>target)
                        return mid;
                    else
                        low = mid + 1;
                }
            }
            else if(A[mid]>target)
            {
                
                high = mid - 1;
            }
            else
            {
                
                low = mid + 1;
            }
        }
        
        return -1;
    
    }
};
