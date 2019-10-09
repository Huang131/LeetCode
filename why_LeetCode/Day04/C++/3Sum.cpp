'''
���ȶ�ԭ�����������Ȼ��ʼ�������������飬
����ע�ⲻ�Ǳ��������һ��ֹͣ�����ǵ������������Ϳ����ˣ�
�м����������ǰһ������ͬ�����־�ֱ��������
���ڱ������������������0��������һ��������Ϊ��������0������Ӳ����ܵ���0��
������0��ȥ������õ�һ��sum������ֻ��Ҫ��֮���ҵ�������֮�͵���sum���ɣ�
����һ��������ת��Ϊ����two sum����ʱ������һ��ɨ�裬�ҵ��˵���sum��������
���ϵ�ǰ�����������֣���˳��������м��ɣ�Ȼ��Ҫע�������ظ����֡�
ʱ�临�Ӷ�Ϊ O(n2)

'''

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        
        const int target=0;
        auto begin=nums.begin(),last=nums.end()-1;
        for(auto i=begin;i<last-1;i++)
        {
            if(*(i)>0) break;
            if(i>begin&&*(i)==*(i-1)) continue;
            
            auto j=i+1;
            auto k=last;
            while(j<k)
            {
                if(*(i)+*(j)+*(k)<target)
                {
                    j++;
                    while(j<k&&*(j-1)==*(j)) j++;
                }
                else if(*(i)+*(j)+*(k)>target)
                {
                    k--;
                    while(j<k&&*(k+1)==*(k)) k--;
                }
                else
                {
                    result.push_back({*(i),*(j),*(k)});
                    j++;
                    k--;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) j++;
                }
            }
        }
        return result;
    }
};