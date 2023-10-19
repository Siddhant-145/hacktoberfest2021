// solution of 242. Valid Anagram leetcode solution

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s ==t) return 1;
        return 0;

    }
};
