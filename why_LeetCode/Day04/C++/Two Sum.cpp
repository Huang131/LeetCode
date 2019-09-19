'''
����һ�������ϣ�� O(n) 
ʹ�������ε������ڵ�һ�ε����У����ǽ�ÿ��Ԫ�ص�ֵ������������ӵ����С�
Ȼ���ڵڶ��ε����У����ǽ����ÿ��Ԫ������Ӧ��Ŀ��Ԫ�أ�target - nums[i]��
�Ƿ�����ڱ��С�ע�⣬��Ŀ��Ԫ�ز����� nums[i]����

'''

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++)
        {
            int another=target-nums[i];
            if(map.find(another)!=map.end()&&map[another]!=i)
            {
                result.push_back(i);
                result.push_back(map[another]);
                break;
            }
        }
        return result;
    }
};

'''
��������һ���ϣ��
�ڽ��е�������Ԫ�ز��뵽���е�ͬʱ���������Ƿ��Ѿ����ڵ�ǰԪ������Ӧ��Ŀ��Ԫ�ء�
��������ڣ��������Ѿ��ҵ��˶�Ӧ�⣬���������䷵�ء�
'''
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
            int another=target-nums[i];
            if(map.find(another)!=map.end()&&map[another]!=i)
            {
                result.push_back(i);
                result.push_back(map[another]);
                break;
            }
            map[nums[i]]=i;
        }
        return result;
    }
};