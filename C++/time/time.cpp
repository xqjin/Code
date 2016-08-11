#include<ctime>
#include<iostream>

using namespace std;

int main() {

    time_t long_time;
    time(&long_time);
    struct tm *tm_time = localtime(&long_time);

    int h = tm_time->tm_hour;
    int m = tm_time->tm_min;
    std::cout<< h << std::endl;
    return 0;
}
