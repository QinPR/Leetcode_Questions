// Given a string s, find the length of the longest substring without repeating characters.
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.


class Solution {
public:
    bool check_char_in_string(char ch, char* s, int length){
        for (int i = 0; i < length; i++){
            if (ch == s[i]) return true;
        }
        return false;
    }

    int lengthOfLongestSubstring(string s) {
        int string_len = s.length();
        int cur_len = 0;
        int max_one = 0;
        for (int i = 0; i < string_len; i++){
            char* cur_longest_str = (char*)malloc(sizeof(char)*string_len);
            cur_longest_str[0] = s[i];
            cur_len += 1;
            for (int j = i+1; j < string_len; j++){
                if (check_char_in_string(s[j], cur_longest_str, cur_len)){
                    break;
                }else{
                    cur_longest_str[cur_len] = s[j];
                    cur_len += 1;
                }
            }
            if (cur_len > max_one){
                max_one = cur_len;
            }
            cur_len = 0;
            free(cur_longest_str);
        }
        return max_one;
    }
};
