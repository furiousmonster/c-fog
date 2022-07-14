#include <iostream>
#include <vector>
#include <string>
#include "file.h"

using namespace std;

int main() {
    vector<string> vs = {
        "apple",
        "pear",
        "peach",
        "watermelon",
        "strawberry",
        "APPLE"
    };

    file f;
    f.fwrite(vs);
    f.fread();


    return 0;
}
