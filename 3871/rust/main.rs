impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        if n < 1000{
            return 0;
        }

        let mut border: i64 = 1000;
        let mut res = 0;
        let mut comma_count = 1;
        while n >= border * 1000{
            res += (border * 1000 - border) * comma_count;
            border = border * 1000;
            comma_count += 1;
        }
        res += (n - border + 1) * comma_count;

        return res;
    }
}