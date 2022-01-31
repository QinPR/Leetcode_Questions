// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
// Input: s = "leetcode"
// Output: false

class Solution {
public:
    bool isUnique(string astr) {
        int * bitmap = (int*)malloc(sizeof(int)*26);
        for (int i = 0; i < 26; i++){
            bitmap[i] = 0;    // indicate that this char haven't appear yet
        }
        for (int i = 0; i < astr.length(); i++){
            if (bitmap[astr[i] - 'a'] == 1){
                free(bitmap);
                return false;
            }else{
                bitmap[astr[i] - 'a'] = 1;
            }
        }
        free(bitmap);
        return true;
    }
};
