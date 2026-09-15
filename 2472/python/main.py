def findMinPalindromeUneven(s: str, start: int, min_length: int):
    if min_length == 1:
        return start
    left = start
    right = start
    while right - left + 1 < min_length:
        left = left - 1
        right = right + 1
        if left < 0 or right >= len(s) or s[left] != s[right]:
            return -1
        
    return right

def findMinPalindromeEven(s: str, start: int, min_length: int):
    left = start - 1
    right = start
    if left < 0 or s[left] != s[right]:
        return -1
    
    while right - left + 1 < min_length:
        left -= 1
        right += 1
        if left < 0 or right >= len(s) or s[left] != s[right]:
            return -1

    return right        



class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        res: int = 0

        min_dist = int(k / 2)
        start_pos = min_dist
        even_length = k%2 == 0

        while start_pos < len(s):
            if even_length:
                right = findMinPalindromeEven(s, start_pos, k)
                if right == -1:
                    right = findMinPalindromeUneven(s, start_pos, k)
            else:
                right = findMinPalindromeUneven(s, start_pos, k)
                if right == -1:
                    right = findMinPalindromeEven(s, start_pos, k)

            if right == -1:
                start_pos += 1
            else:
                res += 1
                
                start_pos = right + 1 + min_dist

        return res


def main():
    test_string = "abaccdbbd"
    test_k = 3

    res = Solution().maxPalindromes(test_string, test_k)
    print(res)



if __name__ == "__main__":
    # print(findMinPalindromeEven("abaccdbbd", 7, 3))
    main()