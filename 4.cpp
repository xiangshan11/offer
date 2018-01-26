/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
*/
/*
先序遍历的第一个元素为根节点，在中序遍历中找到这个根节点，从而可以将中序遍历分为左右两个部分，
左边部分为左子树的中序遍历，右边部分为右子树的中序遍历，进而也可以将先序遍历除第一个元素以外的剩余部分分为两个部分，
第一个部分为左子树的先序遍历，第二个部分为右子树的先序遍历。
由上述分析结果，可以递归调用构建函数，根据左子树、右子树的先序、中序遍历重建左、右子树。
*/
/*
数组+递归
*/
#include <iostream>
using namespace std;

//树结点结构体
struct BinaryTreeNode
{

    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;



};

//打印树结点
void PrintTreeNode(BinaryTreeNode *pNode)
{
    if (pNode != NULL)
    {
        printf("value of this node is : %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != NULL)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");
        if (pNode->m_pRight != NULL)
            printf("value of its right childe is : %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {

        printf("this node is null.\n");

    }
    printf("\n");
}
void PrintTree(BinaryTreeNode *pRoot)
{
    PrintTreeNode(pRoot);
    //   
    if (pRoot != NULL)
    {
        if (pRoot->m_pLeft != NULL)
            PrintTree(pRoot->m_pLeft);
        if (pRoot->m_pRight != NULL)
            PrintTree(pRoot->m_pRight);
    }
}

/*
preorder 前序遍历
inorder 中序遍历

*/

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
BinaryTreeNode *Construct(int *preorder, int *inorder, int length)//输入前序序列，中序序列和序列长度
{
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);

}

// startPreorder 前序遍历的第一个节点  
// endPreorder   前序遍历的最后后一个节点  
// startInorder  中序遍历的第一个节点  
// startInorder  中序遍历的最后一个节点  

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    // 前序遍历序列的第一个数字是根结点的值  
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    
    // 只有一个结点
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input.");
    }

    //有多个结点
    // 在中序遍历中找到根结点的值  
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input");
    //  
    int leftLength = rootInorder - startInorder;    //中序序列的左子树序列长度
    int *leftPreorderEnd = startPreorder + leftLength;    //左子树前序序列的最后一个结点
    if (leftLength > 0)
    {
        // 构建左子树  
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder)    //（中序序列）若还有左子树，则左子树序列长度应等于当前前序序列的长度
        //若小于，说明已无左子树，此时建立右子树
    {
        // 构建右子树  
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    //  
    return root;
}

// 测试代码  
void Test(char *testName, int *preorder, int *inorder, int length)
{
    if (testName != NULL)
        printf("%s Begins:\n", testName);
    printf("The preorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is:");
    for (int i = 0; i < length; ++i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode *root = Construct(preorder, inorder, length);
        PrintTree(root);

    }
    catch (std::exception &expection)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树  
//              1  
//           /     \  
//          2       3    
//         /       / \  
//        4       5   6  
//         \         /  
//          7       8  
void Test1()
{
    const int length = 8;
    int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    Test("Test1", preorder, inorder, length);
}

int main()
{
    Test1();  
    system("pause");
    return 0;
}

/*
输出结果：
----------------------------------------------------------------
Test1 Begins:
The preorder sequence is: 1 2 4 7 3 5 6 8
The inorder sequence is:4 7 2 1 5 3 8 6
value of this node is : 1
value of its left child is: 2.
value of its right childe is : 3.

value of this node is : 2
value of its left child is: 4.
right child is null.

value of this node is : 4
left child is null.
value of its right childe is : 7.

value of this node is : 7
left child is null.
right child is null.

value of this node is : 3
value of its left child is: 5.
value of its right childe is : 6.

value of this node is : 5
left child is null.
right child is null.

value of this node is : 6
value of its left child is: 8.
right child is null.

value of this node is : 8
left child is null.
right child is null.

*/
/*
容器+递归
*/

#include <iostream>
#include <vector>
using namespace std;


// Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/* 先序遍历第一个位置肯定是根节点node，

中序遍历的根节点位置在中间p，在p左边的肯定是node的左子树的中序数组，p右边的肯定是node的右子树的中序数组

另一方面，先序遍历的第二个位置到p，也是node左子树的先序子数组，剩下p右边的就是node的右子树的先序子数组

把四个数组找出来，分左右递归调用即可

*/

class Solution {

public:

    struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {

        int in_size = in.size();//获得序列的长度

        if (in_size == 0)

            return NULL;

        //分别存储先序序列的左子树，先序序列的右子树，中序序列的左子树，中序序列的右子树
        vector<int> pre_left, pre_right, in_left, in_right;

        int val = pre[0];//先序遍历第一个位置肯定是根节点node,取其值
        //新建一个树结点，并传入结点值
        TreeNode* node = new TreeNode(val);//root node is the first element in pre
        //p用于存储中序序列中根结点的位置
        int p = 0;

        for (p; p < in_size; ++p){

            if (in[p] == val) //Find the root position in in 

                break;        //找到即跳出for循环

        }

        for (int i = 0; i < in_size; ++i){

            if (i < p){
                //建立中序序列的左子树和前序序列的左子树
                in_left.push_back(in[i]);//Construct the left pre and in 

                pre_left.push_back(pre[i + 1]);//前序第一个为根节点,+1从下一个开始记录

            }

            else if (i > p){
                //建立中序序列的右子树和前序序列的左子树
                in_right.push_back(in[i]);//Construct the right pre and in 

                pre_right.push_back(pre[i]);

            }

        }
        //取出前序和中序遍历根节点左边和右边的子树
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        node->left = reConstructBinaryTree(pre_left, in_left);

        node->right = reConstructBinaryTree(pre_right, in_right);

        return node;

    }

};