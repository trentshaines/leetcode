#include <iostream>
#include <vector>

class Solution {
private:
    bool canJumpHelper(std::vector<int>& nums, size_t current_index) {
        size_t n = nums.size();
        
        if (nums[current_index] == -1)
            return false;
        if (current_index == n - 1)
            return true;

        std::cout << "Visited index " << current_index << " jumping up to " << nums[current_index] << "\n";

        for (size_t next = current_index + 1; next <= std::min(current_index + nums[current_index], n-1); ++next){
            if (canJumpHelper(nums, next))
                return true;
        }
        nums[current_index] = -1;  // Mark as visited

        return false;
    }

public:
    bool canJump(std::vector<int>& nums) {
        // DFS + memo using in-place marking
        return canJumpHelper(nums, 0);
    }
};

int main() {
    Solution solution;
    // Test case 1: [2,3,1,1,4] - should return true
    std::vector<int> nums1 = {2, 3, 1, 1, 4};
    bool result1 = solution.canJump(nums1);
    
    return 0;
}
