struct Solution {}

impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut rows: Vec<i32> = Vec::new();

        let mut prev = 0;
        let mut res = 0;

        for row in bank{
            let mut count = 0;
            for c in row.chars(){
                if c == '1'{
                    count += 1;
                }
            }
            res += prev *count;
            if count > 0{
                prev = count;
            }
        }
        return res;
    }
}

fn main(){
    let res = Solution::number_of_beams(vec!["0".to_string()]);

    println!("Solution: {res}");
}