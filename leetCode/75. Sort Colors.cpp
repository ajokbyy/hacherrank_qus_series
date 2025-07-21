----------------------------------------------------------------***------------------------------------------------------
  75. Sort Colors
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
  ----------------------------------------------------------***---------------------------------------------------------------------------------------------
  ans - >
  class Solution {
public:
    void sortColors(vector<int>& nums) {
// -----------------------------------------------------m2- optimize (here we are using Dutch Natioanl Flag Algo)
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        // here we are taking 3 pointer/veriable and use then to make it short
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        
    }
};


// ------------------------------------------------------------m1
// int red = 0, white = 0, blue = 0;
//         for(int n : nums){
//             if(n==0) red++;
//             else if(n==1) white++;
//             else blue++;
//         }
//         int index = 0;
//         while(red>0){
//             nums[index]=0;
//             index++;  --red;
//         }
//         while(white--){
//             nums[index++] =1;
//         }
//         while(blue>0){
//             nums[index++]=2;
//             blue--;
//         }
