// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {

//         long long sum = 0;
//         int n = skill.size();

//         unordered_map<int, int> mp;

//         for (int i = 0; i < n; i++) {
//             mp[skill[i]]++;
//             sum += skill[i];
//         }

//         int teams = n / 2;
//         if (sum % teams != 0)
//             return -1;
//         int skill_count = sum / teams;

//         sum = 0;
//         for (int i = 0; i < n; i++) {
//             int rem = skill_count - skill[i];
//             if (mp.find(rem) != mp.end()) {
//                 if (mp[skill[i]] > 0 && mp[rem] == 0)
//                     return -1;

//                 if (mp[skill[i]]) {

//                     sum += skill[i] * rem;
//                     mp[rem]--;
//                     mp[skill[i]]--;
//                 }

//             } else
//                 return -1;
//         }

//         return sum ;
//     }
// };



// ==================Another Optimal Approach ============

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        long long sum = 0;
        int n = skill.size();


        for (auto &it:skill) {

            sum += it;
        }

        int teams = n / 2;
        if (sum % teams != 0)
            return -1;
        int skill_count = sum / teams;
        sort(skill.begin(), skill.end());
        int left = 0, right = n-1;

        sum = 0;

        while(left<right){
            if(skill[left]+skill[right]!=skill_count)
            return -1;

            else sum+= skill[left]*skill[right];

            left++;
            right--;
        }


        return sum ;
    }
};