#include<ext_string.h>

using namespace std;

int splitString(
    const string & input, 
    const string & pattern, 
    vector<string>& result) {

    std::string::size_type pos;
    string str = input + pattern;
    int size = str.size();

    for (int i = 0; i < size; i++) {
        pos = str.find(pattern, i);
        if (pos < size) {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return 0;
}
