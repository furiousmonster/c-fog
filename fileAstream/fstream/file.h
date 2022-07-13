//
// Created by hlz on 2021/9/30.
//

#ifndef CPP_FILE_H
#define CPP_FILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class file {
private:
    fstream f;
public:

    void fwrite(vector<string>& v) {

        f.open("test.txt", ios::out);

        for (const string s : v) {
            // const char* p = s.c_str();
            // f.write(p, s.size());
            f << s << endl;
        }

        f.close();
    }


    void fread() {
        f.open("test.txt", ios::in);

        string buf;
        while (getline(f, buf)) {
            cout << buf << endl;
        }
        f.close();
    }
};


#endif //CPP_FILE_H
