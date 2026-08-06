class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int duplicate;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                duplicate = nums[i];
            }
        }
        int expectedSum = n*(n+1)/2;
        int actualSum = 0;
        for(int i = 0; i < n; i++){
            actualSum += nums[i];
        }

        int missing = expectedSum - actualSum + duplicate;

        return {duplicate, missing};

        
    }
};