impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        let mut res = 0;

        for (i, c) in s.as_bytes().iter().enumerate() {
            let fak: i32 = (c - b'a') as i32;
            res = res + -(fak - 26) * (i as i32 +1);
        }
        return res;
    }
}
