#include <iostream>
#include "timer.h"

using namespace std;

int main(int argc, char ** argv)
{
    StopWatch stop_watch(true);
    cout << "Hello World" << endl;
    int k = 0;
    for (int i = 0; i < 1000; i++)
    {
        //do nothing
        k += 12;
    }
    double elapse = stop_watch.elapsed();
    cout << elapse << endl;
    return 0;
}
