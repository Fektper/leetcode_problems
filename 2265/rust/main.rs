// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}

struct Solution{

}

fn calc_tree(root: &Option<Rc<RefCell<TreeNode>>>) -> (i32, i32, i32) {
    // Return number of nodes and sum of nodes
    match root{
      None => {return (0, 0, 0)},
      Some(node) => {
        let node = node.borrow();

        let (left_num, left_sum, left_res) = calc_tree(&node.left);
        let (right_num, right_sum, right_res) = calc_tree(&node.right);

        let avg = (left_sum + right_sum + node.val) / (left_num + right_num + 1);

        if node.val == avg{
          return (left_num + right_num + 1, left_sum + right_sum + node.val, left_res + right_res + 1);
        }
        (left_num + right_num + 1, left_sum + right_sum + node.val, left_res + right_res)
      }
    }
}

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {

      let (num_nodes, value_sum, res)= calc_tree(&root);
      return res;
    }
}