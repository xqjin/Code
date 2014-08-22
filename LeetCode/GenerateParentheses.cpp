class Solution {
public:

    //通过；
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        string s = "";
        get(0,0,n,s,re);
        return re;
    }
    
    void get(int ln,int rn,int n,string s,vector<string> & re)
    {
        if(ln==n && rn==n)
        {
            re.push_back(s);
            return;
        }
        
        if(ln<n)
        {
            get(ln+1,rn,n,s+"(",re);
        }
    
        if(rn<ln)
        {
            get(ln,rn+1,n,s+")",re);
        }
        
    }
};

/*

public List<String> generateParenthesis(int n) {
    ArrayList<String> list = new ArrayList<String>();
    Stack<String> stack = new Stack<String>();
    Stack<Integer> validationStack = new Stack<Integer>();
    stack.push("(");
    validationStack.push(0);
    while(stack.size() != 0)
    {
        String s = stack.pop();
        int v = validationStack.pop();
        if(s.length() == n * 2)
        {
            list.add(s);
            continue;
        }
        if(s.length() - v < n)
        {
            stack.push(s + "(");
            validationStack.push(v);
        }
        if(2 * v < s.length())
        {
            stack.push(s + ")");
            validationStack.push(v+1);
        }
    }
    return list;
}



*/


/*

这道题目非常好，因为我不会做；

初始的尝试错了，直接当成分桃的类似题目；造成结果漏；

这道题目存在递归和非递归算法；

非递归算法没看懂；


*/


/*
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        put(n,re);
        return re;
    }
    
    void put(int n,vector<string> & re)
    {
        for(int i=1;i<=n;i++)
        {   
            string temp = "";
            put_per(i,0,temp,n,re);
        }
    }
    
    void put_per(int m,int index,string temp ,int left,vector<string> & re)
    {
        if(m-1==index && left > 0) // success to produce the result
        {
            re.push_back(temp+getstr(left));
        }
        
        
        for(int i=1;i<left;i++)
        {   
            put_per(m,index+1,temp+getstr(i),left-i,re);
        }
        
    }
    
    string getstr(int num)
    {
        string s = "";

        string l = "";
        string r = "";
            
        for(int j=0;j<num;j++)
        {
            l += "(";
            r += ")";
            
        }
        s += l + r;
        return s;
    }
*/
