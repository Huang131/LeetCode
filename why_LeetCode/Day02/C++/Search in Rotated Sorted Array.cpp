    //���ö��ֲ��ҿ������㸴�Ӷȵ�Ҫ�󣬵��б�������

    //�����λ������ߴ�˵������ǵ����ģ��ϵ����ұߣ�
    //���target����ߵ��������䣬������߲��ң��������ұ߲���.

    //�����λ�������С��˵���ұ��ǵ����ģ��ϵ�����ߣ�
    //���target���ұߵĵ������䣬�����ұ߲��ң���������߲��ҡ�

class Solution {
public:
    int search(vector<int>& nums, int target) {
    int first=0,last=nums.size();  
    while(first!=last)
    {
        const int mid=(first+last)/2;
        if (nums[mid]==target)
            return mid;
        
	//�������
        if(nums[first]<=nums[mid])
        {
            if(nums[first]<=target&&target<nums[mid])
                last=mid;
            else
                first=mid+1;
        }
        //�ұ�����
        else
        {
            if(nums[mid]<target&&target<=nums[last-1])
                first=mid+1;
            else
                last=mid;
        }
        
    }
    return -1;
    }
};