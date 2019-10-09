//����һ��һ�α��� ʱ�临�Ӷ�:O(n2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int num=gas.size();
        bool flag;
        for(int i=0;i<num;i++)
        {
            int j=i;
            int total_cost=0,total_gas=0;
            flag=false;
            while(1)
            {
                total_gas+=gas[j];
                total_cost+=cost[j];
                if(total_gas>=total_cost)
                {
                    j++;
                    j%=num;
                    if(j==i)
                        break;
                }
                else
                {
                    flag=true;
                    break;
                }
            }
            
            if(!flag)
                return j;            
        }
        
        if(flag)
            return -1;
        
        return 0;
    }
};

//������:ʱ�临�Ӷ� O(N) �ռ临�Ӷ� O(1)
//����Ҫ֪����������������ǰ����gas������Ҫ����cost�������������Ż������Ĵ��ڡ�
//���迪ʼ�������start = 0, ������������������ǰ��gasֵ����costֵ���Ϳ��Լ���ǰ����
//��ʱ����һ��վ�㣬ʣ���gas���ϵ�ǰ��gas�ټ�ȥcost�����Ƿ����0��������0�������ǰ����
//������ĳһվ��ʱ�������ֵС��0�ˣ���˵������㵽������м���κ�һ���㶼������Ϊ��㣬
//��������Ϊ��һ���㣬������������������������ʱ����ǰ�������㼴Ϊ����
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int j = 0;
        for (int i = 0, sum = 0; i < gas.size(); i++) 
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i+1;
                sum = 0;
                }
        }
        return total >= 0 ? j : -1;

    }
};
