lass Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        // Step 1: Count frequencies
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Create buckets (bucket[i] stores numbers appearing i times)
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        
        for (auto& pair : freqMap) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        // Step 3: Collect top k elements from the highest frequency buckets
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result; // Stop early
            }
        }

        return result;
    }
};
