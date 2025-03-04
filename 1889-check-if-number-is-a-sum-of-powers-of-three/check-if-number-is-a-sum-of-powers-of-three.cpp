class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;  // If remainder is 2, not possible
            n /= 3;  // Reduce n by dividing by 3
        }
        return true;  // If we reach 0, then it's possible
    }
};
