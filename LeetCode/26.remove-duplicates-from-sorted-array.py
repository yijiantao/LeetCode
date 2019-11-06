# -*- coding:UTF-8 -*-

class Solution(object):
    @classmethod
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        _index = 0
        while _index < len(nums) - 1:
            if nums[_index] != nums[_index + 1]:
                _index += 1
            else:
                nums.pop(_index + 1)
        return len(nums)


if __name__ == "__main__":
    nums = [1,1,2]
    print(Solution().removeDuplicates(nums = nums))