class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> goodIdx;

        for (auto &triplet : triplets) {

            if (triplet[0] > target[0] ||
                triplet[1] > target[1] ||
                triplet[2] > target[2])
                continue;

            for (int i = 0; i < 3; i++) {
                if (triplet[i] == target[i])
                    goodIdx.insert(i);
            }
        }

        return goodIdx.size() == 3;
    }
};