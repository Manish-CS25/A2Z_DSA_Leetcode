// ==============BruteForce Approach===============

// class Solution {
// public:
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         int n = times.size();
//         int targetArrivalTime = times[targetFriend][0];

//         vector<int> chairs(n, -1);

//         sort(begin(times), end(times));

//         for (vector<int>& time : times) {
//             int arrival = time[0];
//             int depart = time[1];
//             for (int i = 0; i < n; i++) {

//                 if (chairs[i] <= arrival) {
//                     chairs[i] = depart;

//                     if (arrival == targetArrivalTime) {
//                         return i;
//                     }
//                     break;
//                 }
//             }
//         }

//         return -1;
//     }
// };

// ======== Optimal Approach =========================

class Solution {
public:
    typedef pair<int, int> p;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<p, vector<p>, greater<p>> ocuppied; // dpart , chairno.
        priority_queue<int, vector<int>, greater<int>>
            freeChair; // available chair no.

        int targetArrivalTime = times[targetFriend][0];

        vector<int> chairs(n, -1);
        int chairNo = 0;

        sort(times.begin(), times.end());

        for (int i = 0; i < n; i++) {

            int arrival = times[i][0];
            int depart = times[i][1];

            while (!ocuppied.empty() && ocuppied.top().first <= arrival) {
                freeChair.push(ocuppied.top().second);
                ocuppied.pop();
            }

            if (freeChair.empty()) {

                ocuppied.push({depart, chairNo});
                if (arrival == targetArrivalTime) {
                    return chairNo;
                }

                chairNo++;

            }

            else {
                int currAvalChair = freeChair.top();
                freeChair.pop();

                if (arrival == targetArrivalTime) {
                    return currAvalChair;
                }
                ocuppied.push({depart, currAvalChair});
            }
        }

        return -1;
    }
};
