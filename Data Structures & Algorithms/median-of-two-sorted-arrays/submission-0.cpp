class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int med1 = 0;
        int med2 = 0;
        int i = 0, j = 0;
        
        for (int cnt = 0; cnt < (m + n) /2 + 1; cnt++) {
            med2 = med1;

            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    med1 = nums1[i];
                    i++;
                }
                else {
                    med1 = nums2[j];
                    j++;
                }
            }

            else if(i < m) {
                med1 = nums1[i];
                i++;
            }
            else {
                med1 = nums2[j];
                j++;
            }
        }

        if ((m + n) % 2 == 0) {
            return (med1 + med2) / 2.0;
        }

        else {
            return double(med1);
        }
    }
};
