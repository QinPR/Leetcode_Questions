impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let mut string_x: String = x.to_string();

        let string_rev:String = string_x.chars().rev().collect();  
        //看来string_x.chars()并不会取走ownership

        if (string_x == string_rev){
            return true;
        }
        return false;
    }
}