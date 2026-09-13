impl Solution {
    pub fn largest_overlap(img1: Vec<Vec<i32>>, img2: Vec<Vec<i32>>) -> i32 {
        let n = img1.len() as i32;
        let mut ones: Vec<(i32, i32)> = Vec::new();
        for i in 0..n {
            for j in 0..n {
                if img1[i as usize][j as usize] == 1 {
                    ones.push((i, j))
                }
            }
        }
        let mut max_overlap = 0;
        for dx in (-n)..n {
            for dy in (-n)..n {
                let mut current_overlap = 0;
                for (x, y) in ones.iter() {
                    if x + dx < n && x + dx >= 0 && y + dy < n && y+dy >= 0 && img2[(x+dx) as usize][(y+dy) as usize] == 1 {
                        current_overlap += 1;
                    }
                }
                if current_overlap > max_overlap {
                    max_overlap = current_overlap;
                }
            }
        }
        return max_overlap;
    }
}
