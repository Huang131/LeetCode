#����һ���Ⱥϲ����������У�Ȼ���ٲ���  O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size()-1,n=nums2.size()-1;
        int k=nums1.size()+nums2.size()-1;
        int total=k;
        nums1.resize(k+1);
        while(m>=0&&n>=0)
        {
            if(nums1[m]>nums2[n])
            {
                nums1[k--]=nums1[m--];
            }
            else
            {
                nums1[k--]=nums2[n--];
            }
        }
        while(m>=0)
        {
            nums1[k--]=nums1[m--];
        }
        while(n>=0)
        {
            nums1[k--]=nums2[n--];
        }
        
        if(total%2==0)
        {
            return double(nums1[total/2]);
        }
        else
        {
            return double(nums1[total/2]+nums1[total/2+1])/2.0;
        }
    }
};

#��������С�ڵ���O(m+n)
#ʹ������ָ��pA��pB,�ֱ�ָ��A��B����ĵ�һ��Ԫ�أ�ʹ��������merge sort��ԭ��
#�������A��ǰԪ��С����ôpA++, ͬʱm++;�������B��ǰԪ��С����ôpB++��ͬʱm++�� 
#���յ�m����k��ʱ�򣬾͵õ������ǵĴ𰸡�
class Solution {
public:
    double sum=0.0;
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size()-1,n=nums2.size()-1;
        int k=nums1.size()+nums2.size()-1;
        const int total=k;
        const int key=total/2;
        while(m>=0&&n>=0)
        {
            
            if(nums1[m]>nums2[n])
            {
                if(check(nums1,total,key,k,m))
                    return sum/2.0;
                k--;
                m--;
            }
            else
            {
                if(check(nums2,total,key,k,n))
                   return sum/2.0;
                k--;
                n--;
            }
        }
        while(m>=0)
        {
                if(check(nums1,total,key,k,m))
                    return sum/2.0;
                k--;
                m--;
        }
        while(n>=0)
        {
               if(check(nums2,total,key,k,n))
                   return sum/2.0;
                k--;
                n--;
        }
        return 0.0;
    }
    
private:
    bool check(vector<int>& nums,const int total,const int key,int k,int loc)
    {    
        if(k==key||k==key+1)
        {
            if(total%2==0&&k==key)
            {
                sum=double(nums[loc]*2);
                return true;
            }
            else
            {
                sum+=double(nums[loc]);
                if(k==key)
                    return true;
            }
        }
        return false;
    }
};

#�����������ֲ��� O(log(m + n)) ��ϸ�ⷨ��jpg
class Solution {
public:
double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    const int m = A.size();
    const int n = B.size();
    int total = m + n;
    if (total & 0x1)
        return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
    else
        return (find_kth(A.begin(), m, B.begin(), n, total / 2)
                + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
}
    
private:
static int find_kth(vector<int>::const_iterator A, int m,vector<int>::const_iterator B, int n, int k) 
{
	//always assume that m is equal or smaller than n
    if(n<m) return find_kth(B,n,A,m,k);
    if(m==0) return *(B+k-1);
    if(k==1) return min(*A,*B);

    int a=min(k/2,m),b=k-a;
    if(*(A+a-1)<*(B+b-1))
        return find_kth(A+a,m-a,B,n,k-a);
    else if(*(A+a-1)>*(B+b-1))
        return find_kth(A,m,B+b,n-b,k-b);
    else
        return *(A+a-1);
}
};