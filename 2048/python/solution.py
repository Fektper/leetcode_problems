# Precomputation code
def all_permut_nums(digits: list[int]):
    if (len(digits) == 1):
        return [digits[0]]
    all_nums = []
    fac = 10**(len(digits)-1)
    for i in range(len(digits)):
        all_nums += [fac * digits[i] + x for x in all_permut_nums(digits[:i] + digits[i+1:])]

    return list(set(all_nums))


def get_digits(i):
    digits = []
    for j in range(0, 6):
        if ((2**j) & i):
            digits.append(j+1)

    return digits

def generate_digits(digits):
    expanded_digits = []
    for dig in digits:
        for i in range(dig):
            expanded_digits.append(dig)

    return all_permut_nums(expanded_digits)
    

def gen_balanced_nums(max_digit = 6):
    all_digits = []
    for num_digs in range(1, max_digit+1):
        combos = [get_digits(i) for i in range(2**num_digs)]
        combos= [x for x in combos if sum(x) == num_digs]
        all_digits+= combos

    all_nums = []
    for dig in all_digits:
        all_nums += generate_digits(dig)

    return all_nums

# Super smart algorithm

import bisect

class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        max_gen = 1
        while (int(n / (10**max_gen)) > 0):
            max_gen += 1

        candidate_nums = [1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555, 122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232, 133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313, 223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123, 233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321, 331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321, 333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424, 442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444]
        return candidate_nums[bisect.bisect_right(candidate_nums, n)]