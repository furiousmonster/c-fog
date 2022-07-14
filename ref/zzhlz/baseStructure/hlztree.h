#ifndef HLZTREE_H
#define HLZTREE_H

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;


/**
 * 数据结构TreeNode
 */ 
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class TreeUtils {
private:
  vector<vector<int>> ret;
  vector<int> path;

  int maxDiameter;

public:
  int maxDepth(TreeNode* root) {
    // 树的最大深度
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  /**
   * 和为某一值的路径
   * 
   */ 
  void dfs(TreeNode* root, int target) {
    if (root == nullptr) {
      return;
    }
    
    path.emplace_back(root->val);
    target -= root->val;
    
    if (root->left == nullptr && root->right == nullptr && target == 0) {
      ret.emplace_back(path);
    }
    dfs(root->left, target);
    dfs(root->right, target);
    
    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int target) {
    ret.clear();
    path.clear();
    dfs(root, target);
    return ret;
  }


  /**
   * 包含某一节点的路径
   * 
   */ 
  void dfs2(TreeNode* root, int target) {
    if (root == nullptr) return;

    path.emplace_back(root->val);
    if (root->val == target) {
      ret.emplace_back(path);
    }

    dfs2(root->left, target);
    dfs2(root->right, target);
    
    path.pop_back();
  }

  vector<vector<int>> pathIncludeNode(TreeNode* root, int target) {
    ret.clear();
    path.clear();
    dfs2(root, target);
    return ret;
  }


  /**
   * 最长路径
   */
  void findLongestPath(TreeNode* root) {
      path.push_back(root->val);
      if (root->left == NULL && root->right == NULL)
          return;

      if (maxDepth(root->left) >= maxDepth(root->right)) {
        findLongestPath(root->left);
      } else {
        findLongestPath(root->right);
      }
  }

  void maxLenRoutes(TreeNode* root) {
    path.clear();
    findLongestPath(root);
    printOneDVector(path);
  }


  /**
   * 最长直径
   * 
   * 
   */ 
  void findLongestDiameter(TreeNode* root) {
    path.clear();

    if (!root->left && !root->right) return;

    int diameter = 0;
    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    diameter = lDepth + rDepth + 1;
    if (diameter > maxDiameter) {
      maxDiameter = diameter;

      findLongestPath(root->left);
      path.emplace_back(root->val);
      findLongestPath(root->right);

      reverse(path.begin(), path.begin() + lDepth);
    }

    if (lDepth > rDepth) {
      findLongestDiameter(root->left);
    } else if (lDepth < rDepth) {
      findLongestDiameter(root->right);
    } else {
      // 一样长，子节点一定没有更长的？
      return;
    }

  }

  void maxLenDiameter(TreeNode* root) {
    maxDiameter = 0;
    path.clear();

    findLongestDiameter(root);
    cout << "max Diameter is " << maxDiameter << endl;
    printOneDVector(path);
  }


};




class BuildTree {
/**
 * 构建树的类
 */ 
private:
    unordered_map<int, int> index;

public:
  /**
   * 从先序和中序遍历构造二叉树。不能有重复值
   * @params: preorder: 先序遍历
   *          inorder: 中序遍历
   * @return: 返回root
   */ 
  TreeNode* buildTreeByPreIn(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    if (preorder_left > preorder_right) {
        return nullptr;
    }
    
    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = index[preorder[preorder_root]];
    
    // 先把根节点建立出来
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = buildTreeByPreIn(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right = buildTreeByPreIn(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
    }
    return buildTreeByPreIn(preorder, inorder, 0, n - 1, 0, n - 1);
  }


  /**
   * 先序遍历序列化, 树到string
   * @params: root
   * @return: 返回root
   */
  string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "#";
    }
    string leftStr = serialize(root->left);
    string rightStr = serialize(root->right);
    return to_string(root->val) + "," + leftStr + "," + rightStr;
  }


  TreeNode* dfs(vector<string>& strs, int &i) {
    string str = strs[i];
    i++;
    if (str == "#") {
        return nullptr;
    }

    TreeNode* node = new TreeNode(stoi(str));
    node->left = dfs(strs, i);
    node->right = dfs(strs, i);
    return node;
  }


  /**
   * 反序列化, string到树
   * @params: string
   * @return: 返回root
   */
  TreeNode* deserialize(string data) {
    // 分割字符串
    vector<string> dataArray{""};
    for (auto& ch : data) {
      if (ch == ',') {
        dataArray.push_back("");
      } 
      else {
        dataArray.back().push_back(ch);
      }
    }
    int i = 0;
    return dfs(dataArray, i);
  }


};


class Traversal {
private:
  vector<int> path;


/**
 * 遍历树的类
 */ 
public:
  void inorder(TreeNode* root, vector<int>& res) {
    if(!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }


  // 输出根到叶子的所有路径
  void allPath(TreeNode* root) {
    if (root == nullptr) return;

    cout << "加入了节点" << root->val << endl;
    path.emplace_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
      cout << "得到了路径" << endl;
      printOneDVector(path);
    }

    allPath(root->left);
    allPath(root->right);

    cout << "剔除了节点" << root->val << endl;
    path.pop_back();

  }
};



class tree {
private:
  TreeNode* root;
  BuildTree build;
  Traversal traverse;

public:
  void printPre() {
    // 打印二叉树
    vector<int> inOr = traverse.inorderTraversal(root);
    printOneDVector(inOr);
  }


  void testTreeBuild(vector<int>& preOrder, vector<int>& inOrder) {
    // 从先序和中序构造二叉树
    root = build.buildTree(preOrder, inOrder);
  }
};


#endif