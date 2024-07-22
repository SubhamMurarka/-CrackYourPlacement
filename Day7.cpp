//Q21 : Buy and sell stock.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int profit = 0;
        for(int i=0; i<n; i++) {
            profit = max(profit, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return profit;
    }
};

//Q22 : Buy and sell stocks ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //[4 2 5 3]
        int n = prices.size();
        int i = 0, j = i+1, flag = 0;
        int mx = 0, profit = 0;
        int prev_diff = 0;
        while(i < n && j < n) {
           int curr_diff = prices[j]-prices[i];
           while(j<n && curr_diff >= prev_diff) {
               flag = 1;
               prev_diff = curr_diff;
               j++;
               if(j<n)curr_diff = prices[j] - prices[i];
           }
            profit += prev_diff;
            prev_diff = 0;
            if(flag == 1){
                flag = 0;
                i=j;
                j=j+1;
            }else{
                i++; j++;
            }
            
        }
        return profit;
    }
};