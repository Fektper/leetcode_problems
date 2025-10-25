struct Solution{}

impl Solution {
    pub fn total_money(n: i32) -> i32 {
        let mut previous_monday: i32 = 0;
        let mut previous_day: i32 = 0;
        let mut total_money: i32 = 0;

        for n in 0..n {
            if n % 7 == 0 {
                previous_monday += 1;
                previous_day = previous_monday
                
            } else{
                previous_day += 1;
            }
            total_money += previous_day;
        }
        return total_money;
    }
}

fn main(){
    // let test = Solution{};

    println!("{}", Solution::total_money(5))

}