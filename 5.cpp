/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型

用stack1来实现队列的push操作，
用stack2来实现队列的pop操作，
当stack2为空时，将stack1的数据全部压入stack2，等待队列的pop操作
*/
class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int result;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
}