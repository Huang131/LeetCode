'''
����һ���� 4->1,1,2
������Ȼ�����Ҽбƣ�ʱ�临�Ӷ�0(n^3)���ռ临�Ӷ�0(1)


'''

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());

        for(auto i=nums.begin();i<prev(nums.end(),3);i++)
        {
            for(auto j=i+1;j<prev(nums.end(),2);j++)
            {
                auto k=j+1;
                auto l=nums.end()-1;
                while(k<l)
                {
                    if(*(i)+*(j)+*(k)+*(l)<target)
                        k++;
                    else if(*(i)+*(j)+*(k)+*(l)>target)
                        l--;
                    else
                    {
                        result.push_back({*(i),*(j),*(k),*(l)});
                        k++;
                        l--;
                    }
                }
            }
        }
        sort(result.begin(),result.end());
	//unique��sort��ʹ��,���unique�ĵײ�����й�
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

'''
��������map 4->1,1,2(2->1)
��һ��hashmap�Ȼ����������ĺ�
ʱ�临�Ӷȣ�ƽ��0(n^2), �0(n^4)�� �ռ临�Ӷ�0(n^2)

'''
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        unordered_map<int,vector<pair<int,int>>> map;

        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                map[nums[i]+nums[j]].push_back(pair<int,int>(i,j));
            }
        }

        for(int k=0;k<nums.size();k++)
        {
            for(int l=k+1;l<nums.size();l++)
            {
                int gap=target-nums[k]-nums[l];
                if(map.find(gap)==map.end()) continue;

                auto& key_vec=map[gap];
                for(int m=0;m<key_vec.size();m++)
                {
                    if(k<=key_vec[m].second) continue;
                    result.push_back({nums[key_vec[m].first], nums[key_vec[m].second], nums[k], nums[l]});
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

'''
��������multimap 4->2(2->1),2(2->1)
��һ��hashmap �Ȼ����������ĺ�
ʱ�临�Ӷ�0(n^2)�� �ռ临�Ӷ�0(n^2)

'''
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());

        unordered_multimap<int,pair<int,int>> map;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                map.insert(make_pair(nums[i]+nums[j],make_pair(i,j)));
            }
        }

        //map ע���ֹ���� !=map.end() ��Ϊ�������Դ洢
        //vector ��ֹ���������� <vec.end()
        for(auto k=map.begin();k!=map.end();k++)
        {
            int gap=target-k->first;
            auto range=map.equal_range(gap);
            for(auto l=range.first;l!=range.second;l++)
            {
                auto a=k->second.first;
                auto b=k->second.second;
                auto c=l->second.first;
                auto d=l->second.second;
                if(a!=c&&b!=d&&a!=d&&b!=c)
                {
                    vector<int> vec{nums[a],nums[b],nums[c],nums[d]};
                    sort(vec.begin(),vec.end());
                    result.push_back(vec);
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};
