# ���������в��ظ���Ԫ�ظ���
# ���������±꣬index��Ϊ���գ�i�±��ͷ��β��ʼ����
# �������±��Ӧ��ֵ�����ʱ����ʼ���н���
def removeDuplicates(nums):
    if not nums:
        return 0
    index = 0
    for i in range(len(nums)):
        if nums[index] != nums[i]:
            index = index + 1
            nums[index] = nums[i]
    return index + 1


print(removeDuplicates(sorted([1, 2, 3, 2, 2, 3, 1])))
