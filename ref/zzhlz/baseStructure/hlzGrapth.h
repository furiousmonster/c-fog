#ifndef HLZGRAPTH_H
#define HLZGRAPTH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;



// 图的结构
class Graph {
private:
  int Nvertexs = 5; //图顶点数量
  string gvertexs; //图顶点
  vector<vector<int>> gedges;  //邻接矩阵
  int numConnetedGraph; //连通图数量
  
  vector<int> visited; //访问过顶点
  int numCircle; //环数量
  string route;
  vector<string> routes;

public:
  Graph() {};
  
  Graph(int N, string vertexs, vector<vector<int>> edges) : Nvertexs(N), gvertexs(vertexs), gedges(edges) {
    cout<<"图构造完成"<<endl;
  };

  void setGraph(int N, string vertexs, vector<vector<int>> edges) {
    cout<<"set完成" << endl;
    Nvertexs = N;
    gvertexs = vertexs;
    gedges = edges;
    initVisted();
  }


  // 初始化visited矩阵
  void initVisted() {
    visited.resize(Nvertexs);
    for (int& i : visited) {
      i = 0;
    }
  }


  /**
   * 深度优先搜索遍历图
   */ 
  void DFS(int i) {
    int j = 0;
    visited[i] = 1;
    // 操作顶点i
    cout<<"访问了顶点"<<gvertexs[i]<<endl;

    for (j = 0; j < Nvertexs; j++) {
      if (gedges[i][j] == 1 && !visited[j]) {
        DFS(j);
      }
    }
  }

  void DFSTraverse() {
    int i;
    for (i = 0; i < Nvertexs; i++) {
      // 对未访问的节点执行dfs, 连通图只执行一次
      if (!visited[i]) DFS(i);
    }
  }


  /**
   * 找到无向图所有环
   * 
   * 
   */ 
  void DFS2(int i, int lastVisited) {
    int j = 0;
    visited[i] = 1;

    if (i == 0) {
      cout << "开始访问第一个顶点" << endl;
      route += gvertexs[i];
    } else {
      // 操作顶点i
      cout << "上次访问的顶点是" << gvertexs[lastVisited] << endl;
      cout << "访问了顶点" << gvertexs[i] << endl;
      route += gvertexs[i];
    }


    for (j = 0; j < Nvertexs; j++) {
      cout << "正在查找顶点" << gvertexs[i] << "相邻路径" << endl;
      if (gedges[i][j] == 1 && visited[j] && lastVisited != j) {
        cout << "遇到了已访问顶点" << gvertexs[j] << endl;

        // numCircle++;
        // cout << "环的数目为" << numCircle << endl;

        route += gvertexs[j];
        routes.emplace_back(route);
        route.pop_back();
      } else if (gedges[i][j] == 1 && !visited[j]) {
        cout << "继续访问顶点" << gvertexs[j] << endl;
        int tmp = lastVisited;
        lastVisited = i;
        DFS2(j, lastVisited);
        lastVisited = tmp;
      } else {
        continue;
      }
    }
  }

  void clearRoutes() {

    // 删除最后一条回路ABCDEE
    // vector<string>::iterator iter;
    // iter = routes.begin();
    // while (iter != routes.end()) {
    //   string str = *iter;
    //   for (int i = 1; i < str.size(); i++) {
    //     if (str[i] == str[i - 1]) {
    //       iter = routes.erase(iter); //erase迭代器失效，但会返回下一个有效的iter
    //     } else {
    //       ++iter;
    //     }
    //   }
    // }

    routes.pop_back();
    for (string& str : routes) {
      char joinC = str[str.size() - 1];
      int start = str.find(joinC);
      str = str.substr(start);
    }
    numCircle = routes.size();

  }

  void findAllCircle() {
    numConnetedGraph = 0;
    numCircle = 0;
    
    for (int i = 0; i < Nvertexs; i++) {
      if (!visited[i]) {
        numConnetedGraph++; //每循环一次，连通图数目加1
        DFS2(i, 0);
      }
    }

    clearRoutes();
    cout << "连通图数目是" << numConnetedGraph << endl;
    cout << "环数目是" << numCircle << endl;
    for (string& str : routes) {
      cout<<"环路为"<<endl;
      cout<<str<<endl;
    }
  }


};



class topologicalOrder {
private:
  vector<vector<int>> prerequisites;

public:

  void initG(vector<vector<int>>& prerequisites) {
    /**
     * 0-1-2
     * | \ /
     * 6  3-4 5
     * 
     */ 
    prerequisites = {
      {0, 1},
      {1, 2},
      {1, 3},
      {2, 3},
      {3, 4},
      {0, 6}
    };
  }


  vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int>> edges(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0); //indegree[1] = 1 学课程1前置有一个课程没学
    vector<int> res;

    for (const auto &p : prerequisites) {
      edges[p[0]].push_back(p[1]); // 0 :1, 6 ; 1 :2,3 ;2:3;3:4;
      ++indegree[p[1]]; //indegree[1]=1
    }

    queue<int> que;
    // 初始化队列，将为0的数据放入
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i] == 0) que.push(i);
    }

    while (!que.empty()) {
      int abledCourse = que.front();
      res.push_back(abledCourse);
      que.pop();

      for (auto linkedCourse : edges[abledCourse]) {
        --indegree[linkedCourse];
        if (!indegree[linkedCourse]) {
          que.push(linkedCourse);
        }
      }
    }

    // 检查是否有课程没学完
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i]) {
        return vector<int>();
      }
    }

    return res;
  }
};





#endif