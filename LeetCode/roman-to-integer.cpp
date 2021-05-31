// LEETCODE PROBLEM - https://leetcode.com/problems/roman-to-integer/

class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1) {
                if (values[s[i]] < values[s[i + 1]]) {
                    num += values[s[i + 1]] - values[s[i]];
                    i++;
                    continue;
                }
            }
            num += values[s[i]];
        }
        return num;
    }
};