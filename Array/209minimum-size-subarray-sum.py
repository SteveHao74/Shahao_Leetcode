##209. 长度最小的子数组
'''
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-size-subarray-sum

'''
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        index_start = 0
        index_end = 1
        shortest_lenth = 0
        temp_sum = 0
        for  index_end in range(0,len(nums)):
            temp_sum += nums[index_end]
            while temp_sum>= target:
                # if temp_sum >= target:
                temp_lenth = index_end - index_start + 1
                if shortest_lenth==0: 
                    shortest_lenth = temp_lenth
                elif shortest_lenth> temp_lenth:
                    shortest_lenth = temp_lenth
                
                temp_sum -= nums[index_start]
                index_start += 1

        return shortest_lenth
                



