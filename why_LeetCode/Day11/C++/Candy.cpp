//�ַ��ǹ�

//����һ���������
//�ֱ�������ҡ������������rating,���ϸ���candy���飬ֱ�����鲻�ٷ����仯�����ͳ������
//ʱ�临�Ӷȣ�O(N2)  �ռ临�Ӷȣ�O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;

        int sum=0;
        vector<int> candy(ratings.size(),1);
        bool change=true;

        while(change)
        {
            change=false;
            for(int i=1;i<ratings.size();i++)
            {
                if(ratings[i]>ratings[i-1] && candy[i]<=candy[i-1])
                {
                    candy[i]=candy[i-1]+1;
                    change=true;
                }
            }

            for(int i=ratings.size()-2;i>=0;i--)
            {
                if(ratings[i]>ratings[i+1] && candy[i]<=candy[i+1])
                {
                    candy[i]=candy[i+1]+1;
                    change=true;
                }
            }
        }

        sum=accumulate(candy.begin(),candy.end(),0);
        return sum;
    }
};


//������������������
//�ֱ����һ���������飬ȡ��Ӧλ�õ����ֵΪ���ս�������ͳ������
//ʱ�临�Ӷȣ�O(N)  �ռ临�Ӷȣ�O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;

        int sum=0;
        vector<int> left2right(ratings.size(),1);
        vector<int> right2left(ratings.size(),1);
 
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                left2right[i]=left2right[i-1]+1;
            }
        }

        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                right2left[i]=right2left[i+1]+1;
            }
        }
        
        for(int i=0;i<ratings.size();i++)
        {
            sum+=max(left2right[i],right2left[i]);
        }
        
        return sum;
    }
};


//��������ʹ��һ������
//ʱ�临�Ӷȣ�O(N)  �ռ临�Ӷȣ�O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;

        int sum=0;
        vector<int> candy(ratings.size(),1);
 
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candy[i]=candy[i-1]+1;
            }
        }

        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }

        sum=accumulate(candy.begin(),candy.end(),0);

        return sum;
    }
};

//��������ʹ��һ������
//ʱ�临�Ӷȣ�O(N)  �ռ临�Ӷȣ�O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;

        int sum=0;
        vector<int> candy(ratings.size(),1);
 
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candy[i]=candy[i-1]+1;
            }
        }

        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }

        sum=accumulate(candy.begin(),candy.end(),0);

        return sum;
    }
};


//�����ģ�����һ��
//ʱ�临�Ӷȣ�O(N)  �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;

        int sum=0;
        int cursum=1;
 
        for(int i=0;i<ratings.size()-1;)
        {
            if(ratings[i]==ratings[i+1])
            {
                sum+=cursum;
                i++;
                cursum=1;
            }
            else if(ratings[i]<ratings[i+1])
            {
                for(;i<ratings.size()-1 && ratings[i]<ratings[i+1];i++) sum+=(cursum++);
            }
            else if(ratings[i]>ratings[i+1])
            {
                int decount=1;
                for(;i<ratings.size()-1 && ratings[i]>ratings[i+1];i++) sum+=(decount++);
                sum+=max(cursum,decount);
                sum--;
                cursum=1;
            }
        }
        sum+=cursum;

        return sum;
    }
};