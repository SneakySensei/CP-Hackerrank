// LEETCODE PROBLEM - https://leetcode.com/problems/palindrome-number/

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int revHalf = 0;
        while (x > revHalf) {
            revHalf = revHalf * 10 + x % 10;
            x /= 10;
        }

        return x == revHalf || x == revHalf / 10;
    }
};