#ifndef H_CLOCK
#define H_CLOCK

class Clock
{
    Clock(Clock &) = delete;
    Clock & operator=(const Clock &) = delete;

private:
    int seconds;
    int minutes;
    int hours;
    static Clock * instance;
    Clock();
    ~Clock();

public:
    static Clock * getInstance();
    void setTime(int, int, int);
    void readTime();
};

#endif