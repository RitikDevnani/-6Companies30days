//IMPORTANT
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        //we need to calculate median, so that least value get added/subtracted
        //cout<<nums.size()/2<<endl;
        int avg = nums[nums.size()/2];
        if(nums.size() % 2 == 0)
        {
            avg += nums[nums.size()/2 - 1];
            avg /= 2;
        }

        //cout<<avg;
        int result = 0;
        for(auto i : nums)
        {
            result += abs(avg - i);
        }

        return result;
    }
};