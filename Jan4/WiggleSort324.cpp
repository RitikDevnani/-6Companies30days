class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() % 2 == 0 ? nums.size() / 2 - 1 : nums.size() / 2;
        cout<<mid;
        
        vector<int> temp(nums.size());

        for(int i = 0; i <= nums.size() / 2; i++)
            if(i*2 != nums.size()) temp[i*2] = nums[mid - i]; 
        for(int i = 1; i <= nums.size() / 2; i++)
            temp[i*2 - 1] = nums[nums.size() - i];

        for(int i = 0; i < temp.size(); i++)
            nums[i] = temp[i];
    }
};