struct Solution {}

impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut rows: Vec<i32> = Vec::new();

        for row in bank{
            let mut count = 0;
            for c in row.chars(){
                if c == '1'{
                    count += 1;
                }
            }
            if count > 0{
                rows.push(count);
            }
        }

        let mut res = 0;
        if rows.len() <= 1{
            return 0;
        }
        for i in 0..rows.len()-1 {
            res += rows[i] * rows[i+1];
        }
        return res;
    }
}

fn main(){
    let res = Solution::number_of_beams(vec!["0".to_string()]);

    println!("Solution: {res}");
}