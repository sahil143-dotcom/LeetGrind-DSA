class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int maxSoFar = 0;

        for(int i=1;i<prices.size();i++){
            minSoFar = min(minSoFar, prices[i]);
            maxSoFar = max(maxSoFar, prices[i]-minSoFar);
        }
        return maxSoFar;
    }
};