class Solution {
public:

    int solve(string &s,int points,char first,char second)
    {
        stack<char>st;
        int count=0;

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && st.top()==first && s[i]==second)
            {
                count+=points;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string s1="";

        while(!st.empty())
        {
            s1+=st.top();
            st.pop();
        }
        reverse(s1.begin(),s1.end());
        s=s1;

        cout<<s<<" ";

        return count;
    }

    int maximumGain(string s, int x, int y) {
        int result=0;
        if(x>y)
        {
            result+=solve(s,x,'a','b');
            result+=solve(s,y,'b','a');
        }
        else if(y>x)
        {
            result+=solve(s,y,'b','a');
            result+=solve(s,x,'a','b');
        }

        return result;
    }
};