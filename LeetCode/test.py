# -*- coding:UTF-8 -*-

class Solution(object):
    @classmethod
    def longestCommonPrefix(strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        import os
        return os.path.commonprefix(strs)

if __name__ == "__main__":
    print (Solution.longestCommonPrefix(strs = ["flower","flow","flight"]))