//����һ��������ⷨ 
//���������е�ÿ��Ԫ�أ������ҳ������ˮ�ܴﵽ�����λ�ã������������߶ȵĽ�Сֵ��ȥ��ǰ�߶ȵ�ֵ��
//ʱ�临�Ӷȣ�O(N2) �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        const int n=height.size();
        int ans=0;

        for(int i=1;i<n-1;i++)
        {
            int max_left=0,max_right=0;
            for(int j=i;j>=0;j--)
            {
                max_left=max(max_left,height[j]);
            }
            for(int j=i;j<n;j++)
            {
                max_right=max(max_right,height[j]);
            }
            ans+=min(max_left,max_right)-height[i];
        }
        return ans;
    }
};


//����������̬�滮 
//��ǰ�洢max����ˣ�����ͨ����̬��̽��
//ʱ�临�Ӷȣ�O(N) �ռ临�Ӷȣ�O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;

        const int n=height.size();
        int ans=0;
        vector<int> max_left(n),max_right(n);

        max_left[0]=height[0];
        max_right[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            max_left[i]=max(max_left[i-1],height[i]);
            max_right[n-i-1]=max(max_right[n-i],height[n-i-1]);
        }
        for(int i=0;i<n;i++)
        {
            ans+=min(max_left[i],max_right[i])-height[i];
        }

        return ans;
    }
};

//������������߻��ֳ������֣��ֱ����� 
//ʱ�临�Ӷȣ�O(N) �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
            
        const int n=height.size();
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(height[i]>height[m])
                m=i;
        }

        int ans=0;
        for(int i=0,top=0;i<m;i++)
        {
            if(height[i]>top) 
                top=height[i];
            else
                ans+=top-height[i];
        }

        for(int i=n-1,top=0;i>m;i--)
        {
            if(height[i]>top)
                top=height[i];
            else
                ans+=top-height[i];
        }

        return ans;
    }
};

//�����ģ�ջ
//�����ǰ�����ο�С�ڻ����ջ�������ο飬���ǽ����ο��������ջ����˼�ǵ�ǰ�����ο鱻ջ�е�ǰһ�����ο�綨��
//������Ƿ���һ�����ο鳤��ջ�������ǿ���ȷ��ջ�������ο鱻��ǰ���ο��ջ��ǰһ�����ο�綨��������ǿ��Ե���ջ��Ԫ�ز����ۼӴ𰸵�ans��
//ʱ�临�Ӷȣ�O(N) �ռ临�Ӷȣ�O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;

        const int n=height.size();
        int ans=0;
        int current=0;
        stack<int> st;
        while(current<n)
        {
            while(!st.empty() && height[current]>height[st.top()])
            {
                int top=st.top(); //ԭtop  һ��Ҫpop
                st.pop();
                if(st.empty())
                    break;

                //height[st.top()] height[top] height[current]�γɹ���
                int distance=current-st.top()-1; //��top
                int bounded_height=min(height[current],height[st.top()])-height[top];
                ans+=distance*bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};