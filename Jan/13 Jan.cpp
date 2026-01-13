class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;

        for (auto &sq : squares) {
            double l = sq[2];
            totalArea += l * l;
        }
        double target = totalArea / 2.0;
        double low = 1e9, high = -1e9;

        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            low = min(low, y);       
            high = max(high, y + l); 
        }
        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;
              for (auto &sq : squares) {
                double y0 = sq[1];
                double l = sq[2];
                if (mid <= y0) {
                    continue;
                }
                else if (mid >= y0 + l) {
                    areaBelow += l * l;
                }
                else {
                    areaBelow += l * (mid - y0);
                }
            }
            if (areaBelow < target) {
                low = mid;   
            } else {
                high = mid;  
            }
        }

        return low;
    }
};