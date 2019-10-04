//����һ��ʹ�����
//ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ�:O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(auto num : nums)
        {
            result^=num;
        }
        return result;
    }
};

//��������ʹ�����
//ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ�:O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
    }
};