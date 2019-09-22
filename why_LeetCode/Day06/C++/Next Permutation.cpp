class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       //�ٷ�����
       //next_permutation(nums.begin(),nums.end());
       my_next_permutation(nums.begin(),nums.end());
    }

private:
    template<typename it>
    bool my_next_permutation(it first, it last)
    {
        //���������
        const auto rfirst=reverse_iterator<it>(last);
        const auto rlast=reverse_iterator<it>(first);
        
        //Ѱ������(a<b)��ab���������ҵ�a
        auto pivot=next(rfirst);
        while(pivot!=rlast && *pivot>=*prev(pivot))
        {
            pivot++;
        }

        //���a���Ƿ���ĩβ,��˵��û����һ������
        if(pivot==rlast)
        {
            reverse(rfirst,rlast);
            return false;
        }
        
        //Ѱ�����ұߵ�һ������a��ֵ��λ��
        auto change=find_if(rfirst,rlast,bind1st(less<int>(),*pivot));
        //����
        swap(*change,*pivot);
        //����
        reverse(rfirst,pivot);
        return true;
    }
};
