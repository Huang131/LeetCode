//ʱ�䣺2019-9-17
//���ߣ�fish_bot
//��Ŀ��LeetCode 81

class Solution {
public:
	bool search(vector<int>& nums, int target)
	{
		int len = nums.size();

		int head = 0;
		while (head != len) {
			int mid = (head + len) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[head] == nums[mid])//
			{
				head++;
			}
			else if (nums[head] < nums[mid])
			{
				if (target < nums[mid] && target >= nums[head])
					len = mid;
				else
					head = mid + 1;
			}

			else
			{
				if (target > nums[mid] && target <= nums[len - 1])
					head = mid + 1;
				else
					len = mid;
			}
		}

		return false;
	}
};


//��33��˼·����һ�£��ж�һ��head��mid��ȵ�����������Ⱦ�head++����һ��ʱ�临�Ӷ�ΪO��n��