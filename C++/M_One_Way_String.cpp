// There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

// Input: 
// first = "pale"
// second = "ple"
// Output: True

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int first_length = first.length();
        int second_length = second.length();
        if (first_length == second_length){ // maybe replace
            int diff_count = 0;
            for (int i = 0; i < first_length; i++){
                if (first[i] != second[i]) diff_count += 1;
            }
            if (diff_count <= 1) return true;
            return false;
        }
        if (first_length - second_length != 1 && first_length - second_length != -1){
            return false;
        }
        bool first_diff = false;
        if (first_length > second_length){
            int index_first = 0;
            int index_second = 0;
            while (index_first < first_length){
                if (!first_diff){
                    if (first[index_first] == second[index_second]){
                        index_first += 1;
                        index_second += 1;
                    }else{
                        first_diff = true;
                        index_first += 1;
                    }
                }else{
                    if (first[index_first] == second[index_second]){
                        index_first += 1;
                        index_second += 1;
                    }else{
                        return false;
                    }
                }
            }
        }
        else{
            int index_first = 0;
            int index_second = 0;
            while (index_second < first_length){
                if (!first_diff){
                    if (first[index_first] == second[index_second]){
                        index_first += 1;
                        index_second += 1;
                    }else{
                        first_diff = true;
                        index_second += 1;
                    }
                }else{
                    if (first[index_first] == second[index_second]){
                        index_first += 1;
                        index_second += 1;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
