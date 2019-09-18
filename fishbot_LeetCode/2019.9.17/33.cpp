//ʱ�䣺2019-9-16
//���ߣ�fish_bot
//��Ŀ��LeetCode 33




class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		int len = nums.size();

		int head = 0;
		while (head != len) {
			int mid = (head + len) / 2;//ż��ȡ��һ��Ϊ��ֵ
			if (nums[mid] == target)
				return mid;
			if (nums[head] <= nums[mid])
			{
				if (target < nums[mid] && target >= nums[head])
					len = mid;
				else
					head = mid + 1;//������ֵ�����ص�������mid+1����-1
			}

			else
			{
				if (target > nums[mid] && target <= nums[len - 1])
					head = mid + 1;
				else
					len = mid;
			}
		}

		return -1;
	}
};

//ע���������飬ֻתһ��
//���ַ���������ֵ������ֵ�ĶԱ��ж���תλ��
//���������
//ǰ������ת��target��ǰ or �ں�
//�������ת��target�ں� or ��ǰ��
