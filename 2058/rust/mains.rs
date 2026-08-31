// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

struct Solution{

}

fn local_extreme(a: i32, b: i32, c: i32) -> bool{
  (a > b && c > b) || (a < b && c < b)
}

impl Solution {
    pub fn nodes_between_critical_points(head: Option<Box<ListNode>>) -> Vec<i32> {
      let mut cur = head;
      let mut p2;
      let mut p1;
      let mut p0;
      

      match cur {
        Some(x) => {
          p1 = x.val;
          cur = x.next;
        },
        None => {return [-1, -1].to_vec()}
      }
      match cur {
        Some(x) => {
          p0 = x.val;
          cur = x.next;
        },
        None => {return [-1, -1].to_vec()}
      }
    
      let mut min_dist = -1;
      let mut max_dist = -1;
      let mut i = 1;
      let mut last_extrema = -1;

      loop {
        match cur{
          Some(x) => {
            p2 = p1;
            p1 = p0;
            p0 = x.val;
            cur = x.next;
          }
          None => {break}
        }
        i = i+1;

        if local_extreme(p2, p1, p0){
          if last_extrema == -1 {
            last_extrema = i-1;
          }
          else {
            let dist = i - 1 - last_extrema;
            last_extrema = i-1;
            if min_dist == -1 || dist < min_dist {
              min_dist = dist;
            }
            if max_dist == -1 {
              max_dist = dist;
            }
            else {
              max_dist = max_dist + dist;
            }
          }
        }
      }

      return [min_dist, max_dist].to_vec();
    }
}

fn main(){
    Solution::nodes_between_critical_points(None);
}

