//�������߷�ת��Ȼ��ת��
class Solution:
    def rotate(self, matrix):  
        matrix[:] = map(list,zip(*matrix[::-1]))  