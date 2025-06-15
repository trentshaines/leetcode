class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = {}
        curr_len, l = 0, 0
        for r, x in enumerate(s):
            # If the last occurence of the current char is in window, set it after. 
            l = max(last.get(x, -1) + 1, l)
            last[x] = r
            curr_len = max(r - l + 1, curr_len)
        return curr_len