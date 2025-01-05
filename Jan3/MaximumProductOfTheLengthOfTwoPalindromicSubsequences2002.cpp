class Solution {
public:
    bool pal(string &x)
    {
        if(x.size() == 0) return false;
        if(x.size() == 1) return true;

        int n;
        for(int i = 0; i < x.size()/2; i++)
        {
            n = x.size() - i - 1;
            if(x[n] != x[i]) return false;
        }

        return true;
    }

    void traverse(string &s, string &one, string &two, int i, int &result)
    {
        if(i == s.size())
        {
            if(pal(one) && pal(two)) result = max(result, (int)(one.size() * two.size()));

            return; 
        }

        //in ONE
        one.push_back(s[i]);
        traverse(s, one, two, i+1, result);
        one.pop_back();

        //in TWO
        two.push_back(s[i]);
        traverse(s, one, two, i+1, result);
        two.pop_back();

        //no BOTH
        traverse(s, one, two, i+1, result);

        return;
    }

    int maxProduct(string s) {
        int result = 0;
        string one = "", two = "";
        traverse(s, one, two, 0, result);

        return result;
    }
};