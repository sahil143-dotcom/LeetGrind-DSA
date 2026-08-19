class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int totalSum = 0;
        int maxWeight = INT_MIN;
        for(int i=0; i<weights.size(); i++){
            totalSum += weights[i]; 
            maxWeight = max(maxWeight, weights[i]);
        }

        int s = maxWeight, e = totalSum;
        int mid = s + (e-s)/2;
        int ans = e;

        while (s <= e){

            int totalWeight = 0;
            int count = 1;
            for(int i=0; i<weights.size(); i++){
                if(totalWeight + weights[i] > mid){
                    count++;
                    totalWeight = 0;
                }
                totalWeight += weights[i];
            }
            if(count <= days){
                ans = min(ans, mid);
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }

            mid = s + (e-s)/2;
        }
        return ans;
    }
};