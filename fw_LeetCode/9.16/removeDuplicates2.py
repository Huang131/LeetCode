# ����ԭ�����Ѿ��ź�����,�ӵڶ���Ԫ�ؿ�ʼ�������Ƚ����������ߵ�ֵ
# �������ʱ����i��ֵ����count�±��ֵ

def removeDuplicates(nums)
    if len(nums)  3
        return len(nums)
    count = 1
    for i in range(1, len(nums) - 1)
        if nums[i - 1] != nums[i + 1]
            nums[count] = nums[i]
            count += 1
    nums[count] = nums[-1]
    return count + 1


print(removeDuplicates([1, 1, 1, 1, 3, 3, 3, 4, 4, 5]))