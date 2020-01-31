#
# @lc app=leetcode.cn id=219 lang=python3
#
# [219] 存在重复元素 II
#

# @lc code=start
class Solution:
    # def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    @classmethod
    def containsNearbyDuplicate(self, nums, k):
        # 运用字典 - 哈希表来解题
        check_dict = {}
        for _index, _value in enumerate(nums):
            if _value not in check_dict.keys():
                check_dict[_value] = _index
            else:
                if (_index - check_dict[_value]) <= k:
                    return True
                else: check_dict[_value] = _index
        print(check_dict)
        return False

# @lc code=end

print (Solution.containsNearbyDuplicate(nums = [1,2,3,1,2,3], k = 2))