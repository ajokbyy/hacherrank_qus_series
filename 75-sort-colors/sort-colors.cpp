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