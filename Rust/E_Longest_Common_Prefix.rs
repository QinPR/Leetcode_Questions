// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".


// 写得很丑的一段代码
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut min_len = 10000;
        for s in &strs{
            if (min_len > s.len()){
                min_len = s.len();
            }
        } 
        if (min_len == 0){
            return "".to_string();
        }
        let mut prefix: String = String::from("");
        prefix.push((&strs[0].chars().collect::<Vec<char>>())[0]);
        for i in 0..min_len {
            let mut current_char = (&strs[0].chars().collect::<Vec<char>>())[i];
            for str in &strs{
                if (str.chars().collect::<Vec<char>>()[i] != current_char){
                    if (i == 0){
                        return "".to_string();
                    }
                    return prefix;
                }
            }
            if (i > 0) {
                prefix.push(current_char);
            }
        }
        return prefix;
    }
}