class Solution {
public:
    inline int max(const int &a, const int &b) { return a > b ? a : b; }
    inline int min(const int &a, const int &b) { return a < b ? a : b; }
    int maxOperations(vector<int>& nums, int k) {
        vector<int>& d = nums;
        unordered_map<int, int> um;
        for (auto it = d.begin(); it != d.end(); it++) { um[*it]++; }
        int ans = 0;
        for (auto it = um.begin(); it != um.end(); it++) {
            int v = it->first, v2 = k - v;
            if (v == v2) {
                ans += um[v] / 2;
                um[v] = 0;
            } else if (um.find(v2) != um.end()) {
                ans += min(um[v], um[v2]);
                um[v2] = 0;
            }
        }
        return ans;
    }
};