// Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

// An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

// A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

// For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
// Input: strs = ["aba","cdc","eae"]
// Output: 3


class Solution {
public:
    bool is_sub_str(string a, string b){ // check whether a is a sub string of b
        int i = 0;
        for (auto c: b){
            if (c == a[i] && i < a.size()) i++;
        }
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string a, string b){
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++){
            bool isSub = false;
            for (int j = 0; j < strs.size() && strs[i].size() <= strs[j].size(); j++){  // check whether string i is a sub string of string j
                if (i!=j && is_sub_str(strs[i], strs[j])){
                    isSub = true;
                    break;
                }
            }
            if (!isSub){
                return strs[i].size();
            }
        }
        return -1;
    }
};
