//����һ
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[index]!=nums[i])
                nums[++index]=nums[i];
        }
        return index+1;
    }
};

//������ ʹ�ñ�׼��
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=distance(nums.begin(),unique(nums.begin(),nums.end()));
        return l;
    }
};



