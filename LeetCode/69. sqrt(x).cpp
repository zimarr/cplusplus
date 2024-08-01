class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        int mid = lo + (hi - lo) / 2;

        while (lo <= hi) {
            if (long(mid) * mid == x) {
                return mid;
            } else if (long(mid) * mid < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }

            mid = lo + (hi - lo) / 2;
        }

        return hi;
    }
};
