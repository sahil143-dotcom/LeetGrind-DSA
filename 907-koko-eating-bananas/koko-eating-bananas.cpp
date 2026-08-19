class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = -1;
        int high = 1;

        for(int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }

        int low = 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            long long count = 0;

            for(int i = 0; i < piles.size(); i++) {
                    count += piles[i] / mid;
                if(piles[i]%mid !=0)
                    count += 1;
            }

            if(count > h)
                low = mid + 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};