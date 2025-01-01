class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> result(img.size(), vector<int>(img[0].size()));
        int n, sum;
        
        for(int i = 0; i < img.size(); i++)
        {
            for(int j = 0; j < img[0].size(); j++)
           {
                //arrived on element img[x][y]

                sum = 0; //total sum of neighbour elements including yourself
                n = 0; //total number of neighbours including yourself
                for(int x = i - 1; x < i + 2; x++)
                {
                    for(int y = j - 1; y < j + 2; y++)
                    {
                        if(x >= 0 && x < img.size() && y >= 0 && y < img[0].size()) //checking if element exists or not
                        {
                            sum += img[x][y];
                            n++;
                        }
                    }
                }

                //new element value
                result[i][j] = floor(sum/n);
            }
        }

        return result;
    }
};