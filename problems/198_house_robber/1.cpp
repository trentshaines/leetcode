#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int take = 0;
        int skip = 0;
        for(const auto& num: nums){
            int last_take = take;
            take = std::max(skip + num, take);
            skip = last_take; // due to invariant, take >= skip.
        }   
        return take;
    }
};