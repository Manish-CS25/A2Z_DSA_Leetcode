class NumberContainers {
public:
    map<int, int> mp;

    map<int, set<int>> num_map;
    NumberContainers() {}

    void change(int index, int number) {
        if (mp.find(index) != mp.end()) {

            int oldNum = mp[index];

            num_map[oldNum].erase(index);
            if (num_map[oldNum].empty())
                num_map.erase(oldNum);
        }

        mp[index] = number;
        num_map[number].insert(index);
    }

    int find(int number) {

        int ans = -1;
        if (num_map.empty())
            return ans;
        if (num_map.find(number) != num_map.end())
            return *num_map[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */