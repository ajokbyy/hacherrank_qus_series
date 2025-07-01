class Solution {
public:
void divide(vector<int> nums, int start, int end){
        if(start == end){
            return;
        }

        int mid = start + (end - start)/2;
        divide(nums, start, mid);
        divide(nums, mid+1, end);
        merge(nums, start, mid, end);
}
void merge(vector<int> nums, int start, int mid, int end){
    vector<int> merged(end = start +1);
        int i = start;
        int j = mid + 1;
        int k =0;
        while(j<= end && i<= mid){ 
            if(nums[i]<= nums[j]){
                merged[k] == nums[i];
                i++;
                k++;
            }
            else{
                merged[k] = nums[j];
                j++;
                k++;
            }
        }
        while(j<=end){
            merged[k] = nums[j];
            j++;
            k++;
        }
        while(i<=mid){
            merged[k] = nums[i];
            i++;
            k++;
        }
        for(int x = 0; x<merged.size(); x++){
            nums[start + x] = merged[i];
        }
}
   
    
 vector<int> sortArray(vector<int>& nums) {
    divide(nums, 0, nums.size()-1);
    return nums;
    }
};
