from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        lengths = []
        starts = []

        idx = 0
        
        while idx < len(nums):
            current_length = 0
            while idx < len(nums) and not nums[idx] == 1:
                idx += 1

            while idx + current_length < len(nums) and nums[idx + current_length] == 1:
                current_length += 1

            lengths.append(current_length)
            starts.append(idx)
            idx += current_length

        if len(lengths) == 0:
            return 0
        if lengths[0] == len(nums):
            return len(nums) - 1
        if len(lengths) == 1:
            return lengths[0]
        
        connectable = [i for i in range(len(starts) - 1) if starts[i] + lengths[i] + 1 == starts[i+1]]
        if len(connectable) == 0:
            return max(lengths)
        
        lengths_connected = [lengths[i] + lengths[i+1] for i in connectable]

        max_len = max(max(lengths), max(lengths_connected))

        return max_len



if __name__ == "__main__":
    test_input = [0,1,1,1,0,1,1,0,1]
    target_solution = 5

    solver = Solution()
    if solver.longestSubarray(test_input) == target_solution:
        print("Test passed!")
    else:
        print("Test failed")