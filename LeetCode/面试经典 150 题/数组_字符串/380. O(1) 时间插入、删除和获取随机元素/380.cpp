#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (ma.find(val) != ma.end()) { return false; }
        d.push_back(val);
        ma[val] = d.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (ma.find(val) == ma.end()) { return false; }
        int idx = ma[val];
        d[idx] = d.back();
        ma[d[idx]] = idx;
        d.pop_back();
        ma.erase(val);
        return true;
    }
    
    int getRandom() {
        int r = rand() % d.size();
        return d[r];
    }
    
    vector<int> d;
    unordered_map<int, int> ma;
};

int main() {
    return 0;
}
