#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 旋转数组
#

# @lc code=start
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # nums[:] 是深复制 ，在python的赋值中，是通过对象的地址引用进行的赋值，nums[:]修改的是堆中的内容，意思是指针还指向本身
        # nums = 是浅拷贝，修改nums就新开辟了一个地址空间, 测试代码为: 赋值后用 id(a) 与 id(a[:])查看地址
        nums[:] = nums[len(nums) - k:] + nums[:len(nums) - k]
        return nums
        
# @lc code=end
