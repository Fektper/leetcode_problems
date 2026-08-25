impl Solution {
    pub fn missing_multiple(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let mut i = 0;
        let mut m = 1;
        let n = nums.len();
        loop{
            if i >= n{
                return m*k;
            }
            else if nums[i] < m*k {
                i += 1;
            }
            else if nums[i] == m*k{
                i += 1;
                m += 1;
            }
            else {
                return m*k;
            }
        }
    }
}