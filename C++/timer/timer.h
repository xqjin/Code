#include <sys/time.h>

/*
 *  ¼ÆÊ±º¯Êý
 *
 */

class StopWatch
{
    struct timeval _start;
    struct timeval _end;

public:
    StopWatch()
    {
    }

    StopWatch(bool start)
    {
        if (start)
        {
            gettimeofday(&_start, NULL);
        }
    }

    void start()
    {
        gettimeofday(&_start, NULL);
    }

    void stop()
    {
        gettimeofday(&_end, NULL);
    }

    double elapsed()
    {
        gettimeofday(&_end, NULL);
        return _end.tv_sec - _start.tv_sec + (double)(_end.tv_usec - _start.tv_usec) / 1e6; 
    }
};
