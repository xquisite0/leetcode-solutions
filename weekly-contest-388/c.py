# 3076. Shortest Uncommon Substring in an Array
class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        answer = [""] * len(arr)
        cur = 0
        for word in arr:
            
            for i in range(len(word)):
                sub = ""
                for j in range(i, len(word)):
                    sub += word[j]
                    works = True
                    for cur2 in range(len(arr)):
                        if cur2 == cur:
                            continue
                        word2 = arr[cur2]
                        if sub in word2:
                            works = False
                            break
                    if works:
                        if answer[cur] == "" or len(answer[cur]) > len(sub) or (len(answer[cur]) == len(sub) and sub < answer[cur]):
                            answer[cur] = sub
                            # print(cur, sub)
                        
            cur += 1
        return answer