
struct Solution{

}

impl Solution {
    pub fn uniform_array(nums1: Vec<i32>) -> bool {
        let mut smallest_even = -1;
        let mut smallest_odd = -1;

        for n in nums1{
            if n% 2 == 0 && (smallest_even == -1 || n < smallest_even){
                smallest_even = n;
            }
            if n % 2 == 1 && (smallest_odd == -1 || n < smallest_odd){
                smallest_odd = n;
            }
        }

        if smallest_even == -1 || smallest_odd == -1{
            return true;
        }

        if smallest_even < smallest_odd{
            // Need to make everything even, but smallest odd can only be made even with smallest odd itself (so 0)
            return false;
        }
        // Need to make everything odd. all odds already are, all evens can be made odd with smalelst odd
        return true;

        // 2, 3, 4, 5
        // 3, 4, 5, 6
    }
}

fn main() {
    let res = Solution::uniform_array([2, 3].to_vec());
    println!("{res}");
}
