Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.




class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> m;
        int maxLength = 1;
        
        map<int,int>::iterator mi;
        for(vector<int>::iterator vi = num.begin();vi!=num.end();vi++)
        {
            mi = m.find(*vi);
            
            if(mi!=m.end()) continue;
            
            int upper=*vi;
            int lower=*vi;
            
            mi = m.find(*vi+1);
            if(mi!=m.end())
                upper = mi->second;
            
            mi = m.find(*vi-1);
            if(mi!=m.end())
                lower = mi->second;
                
            
            m[*vi] = *vi;
            m[lower] = upper;
            m[upper] = lower;
 
            
            maxLength = (upper-lower+1)>maxLength?(upper-lower+1):maxLength;
        }
        
        return maxLength;
    }
};
