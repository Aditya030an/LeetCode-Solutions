class Solution {
public:
    double areaBelow(double mid, vector<vector<int>>& squares) {
        double area = 0;
        int n = squares.size();
        for (int i = 0; i < n; i++) {
            double y = squares[i][1], len = squares[i][2];
            if (mid >= y + len) {
                area += len * len;
            } else if (mid > y && mid < y + len) {
                area += len * (mid - y);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double miny = INT_MAX, maxy = INT_MIN;
        double totalArea = 0, y = 0;

        for (int i = 0; i < n; i++) {
            double len = squares[i][2]; 
            totalArea += len * len;

            if (miny > squares[i][1])
                miny = squares[i][1];

            if (maxy < squares[i][1] + len)
                maxy = squares[i][1] + len;
        }

        double target = totalArea / 2;
        double l = miny, h = maxy;

        while (h - l > 1e-5) {

            double mid = (l + h) / 2;

            if (areaBelow(mid, squares) < target) {
                l = mid;
            } else {
                y = mid;
                h = mid;
            }
        }

        return y;
    }
};