from typing import List



MAX_BIT_DIGIT = 16 # floor log2(10^5)

def get_or_set(elements, start = 0):
    res = start
    for x in elements:
        res |= x

    return res

def this_index_necessary(target, idx, nums):
    total_or_val = 0
    for i in range(len(nums)):
        if i == idx:
            continue
        total_or_val |= nums[i]

    return not total_or_val == target
def number_necessary(target, num, others):
    return not get_or_set(others) == num

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:

        max_possible_value = get_or_set(nums)
        
        candidate_nums = [x for x in nums if x & max_possible_value]
        

        fixed_nums_indices = [i for i in range(len(candidate_nums)) if this_index_necessary(max_possible_value, i, candidate_nums)]

        potential_nums_indices = [i for i in range(len(candidate_nums)) if not i in fixed_nums_indices]

        set_num = 0
        for i in range(0 if len(fixed_nums_indices) >= 1 else 1, 1<<len(potential_nums_indices)):
            num_indices = []
            for num_index in range(len(potential_nums_indices)):
                if i & (1<<num_index):
                    num_indices.append(potential_nums_indices[num_index])

            total_or_value = get_or_set([candidate_nums[idx] for idx in num_indices])

            total_or_value = get_or_set([candidate_nums[i] for i in fixed_nums_indices], total_or_value)

            if total_or_value == max_possible_value:
                set_num += 1

        return set_num