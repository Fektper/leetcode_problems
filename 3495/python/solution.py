from typing import List
from math import log, ceil


def calculateOps(l, r):
    minDepth = int(log(l, 4))
    maxDepth = int(log(r, 4))

    if (minDepth == maxDepth):
        nums = r-l+1
        ops = minDepth + 1
        return int(ceil(nums*ops/2))
    
    currentDepth = minDepth
    total_ops = 0
    this_ops = 0
    this_nums = 0
    while (currentDepth < maxDepth):
        nextStop = 4**(currentDepth+1) - 1
        this_nums = nextStop - l + 1
        this_ops = currentDepth + 1
        total_ops += this_nums * this_ops
        l = nextStop + 1
        currentDepth += 1

    total_ops += (r-l+1) * (maxDepth + 1)

    return int(ceil(total_ops/2))


    

class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        totalOps = 0
        for query in queries:
            totalOps += calculateOps(query[0], query[1])

        return totalOps
    

if __name__ == "__main__":
    solver = Solution()
    test_input = [[1,2],[1, 1000000000]]
    target_solution = 1 + 7321043037
    res = solver.minOperations(test_input)

    if (res == target_solution):
        print("Test passed")
    else:
        print(f"Test failed! Expected {target_solution} but got {res}")