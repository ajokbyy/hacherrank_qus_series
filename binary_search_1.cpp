// 34. Find First and Last Position of Element in Sorted Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109
// linear search ----
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = -1;
        int ro = -1;
        int n = nums.size();
        for(int idx = 0; idx < n; idx++){
            if(nums[idx] == target){
                lo = idx;
                break;
            }
        }
        for(int idx = n-1; idx >= 0; --idx){
            if(nums[idx] == target){
                ro = idx;
                break;
            }
        }
        return {lo, ro};
    }
    
};

//binary search ---
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = -1;
        int ro = -1;
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = (start + end)/2;
            if(nums[mid] > target){
                end = mid -1;

            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                lo = mid;
                end = mid -1;
            }
        }
        start = 0;
        end = n-1;
        while(start<=end){
            int mid = (start + end)/2;
            if(nums[mid] > target){
                end = mid -1;

            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                ro = mid;
                start = mid + 1;
            }
        }
        return {lo, ro};
    }
};
