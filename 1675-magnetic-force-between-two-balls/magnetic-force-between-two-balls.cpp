class Solution {
public:
    bool check(int x, vector<int>& position, int m) {
        int b_placed = 1;
        int last_pos = position[0];

        for (int i = 0; i < position.size(); i++) {
            if (position[i] - last_pos >= x) {
                if (++b_placed == m) {
                    return true;
                }
                last_pos = position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());
        cout << position[n - 1];
        long long low = 1, high = position[n - 1], ans = 0, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (check(mid, position, m)) {
                ans = mid;
                low = mid + 1;

            }

            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};