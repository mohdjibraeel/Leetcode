class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        // Count how many times each digit appears
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Hundreds digit: 1-9 (cannot be 0)
        for (int h = 1; h <= 9; h++) {
            if (freq[h] == 0) continue;

            freq[h]--;

            // Tens digit: 0-9
            for (int t = 0; t <= 9; t++) {
                if (freq[t] == 0) continue;

                freq[t]--;

                // Ones digit must be even
                for (int o = 0; o <= 8; o += 2) {
                    if (freq[o] > 0) {
                        ans++;
                    }
                }

                freq[t]++;
            }

            freq[h]++;
        }

        return ans;
    }
};