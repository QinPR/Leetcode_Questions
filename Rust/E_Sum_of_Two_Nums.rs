// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案


impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut answer = Vec::new();
        let mut i = 0;
        let mut j = 0;
        let length = nums.len();
        while i < length{
            j = i + 1;
            while j < length{
                if (nums[i] + nums[j] == target){
                    answer.push(i as i32);
                    answer.push(j as i32);
                    return answer;
                }
                j += 1;
            }
            i += 1;
        }
        answer
    }
}