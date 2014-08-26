Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > re;
        permute(num,0,re);
        return re;
    }
    
    void permute(vector<int> &num, int index,vector<vector<int> > & re)
    {
        if(index+1 == num.size())
        {
            re.push_back(num);
        }
        
        for(int i = index;i<num.size();i++)
        {
            bool flag = true;             //防止其中有重复的元素；
            for(int j=index;j<i;j++)
            {
                if(num[j]==num[i])
                {
                    flag = false;
                    break;
                }
            }
            
            if(!flag) continue;          //如果有重复的元素不做处理；
            
            int temp = num[i];
            num[i] = num[index];
            num[index] = temp;
            permute(num,index+1,re);
            
            num[index] = num[i];
            num[i] = temp;
        }
    }
};
