class Solution {
public:
    string getHint(string secret, string guess) {
        //store how many digits repeated in real and fake number
        //store in bull if both digits are same, not in map
        unordered_map<int, int> real;
        unordered_map<int, int> fake;
        int bull = 0, cow = 0, digits = secret.size();
        string result = "";

        for(int i = 0; i < digits; i++)
        {
            int index = digits - i - 1;
            int r = secret[index] - '0', f = guess[index] - '0';

            if(r == f) bull++;
            else
            {
                real[r]++;
                fake[f]++;
            }
        }

        //cow value will be sum of minimum value of both map camparing to each digit
        for(int i = 0; i < 10; i++)
        {
            cow += min(real[i], fake[i]);
        }

        //making result
        
        if(bull == 0) result.push_back('0');
        //reverse the number
        int rev = 0, store = bull;
        for(int i = 1; i <= store; i*= 10)
        {
            rev = rev*10 + bull % 10;
            bull /= 10;
        }
        bull = rev;
        //add in string
        for(int i = 1; i <= store; i*= 10)
        {
            int temp = bull % 10;
            result.push_back(temp + '0');

            bull /= 10;
        }

        result.push_back('A');

        if(cow == 0) result.push_back('0');
        rev = 0;
        store = cow;
        for(int i = 1; i <= store; i*= 10)
        {
            rev = rev*10 + cow % 10;
            cow /= 10;
        }
        cow = rev;
        //add in string
        for(int i = 1; i <= store; i*= 10)
        {
            int temp = cow % 10;
            result.push_back(temp + '0');

            cow /= 10;
        }
        result.push_back('B');

        return result;
    }
};