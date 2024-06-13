#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;

        int init_color = image[sr][sc];
        if (init_color == color) {
            return image; // No need to proceed if the initial color is the same as the new color
        }

        q.push({sr, sc});
        image[sr][sc] = color;

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == init_color) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};
