'''
����˼·��ȥ�������е���elem��Ԫ�أ������µ����鳤�ȣ������е�Ԫ�ز��ر���ԭ����˳��
       ʹ��ͷβָ�룬ͷָ������elemʱ����βָ��ָ���Ԫ�ؽ�������elem�����������ĩβȥ��
'''

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        rear=len(nums)-1
        for front in range(len(nums)-1,-1,-1):
            if nums[front]==val:
                nums[front],nums[rear]=nums[rear],nums[front]
                rear-=1
        return rear+1