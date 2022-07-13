#ifndef HLZARRAY_H
#define HLZARRAY_H

#include <vector>
#include <array>
// #include <


// 矩阵乘法
vector<vector<int>> matmul(vector<vector<int>>& A, vector<vector<int>>& B) {
  int nA = A.size(), mA = A[0].size();
  int nB = B.size(), mB = B[0].size();
  if (nA == 0 || nB == 0 || mA != nB) return {};

  vector<vector<int>> res(nA, vector<int>(mB));
  for (int i = 0; i < nA; i++) {
    for (int j = 0; j < mB; j++) {
      for (int k = 0; k < mA; k++) {
        res[i][j] += A[i][k] * B[k][j];
      }
      
    }
  }

  return res;
}



#endif