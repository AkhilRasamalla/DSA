class Solution {
  public:
    int findMin(int n) {
        if (n == 1 || n == 2 || n == 5 || n == 10) {
            return 1; // directly handled, optional shortcut
        }

        vector<int> coins = {10, 5, 2, 1}; 
        int count = 0;

        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];   // manually pick element
            if (n >= coin) {
                count += n / coin;
                n %= coin;
            }
        }
        return count;
    }
};
