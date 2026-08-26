struct Solution{

}

fn lexicographically_smaller(s: &str, start: usize, end: usize, old_start: usize) -> bool {
    let mut i = 0;
    while i < end - start{
        if s.as_bytes()[start + i ] < s.as_bytes()[old_start + i]{
            return true;
        }
        else if s.as_bytes()[start + i] > s.as_bytes()[old_start + i]{
            return false;
        }
        i += 1;
    }
    return false;
}

impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        let n = s.len();

        let mut best_start = 0;
        let mut best_end = 0;

        let mut start = 0;
        while start < n && s.as_bytes()[start] == b'0'{
            start += 1;
        }
        if start == n{
            return "".to_string();
        }
        let mut end = start;
        let mut num_ones = 0;
        while end <= n{
            
            if start < n && s.as_bytes()[start] == b'0'{
                start += 1;
            }
            else if num_ones == k{
                if best_end == 0 || best_end - best_start > end - start{
                    best_start = start;
                    best_end = end;
                }
                else if best_end - best_start < end - start{
                    
                }
                else if lexicographically_smaller(&s, start, end, best_start){
                    best_start = start;
                    best_end = end;
                }
                start += 1;
                if s.as_bytes()[start - 1] == b'1'{
                    num_ones -= 1;
                }
            }
            else if num_ones < k{
                end += 1;
                if end <= n && s.as_bytes()[end-1] == b'1'{
                    num_ones += 1;
                }
            }
            else if num_ones > k {
                start += 1;
                if s.as_bytes()[start - 1] == b'1'{
                    num_ones -= 1;
                }
            }
        }
        if best_end != 0{
            let mut res = String::with_capacity(best_end - best_start);
            while best_start < best_end{
                res.push(s.as_bytes()[best_start] as char);
                best_start += 1;
            }
            return res;
        }
        "".to_string()
    }
}

fn main(){
    let s = "100011001".to_string(); // "1100100101011001001".to_string();
    let res = Solution::shortest_beautiful_substring(s, 3);
    println!("{res}");
}