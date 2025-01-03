class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int result = 0;
        bool check = true;
        int last = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                last = -1;
                check = true;
                for(int k = 0; k < nums.size(); k++)
                {
                    if(k >= i && k <= j) continue;
                    else
                    {
                        if(last >= nums[k])
                        {
                            check = false;
                            break;
                        }
                        last = nums[k];
                    }
                }
                
                //cout<<"i = "<<i<<", j = "<<j<<endl;
                if(check) result++;
            }
            
        }

        return result;
    }
};