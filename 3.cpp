/*
输入一个链表，从尾到头打印链表每个节点的值
*/
#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x);
        val(x),next(NULL)
        {

        }
};
vectir<int> reverse(struct ListNode * head)
{
    vector<int> result;
    stack<struct ListNode*> nodes;

    struct ListNode* pNode = head;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        result.push_back(pNode->val);
        nodes.pop();
    }
    return result;
}
int main()
{

    return 0;
}