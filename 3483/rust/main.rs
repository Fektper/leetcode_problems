use std::collections::HashSet;

impl Solution {
    pub fn total_numbers(digits: Vec<i32>) -> i32 {

        if digits.len() < 3{
            return 0;
        }
        let mut res = 0;
        let mut nums: HashSet<i32> = HashSet::new();

        for i in 0..digits.len(){
            if digits[i] == 0{
                continue;
            }
            for j in 0..digits.len(){
                if i==j{
                    continue;
                }
                for k in 0..digits.len(){
                    if i==k || j==k{
                        continue;
                    }
                    let val = digits[i]*100 + digits[j]*10 + digits[k];
                    if val % 2 == 0 && !nums.contains(&val){
                        res += 1;
                        nums.insert(val);
                    }

                }
            }
        }
        return res;
    }
}
