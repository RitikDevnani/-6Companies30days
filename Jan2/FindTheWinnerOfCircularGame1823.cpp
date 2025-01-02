class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);

        for(int i = 0; i < friends.size(); i++)
        {
            friends[i] = i+1;
        }

        int i = 0;
        while(friends.size() != 1)
        {
            i+= k-1;
            if(i >= friends.size()) i %= friends.size();

            friends.erase(friends.begin() + i);
        }

        return friends[0];
    }
};