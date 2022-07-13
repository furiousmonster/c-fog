#include "../zzhlz/baseStructure/hlzBase.h"
#include "../zzhlz/baseStructure/hlzstring.h"
#include "../zzhlz/baseStructure/hlzlistNode.h"
#include "../zzhlz/baseStructure/hlztree.h"
#include "../zzhlz/baseStructure/hlzGrapth.h"
#include "hlzstkque.h"

#include <iostream>

using namespace std;

class testString {
private:
  seniorStringFunc sestr;
  string str;

public:
  void testStringSplit() {
    string str = "I am HLZ";
    vector<string> v = split(str);

    for (auto& s : v) {
      cout<<s<<endl;
    }
  }

  void testStrReverseSplit() {
    str = "aabbccdc";
    sestr.splitReverse(str);
  }

};


class testStk {
private:


public:



};


class testTree {
private:
  TreeNode* root;
  BuildTree build;
  Traversal traverse;
  TreeUtils utils;

private:
  vector<int> preOrder;
  vector<int> inOrder;
  vector<int> postOrder;
  string serial;

public:
  void printTreeInOrder() {
    vector<int> inOr = traverse.inorderTraversal(root);
    printOneDVector(inOr);
  }


  void testTreeBuild() {
    /**
     *     1
     *    / \
     *   2   3
     *  / \ / \
     * 4  5 6  7
     * 
     * 
     */ 
    // preOrder = {1, 2, 4, 8, 3, 6, 7};
    // inOrder = {4, 2, 8, 1, 6, 3, 7};

    /**
     *        1
     *       / \
     *      2   3
     *         / \
     *        4   5
     *       /     \
     *      6       7
     *     /         \
     *    8           9
     */
    preOrder = {1, 2, 3, 4, 6, 8, 5, 7, 9};
    inOrder = {2, 1, 8, 6, 4, 3, 5, 7, 9}; 
    root = build.buildTree(preOrder, inOrder);
  }


  void testTreeSerialize() {
    serial = build.serialize(root);
    cout<<serial<<endl;
  }

  void testTreeDeserialize() {
    root = build.deserialize(serial);
  }


  void testTreeSumPath() {
    vector<vector<int>> ress = utils.pathSum(this->root, 11);
    printTwoDVector(ress);
  }


  void testTreePathIncludeNode() {
    vector<vector<int>> ress = utils.pathIncludeNode(this->root, 7);
    printTwoDVector(ress);
  }

  void testTreeAllPath() {
    traverse.allPath(root);
  }

  void testTreeMaxLenRoutes() {
    utils.maxLenRoutes(root);
  }

  void testTreeMaxDiameter() {
    utils.maxLenDiameter(root);
  }

};


class testGrapth {
private:
  Graph G;
  vector<vector<int>> edges;
  int N;
  string vertexs;

public:

  void initG() {
    /**
     * E--A--B
     * |  |  |
     * D--C---
     */ 
    // N = 5;
    // vertexs = "ABCDE";

    // edges = {
    //   {0, 1, 1, 0, 1},
    //   {1, 0, 1, 0, 0},
    //   {1, 1, 0, 1, 0},
    //   {0, 0, 1, 0, 1},
    //   {1, 0, 0, 1, 0}
    // };

    /**
     *      A
     *     / \
     *    B---C
     *   / \ / \
     *  D---E---F
     * 
     * 
     */ 
    N = 6;
    vertexs = "ABCDEF";
    edges = {
      {0, 1, 1, 0, 0, 0},
      {1, 0, 1, 1, 1, 0},
      {1, 1, 0, 0, 1, 1},
      {0, 1, 0, 0, 1, 0},
      {0, 1, 1, 1, 0, 1},
      {0, 0, 1, 0, 1, 0}
    };
  }

  void constructG() {
    initG();
    G.setGraph(N, vertexs, edges);
  }


  void testGrapthDfs() {
    G.DFSTraverse();
  }

  void testGrapthFindCircle() {
    G.findAllCircle();
  }

};




int main(int argc, char *argv[]) {
  
  // 测试分割字符串
  // testString* test = new testString;
  // test->testStringSplit();
  // testString test;
  // test.testStringSplit();


  // 测试分割回文串
  // testString ts;
  // ts.testStrReverseSplit();


  // 测试构建二叉树
  // testTree t;
  // t.testTreeBuild();
  // t.printTreeInOrder();

  // tree t;
  // vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
  // vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
  // t.testTreeBuild(preOrder, inOrder);
  // t.printTreeInOrder();


  // 测试二叉树序列化和反序列化
  // testTree t;
  // t.testTreeBuild();
  // t.testTreeSerialize();
  // t.testTreeDeserialize();
  // t.printTreeInOrder();

  // 和为某一值路径
  // testTree t;
  // t.testTreeBuild();
  // t.printTreeInOrder();
  // t.testTreeSumPath();


  // 根到所有叶子节点的路径
  // testTree t;
  // t.testTreeBuild();
  // t.testTreeAllPath();


  // 到某个节点的路径
  // testTree t;
  // t.testTreeBuild();
  // t.testTreePathIncludeNode();



  // 最长路径 / 直径
  // testTree t;
  // t.testTreeBuild();
  // // t.testTreeMaxLenRoutes(); //路径
  // t.testTreeMaxDiameter();

  // 图的构造与遍历
  // testGrapth tG;
  // tG.constructG();
  // tG.testGrapthDfs(); //测试遍历
  // tG.testGrapthFindCircle(); 




  return 0;
}