//����һ��
//λ���㣬֮ǰʹ����������ʵ������λ��������0+0=0��0+1=1��1+1=0(����λ�Ķ���������)��
//�ڴ����У�������0+1=1��1+1=2��1+2=0(����λ������������)��
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int n=sizeof(int)*8;
        vector<int> count(n,0);
        int result=0;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                count[j]+=(nums[i]>>j)& 1;
                count[j]%=3;
            }
        }
        for(int j=0;j<n;j++)
        {
            result+=(count[j]<<j);
        }
        return result;
    }
};


//��������
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0, threes=0;
        for (auto num : nums)
        {
            twos |= ones & num; // ������ĳλ����1��ʱtwos = 0������2, 3��ʱtwos = 1��
            ones ^= num;  // ������ĳλ����2��ʱones = 0������1, 3��ʱones = 1��
            threes = ones&twos ;// ������ĳλ����3��ʱ����twos = ones = 1ʱ��three = 1�����༴����1, 2��ʱthree = 0��
            ones &= ~threes; //���������³���3�ε�λ���㣬ʵ��`�������²����ǽ�λ�ļӷ�`��
            twos &= ~threes;
        }
        return ones;
    }
};