# 3084. Count Substrings Starting and Ending with Given Character
class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        x = s.count(c)
        return int(x * (x+1) / 2)