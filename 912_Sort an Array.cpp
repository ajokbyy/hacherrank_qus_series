// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessarily unique.
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -5 * 104 <= nums[i] <= 5 * 104



// -------------------------------------------*****-------------------------------------------------
class Solution {
public:
    void divide(vector<int>& nums, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        divide(nums, start, mid);
        divide(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> merged(end - start + 1);

        int i = start;      // pointer for left half
        int j = mid + 1;    // pointer for right half
        int k = 0;          // pointer for merged

        // merge both halves
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                merged[k++] = nums[i++];
            } else {
                merged[k++] = nums[j++];
            }
        }

        // copy remaining elements (if any)
        while (i <= mid)   merged[k++] = nums[i++];
        while (j <= end)   merged[k++] = nums[j++];

        // copy back to original array
        for (int x = 0; x < merged.size(); ++x) {
            nums[start + x] = merged[x];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        divide(nums, 0, nums.size() - 1);
        return nums;
    }
};
