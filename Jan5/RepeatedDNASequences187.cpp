//VERY IMPORTANT
class Solution {
public:
    int str2int(string s)
    {
        int str=0;
        for (int i = 0; i < s.size(); ++i)
            str = (str << 3) +(s[i] & 7);
        return str;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> seq;
        unordered_map<int,int> letter;
        for (int i = 0; i + 10 <= s.size(); i++)
            if (letter[str2int(s.substr(i,10))]++ == 1)
                seq.push_back(s.substr(i,10));
        return seq;
    }
};