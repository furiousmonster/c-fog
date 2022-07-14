#ifndef HLZSTRING_H
#define HLZSTRING_H

#include <vector>
#include <string>

using namespace std;



/**
 * 分割字符串到vector中
 * @params: const string &str: 待分割字符串
 *          string ch: 分割符号
 * @return: 返回分割后的vector
 */ 
vector<string> split(const string &str, string ch = " ") {
	//以 ch 为分割字符，把 cstr 分割为多个元素存到vector
	vector<string> ret;
	int pos = 0;
	int start = 0;
  //查找字符串a是否包含子串b,而是 strA.find(strB) != string:npos
	while ((pos = str.find(ch, start)) != string::npos ) {
		//cout << "pos:" << pos << endl;
		if (pos > start) {
      ret.push_back(str.substr(start, pos-start));
    }
		start = pos + ch.size();
	}
	if (str.size() > start)  {
    ret.push_back(str.substr(start));
  }
	return ret;
}

class seniorStringFunc {
private:
	vector<string> res;
	vector<vector<string>> ress;
	vector<vector<int>> f;
	int n;

public:
	/**
	 * 分割回文串
	 * 回溯！！！
	 * 
	 */ 
	bool isReverse(string& str, int i, int j) {
		while (i < j) {
			if (str[i] != str[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	void isReverseDp(string& str) {
		int n = str.size();
		f.assign(n, vector<int>(n, true));

		for (int i = n - 1; i >= 0; --i) {
				for (int j = i + 1; j < n; ++j) {
						f[i][j] = (str[i] == str[j]) && f[i + 1][j - 1];
				}
		}
	}


  void dfs(string& str, int i) {
		if (i == str.size()) {
			ress.emplace_back(res);
			return;
		}

		for (int j = i; j < str.size(); j++) {
			if (isReverse(str, i, j)) {
			// if (f[i][j]) {
				res.emplace_back(str.substr(i, j - i + 1));
				dfs(str, j + 1);
				res.pop_back();
			}
		}
	}

	void splitReverse(string& str) {
		res.clear();
		ress.clear();

		// isReverseDp(str);

		dfs(str, 0);

		cout << "所有的回文串" << endl;
		printTwoDVector(ress);
	}


};






#endif