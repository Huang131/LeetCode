#����һ
'''
   �������O(n log n)�ĸ��Ӷȣ���ô���������򣬿��Ǳ���Ҫ��O(n)��
   �����������Ԫ��������ģ���Ҫ��O(n)������Ҫ�뵽�ù�ϣ��
   ��һ����ϣ��unordered_ map<int, bool> used ��¼ÿ��Ԫ���Ƿ�ʹ��,��ÿ��Ԫ�أ��Ը�Ԫ
   ��Ϊ���ģ����������ţ�ֱ��������Ϊֹ����¼����ĳ��ȡ�
'''

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> used;
        for(auto i : nums) used[i]=false;
        int longest=0;

        for(auto i : nums)
        {
            if (used[i]) continue;

            int length=1;
            used[i]=true;
            for(int j=i+1;used.find(j)!=used.end();j++)
            {
                used[j]=true;
                length++;
            }
            for(int j=i-1;used.find(j)!=used.end();j--)
            {
                used[j]=true;
                length++;
            }
            longest=max(longest,length);
        }
        return longest;
    }
};

#��������
'''
��һֱ���Ǹ�����Ĳ�����Ӧ����union,find �Ĳ���.�������п��������˺ͳ�������;
ʾ.���������˾Ϳ��Ա�ʾ�� �����ǵ���ѯ�����󣬽����˷ֱ�¶����.��unordered_-
map<int��int> map ���洢.

'''
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        unordered_map<int,int> map;
        int length=1;
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(nums[i])!=map.end()) continue;

            map[nums[i]]=1;
            if(map.find(nums[i]-1)!=map.end())
            {
                length=max(length,mergeCluster(map,nums[i]-1,nums[i]));
            }
            if(map.find(nums[i]+1)!=map.end())
            {
                length=max(length,mergeCluster(map,nums[i],nums[i]+1));
            }   
        }
        return length;

    }

private:
    int mergeCluster(unordered_map<int, int> &map, int left, int right)
    {
        int upper=right+(map[right]-1);
        int lower=left-(map[left]-1);
        int length=upper-lower+1;
        map[upper]=length;
        map[lower]=length;
        return length;
    }
};