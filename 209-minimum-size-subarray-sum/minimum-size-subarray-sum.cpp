class Solution { 
public: 
    int minSubArrayLen(int target, vector<int>& nums) { 
        int left = 0; 
        int sum = 0; 
        int minLength = INT_MAX; 
        
        // Use a for loop to cleanly advance the right pointer
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right]; 
            
            // Shrink the window as long as the condition is met
            while (sum >= target) { 
                minLength = min(minLength, right - left + 1); 
                sum -= nums[left]; 
                left++; // FIX: Increment left to shrink the window
            } 
        } 
        
       
        return (minLength == INT_MAX) ? 0 : minLength; 
    } 
};
