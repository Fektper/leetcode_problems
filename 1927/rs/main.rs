use std::mem::swap;

impl Solution {
    pub fn sum_game(num: String) -> bool {
        let n = num.len();
        let mut left_sum = 0;
        let mut left_quest = 0;
        let mut right_sum = 0;
        let mut right_quest = 0;

        for (i, c) in num.chars().enumerate(){
            if i < n/2{
                if c == '?'{
                    left_quest += 1;
                }
                else {
                    left_sum += c.to_digit(10).expect("NaN") as i32;
                }
            }
            else {
                if c == '?'{
                    right_quest += 1;
                }
                else {
                    right_sum += c.to_digit(10).expect("NaN") as i32;
                }
            }
        }

        if (left_quest + right_quest) % 2 == 1{
            return true; // Alice always wins if she has las move
        }

        if left_quest == right_quest {
            return left_sum != right_sum; // Bob can always do same move on other side
        }

        if right_quest > left_quest{
            swap(&mut left_sum, &mut right_sum);
            swap(&mut left_quest, &mut right_quest);
        }

        let num_quest = left_quest - right_quest;
        let dif: i32 = right_sum - left_sum;
        if dif <= 0 {
            return true;
        }
        return dif != num_quest/2 * 9;

    }
}