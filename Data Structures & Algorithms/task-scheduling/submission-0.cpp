class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char ch : tasks) {
            freq[ch]++;
        }

        priority_queue<int> maxheap;
        for (auto &it : freq) {
            maxheap.push(it.second); 
            
        }

        int time = 0;

        while (!maxheap.empty()) {
            vector<int> temp;

            int cycle = n + 1;
            int i = 0;

            while (i < cycle && !maxheap.empty()) {
                int cnt = maxheap.top();
                maxheap.pop();

                cnt--;

                if (cnt > 0) {
                    temp.push_back(cnt);
                }

                time++;

                i++;
            }

            for (auto it : temp) {
                maxheap.push(it);
            }

            if (maxheap.empty()) break;

            time += cycle - i;
        }

        return time;
    }
};
