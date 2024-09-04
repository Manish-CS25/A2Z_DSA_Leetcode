class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int d = 0;  // direction: 0 - north, 1 - east, 2 - south, 3 - west
        int x = 0, y = 0;  // starting position
        int mxDist = 0;  // max distance squared from origin

        unordered_map<string, int> mp;
        for (auto it : obstacles) {
            string key = to_string(it[0]) + "+" + to_string(it[1]);
            mp[key]++;
        }

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] > 0) {
                int k = 0;

                while (k < commands[i]) {
                    // Move in the current direction
                    if (d == 0) {
                        y++;
                    } else if (d == 1) {
                        x++;
                    } else if (d == 2) {
                        y--;
                    } else {
                        x--;
                    }

                    string key = to_string(x) + "+" + to_string(y);
                    if (mp.find(key) != mp.end()) {
                        // Step back if the new position is an obstacle
                        if (d == 0) {
                            y--;
                        } else if (d == 1) {
                            x--;
                        } else if (d == 2) {
                            y++;
                        } else {
                            x++;
                        }
                        break;
                    }

                    k++;
                    mxDist = max(mxDist, x * x + y * y);
                }
            } else if (commands[i] == -1) {
                if(d==3)
                d=0;
                else d+=1;
            } else if (commands[i] == -2) {
                if(d==0)
                d=3;
                else d-=1;
                  // Turn left (equivalent to -1 mod 4)
            }
        }
        return mxDist;
    }
};
