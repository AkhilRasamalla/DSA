class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
         if (n == 0)
            return 0;

        // Recursive case
        long long moves = 0;

        // Move n-1 disks from 'from' to 'aux'
        moves += towerOfHanoi(n - 1, from, aux, to);

        // Move the largest disk from 'from' to 'to'
        moves += 1;

        // Move n-1 disks from 'aux' to 'to'
        moves += towerOfHanoi(n - 1, aux, to, from);

        return moves;
    }
};