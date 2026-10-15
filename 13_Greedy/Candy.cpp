// brute

class Solution {
public:
    int minCandy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        // Left to right
        for (int i=1;i<n;i++) if(ratings[i]>ratings[i-1]) left[i]=left[i-1]+1;
        
        // Right to left
        for (int i=n-2;i>=0;i--) if(ratings[i]>ratings[i+1]) right[i]=right[i+1]+1;

        int ans = 0;
        for (int i = 0; i < n; i++) ans+=max(left[i],right[i]);
        
        return ans;
    }
};


// better

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        int ans = left[n - 1];

        // Right to left
        int right = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }

            ans += max(left[i], right);
        }

        return ans;
    }
};



// optimal
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }
};