'''
������c++�ĵڶ��ַ�����
����һ����ϣ��key������˵㣬val���������ĳ��ȡ�


����ɨ���������飬�����ǰԪ���Ѿ��ڹ�ϣ�����������


������ڹ�ϣ����Ϳ�һ����������������ĳ���left��right��
���������������䳤��length = 1 + left + right��


������֮������µ����Ҷ˵�ĳ���Ϊ��
len_dict[num - left] =length = len_dict[num + right],
len_dict[num]Ҳ��ֵ��Ϊ��ռ��λ�ӡ�

�ص㣺�����˵㣬�Լ����䳤�ȡ�

'''


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        len_dict={}
        longest=0
        
        for num in nums:
            if num not in len_dict:
                left=len_dict.get(num-1,0)
                right=len_dict.get(num+1,0)
                
                length=left+right+1;
                longest=max(longest,length)
                
                for i in [num-left,num,num+right]:
                    len_dict[i]=length
        return longest