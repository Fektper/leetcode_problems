impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut mins = [nums[n-1]; 100];
        for i in (0..n-1).rev(){
            mins[i] = std::cmp::min(mins[i+1], nums[i]);
        }

        let mut biggest = nums[0];
        for i in 0..n{
            biggest = std::cmp::max(biggest, nums[i]);
            if biggest - mins[i] <= k{
                return i as i32;
            }
        }
        return -1;

    }
}
