//Link:  https://leetcode.com/problems/random-pick-with-weight/

//function pickIndex randomly picks an index in proportion to its weight.
class Solution {
public:
    vector<int> vec;
    Solution(vector<int>& w) {
        vec.push_back(w[0]);
        for(int i=1;i<w.size();i++)
        {
            vec.push_back(w[i]+vec[i-1]);
        }
    }

    int pickIndex() {
        int lim=vec.back();
        //val is any value from 0 to lim-1
        int val=rand() % lim;
        //we try to map to the larger element to value that is fetched by rand
        // sample w: 5  2  15  3
        // vec: 5  7  22  25
        // chances to be fetched 5 : 0-4 (5)
        //                       7 : 5-6 (2)
        //                       22: 7-21 (15)
        //                       25: 22-24 (3)
        auto it=upper_bound(vec.begin(),vec.end(),val);
        return it-vec.begin();
    }
};
