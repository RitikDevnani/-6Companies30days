//IMPORTANT
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        int odd = 0;
        int count = 0;
        int j = 0;

        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] % 2 == 1)
            {
                odd++;

                if(odd >= k)
                {
                    count = 1;
                    while(nums[j] % 2 == 0)
                    {
                        count++;
                        j++;
                    }
                    j++;
                    
                    result += count;
                }
            }
            else if(odd >= k) result += count;
        }

        return result;
    }
};