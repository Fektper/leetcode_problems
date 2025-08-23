
class Solution:
    def isPalindrome(self, x: int) -> bool:
        num_string = str(x)
        digits = len(num_string)

        for i in range(0, digits // 2):
            if not num_string[i] == num_string[digits - 1 - i]:
                return False
        return True
    

if __name__ == "__main__":
    num = 121
    sol = Solution()
    res = sol.isPalindrome(num)

    if res:
        print("Passed")
    else:
        print("Failed")