class Solution {
public:
    bool canMake(vector<int>& buckets, double target, int loss) {
        double surplus = 0.0;
        double deficit = 0.0;

        double efficiency = (100.0 - loss) / 100.0;

        for (int water : buckets) {
            if (water > target) {
                surplus += (water - target) * efficiency;
            } else {
                deficit += (target - water);
            }
        }

        return surplus >= deficit;
    }

    double equalizeWater(vector<int>& buckets, int loss) {
        double low = 0.0;
        double high = *max_element(buckets.begin(), buckets.end());

        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;

            if (canMake(buckets, mid, loss))
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
