class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        # 遍历前n-2个数
        for i in range(len(nums) - 2):
            # 双指针
            j, k = i + 1, len(nums) - 1
            while j < k:
                cur_sum = nums[i] + nums[j] + nums[k]
                if cur_sum == target:
                    return cur_sum
                # cur_sum 更接近目标
                if abs(cur_sum - target) < abs(result - target):
                    result = cur_sum

                if cur_sum < target:
                    j += 1
                elif cur_sum > target:
                    k -= 1

        return result