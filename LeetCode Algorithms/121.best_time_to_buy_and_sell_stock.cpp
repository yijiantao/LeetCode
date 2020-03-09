#include <iostream>
 
using namespace std;
#include<vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        if (prices.size() != 0){
            int buy_price = prices[0];
            for (int _day=1; _day < prices.size(); ++_day){
                if (prices[_day] < buy_price){
                    buy_price = prices[_day];
                }
                else{
                    if ((prices[_day] - buy_price) > max_profit){
                        max_profit = (prices[_day] - buy_price);
                    }
                }
            }
        }
        return max_profit;
    }
};

int main( )
{
    vector<int> prices = {7,6,4,3,1};
    int minprice = 0, maxprofit = 0;
    for (int price: prices) {
        cout<<price<<endl;
        maxprofit = max(maxprofit, price - minprice);
        minprice = min(price, minprice);
    }
    Solution s;
    int max_profit = s.maxProfit(prices);
    cout<<max_profit<<endl;
    return 0;
}