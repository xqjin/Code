The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.




class Solution {
public:


    //必须通过发现规律来解决此类问题；
    /*
    n=1         n=2       n=3
    0           00        000
    1           01        001
                11        011
                10        010  在n-1的基础上，直接在前面加0
                          
                          110  将第一位变为1，然后采用前半部分的你过程，如此正好满足gray码的要求；   
                          111
                          101
                          100
    
    统计数字的大小：只需要在前面加上一个值就OK；

    */
    vector<int> grayCode(int n) {
            
        vector<int> re;

        re.push_back(0);

        for(int i=1;i<=n;i++)
        {
            int size = re.size()-1;
            
            int add = 1 << (i-1);
            while(size>=0)
            {
                re.push_back(re[size]+add);
                size--;
            }
        }
        
        return re;
        
        
    }
};
