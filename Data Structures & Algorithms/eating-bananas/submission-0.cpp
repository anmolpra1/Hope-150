class Solution {
private:
 int calculate_hrs(vector<int>& piles, int speed) {
        int totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
    }  
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int maxVal = *max_element(piles.begin(), piles.end());
        int high = maxVal;

        int ans = maxVal;

        while (l <= high) {
            int mid = (l+high)/2;

            int totalh = calculate_hrs(piles, mid);

            if(totalh <= h) {
                ans = mid;
                high = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
