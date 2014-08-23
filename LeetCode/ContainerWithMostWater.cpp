Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.


class Solution {
public:
    int maxArea(vector<int> &height) {
        
        int high = height.size()-1;
        int low = 0;
        
        int max = 0;
        
        while(low<high)
        {
            int area = (high-low)*(height[low]<height[high]?height[low]:height[high]);
            
            max = max>area?max:area;
            
            if(height[low]<height[high])
                low++;
            else
                high--;
            
        }
        return max;
    }
};


/*

证明：

Here is the proof. Proved by contradiction:

Suppose the returned result is not the optimal solution. Then there must exist an optimal solution, say a container with aol and aor (left and right respectively), such that it has a greater volume than the one we got. Since our algorithm stops only if the two pointers meet. So, we must have visited one of them but not the other. WLOG, let's say we visited aol but not aor. When a pointer stops at a_ol, it won't move until

The other pointer also points to aol. In this case, iteration ends. But the other pointer must have visited aor on its way from right end to aol. Contradiction to our assumption that we didn't visit aor.

The other pointer arrives at a value, say arr, that is greater than aol before it reaches aor. In this case, we does move aol. But notice that the volume of aol and arr is already greater than aol and aor (as it is wider and heigher), which means that aol and aor is not the optimal solution -- Contradiction!

Both cases arrive at a contradiction.


简化版本：

无论如何low and high 在最高点相遇，无论最高点在实际最优值的左边，右边都不可能将最优值漏掉；

如果最高点在中间的话，那么当其中一个在边界的时候，另一个在外面，那么必定是边界上的值先移动，否则不会漏过最优值；

如果边界上的值先移动，那么那么存在另一个最大值，矛盾；

*/
