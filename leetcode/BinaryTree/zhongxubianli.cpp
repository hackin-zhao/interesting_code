#include <iostream>
#include <vector>
#include <stack>
#include <functional>

// 给定一个二叉树的根节点 root ，返回它的 中序 遍历。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, std::vector<int> &res)
    {
        if (!root)
            return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }
};

class Solution1
{
public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode *> stk;
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

class Solution2
{
public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root)
                {
                    predecessor = predecessor->right;
                }

                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else
                {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else
            {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

class SolutionLamda
{
public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::function<void(TreeNode * root)> f;

        f = [&f, &res](TreeNode *root)
        {
            if (!root)
                return;

            f(root->left);
            res.push_back(root->val);
            f(root->right);
        };

        f(root);

        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode n3(3);
    TreeNode n2(2, &n3, nullptr);
    TreeNode root(1, nullptr, &n2);

    Solution s;
    Solution1 s1;
    Solution2 s2;
    SolutionLamda lamda;

    std::cout << "*********** Solution ***************" << std::endl;
    std::vector<int> result = s.inorderTraversal(&root);
    for (auto &p : result)
        std::cout << p << " ";
    std::cout << std::endl;

    std::cout << "*********** Solution1 ***************" << std::endl;
    std::vector<int> result1 = s1.inorderTraversal(&root);
    for (auto &p : result1)
        std::cout << p << " ";
    std::cout << std::endl;

    std::cout << "*********** Solution2 ***************" << std::endl;
    std::vector<int> result2 = s2.inorderTraversal(&root);
    for (auto &p : result2)
        std::cout << p << " ";
    std::cout << std::endl;

    std::cout << "*********** SolutionLamda ***************" << std::endl;
    std::vector<int> result_lamda = lamda.inorderTraversal(&root);
    for (auto &p : result_lamda)
        std::cout << p << " ";
    std::cout << std::endl;

    return 0;
}
