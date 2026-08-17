class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int total_size = nums.size();
        int first_num = 0;
        int last_num = total_size;

        while(first_num<last_num){

            int middle_num = first_num + (last_num - first_num) / 2;
            
            if(nums[middle_num] == target){
                return middle_num;
            }

            if(target < nums[middle_num]){
                last_num = middle_num;
             }

            if(target > nums[middle_num]){
                first_num = middle_num + 1;
            }

        }
        return first_num;
    }
};