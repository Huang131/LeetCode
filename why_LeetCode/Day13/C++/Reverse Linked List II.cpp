//����һ��ͷ�巨 һ�����
/*
��һ���ǽ����3�ŵ����1�ĺ��棬�ڶ��������4�ŵ����1�ĺ��档
���Ǻ��й��ɵĲ�������ô���Ǿ�˵һ�������ˣ�����տ�ʼ��preָ����1��curָ����2��
Ȼ�����ǽ���һ����ʱ�Ľ��t��ָ����3��ע����������ʱ��������ĳ��������Ϊ�����ȶϿ��ý���ǰ����֮�����ϵ��
����Ե���һ�����ɼ���������Ȼ�����ǶϿ����2�ͽ��3�������2��next�������4�ϣ�Ҳ���� cur->next = t->next��
�ٰѽ��3�������1�ĺ����㣨�����2����ǰ�棬�� t->next = pre->next������ٽ�ԭ���Ľ��1�ͽ��2�����ӶϿ���
�����1�������3���� pre->next = t���������Ǿ�����˽����3ȡ����������1�ĺ󷽡�
�ڶ��������4ȡ����������1�ĺ󷽣�Ҳ��ͬ���Ĳ�����
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);//ͷ���
        dummy.next=head;
        ListNode *p=&dummy;

        for(int i=0;i<m-1;i++)
            p=p->next;
        ListNode *cur=p->next;
        for(int i=m;i<n;i++)
        {
            ListNode *temp=cur->next;
            cur->next=temp->next;
            temp->next=p->next;
            p->next=temp;
        }
        return dummy.next;

    }
};

//�����������߱���
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p=head;
        stack<int> st;

        int i=1;
        while(p && i<=n && n>=m)
        {
            if(i>=m)
            {
                st.push(p->val);
            }
            i++;
            p=p->next;
        }

        p=head;
        i=1;
        while(p && i<=n && n>=m)
        {
            if(i>=m)
            {
                p->val=st.top();
                st.pop();
            }
            i++;
            p=p->next;
        }
        return head;

    }
};