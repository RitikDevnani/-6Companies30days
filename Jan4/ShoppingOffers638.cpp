//IMPORTANT
class Solution {
public:
    int total(map<int, map<vector<int>, int>> &dp, vector<int> used, vector<int> &price, 
              vector<vector<int>> &special, vector<int> &needs, int i)
    {
        if(i == special.size())
        {
            int cost = 0;
            for(int j = 0; j < price.size(); j++)
            {
                cost += price[j]*(needs[j] - used[j]);
            }
            return cost;
        }

        if(dp.find(i) != dp.end() && dp[i].find(used) != dp[i].end()) return dp[i][used];

        //don't claim special offer
        int claimno = total(dp, used, price, special, needs, i+1);

        //claim special offer
        bool can_use = true;
        vector<int> new_used = used;
        for(int j = 0; j < needs.size(); j++)
        {
            new_used[j] += special[i][j];
            if(new_used[j] > needs[j])
            {
                can_use = false;
                break;
            }
        }
        
        int claimyes = INT_MAX;
        if(can_use)
        {
            claimyes = special[i][needs.size()] + 
                      total(dp, new_used, price, special, needs, i);
        }

        return dp[i][used] = min(claimyes, claimno);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<int, map<vector<int>, int>> dp;
        vector<int> used(needs.size(), 0);
        return total(dp, used, price, special, needs, 0);
    }
};