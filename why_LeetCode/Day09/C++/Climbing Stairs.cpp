//�ݹ飬��ʱ
class Solution {
public:
    int climbStairs(int n) {
        return fac(n);
    }

private:
    int fac(int n)
    {
        if(n==1||n==2)
            return n;
        else
            return fac(n-1)+fac(n-2);
    } 
};

//����
class Solution {
public:
    int climbStairs(int n) {
        int cur=1; //��ǰֵ
        int pre=0; //ǰһ��ֵ
        for(int i=1;i<=n;i++)
        {
            int temp=cur;
            cur+=pre;
            pre=temp;
        }

        return cur;
    }
};


//��ѧ��ʽ
//쳲���������  a1=1 a2=1 a3=2  ����nҪ��һ ʹ��1���Ӧa2,2���Ӧa3
class Solution {
public:
int climbStairs(int n) {
    const double s = sqrt(5);
    return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
    }
};