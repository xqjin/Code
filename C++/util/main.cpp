#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>
#include<ext_string.h>

using namespace std;

int main(int argc, char * argv[]) {
    vector<string> vec;
    string s = "jin";
    splitString(s, " ", vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}
