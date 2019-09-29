class Solution:
    def singleNumber(self, nums: [int]) -> int:
        ones, twos, threes = 0, 0, 0
        for num in nums:
            twos |= ones & num # ������ĳλ����1��ʱtwos = 0������2, 3��ʱtwos = 1��
            ones ^= num  # ������ĳλ����2��ʱones = 0������1, 3��ʱones = 1��
            threes = ones & twos # ������ĳλ����3��ʱ����twos = ones = 1ʱ��three = 1�����༴����1, 2��ʱthree = 0��
            ones &= ~threes # ���������³���3�ε�λ���㣬ʵ��`�������²����ǽ�λ�ļӷ�`��
            twos &= ~threes
        return ones
