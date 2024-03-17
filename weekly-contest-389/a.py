# 3083. Existence of a Substring in a String and Its Reverse
class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        s1 = s[::-1]
        for i in range(len(s)-1):
            if s[i:i+2] in s1:
                return True
        return False