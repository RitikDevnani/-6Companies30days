class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //considered circle center as origin

        //this loop running inside rectangle because what if circle is inside the rectangle. 
        for(int i = x1 - xCenter; i <= x2 - xCenter; i++)
        {
            if(i <= radius && i >= -(radius))
            {
                for(int j = y1 - yCenter; j <= y2 - yCenter; j++)
                {
                    if((i*i)+(j*j) <= (radius * radius)) return true;
                }
            }
        }

        return false;
    }
};