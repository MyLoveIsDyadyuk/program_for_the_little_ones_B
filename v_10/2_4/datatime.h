#include <iostream>

class Time
{
private:
    friend std::ostream &operator<<(std::ostream &os, Time &val);

    int hour;
    int min;
    int sec;

public:
    Time(/* args */);
    Time(int hour, int min, int sec);
    Time(const Time &Time);
    Time &operator=(const Time &Time);
    Time(Time &&other);
    Time &operator=(Time &&other);
    ~Time();

    int get_hour() { return hour; }
    int get_min() { return min; }
    int get_sec() { return sec; }

    void set_hour(int temp);
    void set_min(int temp);
    void set_sec(int temp);

    void add_sec(int sec);
    void back_sec(int sec);

    Time &operator-(Time &value);
    Time &operator+(Time &value);
};

Time::Time(/* args */)
{
    hour = min = sec = 0;
}

Time::Time(int temp_h, int temp_m, int temp_s)
{
    if (temp_h >= 24)
        throw std::out_of_range("Incorrect time.");
    hour = temp_h;

    if (temp_m >= 60)
        throw std::out_of_range("Incorrect time.");
    min = temp_m;

    if (temp_s >= 60)
        throw std::out_of_range("Incorrect time.");
    sec = temp_s;
}

// copy
Time::Time(const Time &copy_time)
{
    hour = copy_time.hour;
    min = copy_time.min;
    sec = copy_time.sec;
}

Time &Time::operator=(const Time &copy_time)
{
    hour = copy_time.hour;
    min = copy_time.min;
    sec = copy_time.sec;

    return *this;
}

// move
Time::Time(Time &&other)
{
    hour = other.hour;
    min = other.min;
    sec = other.sec;

    other.hour = 0;
    other.min = 0;
    other.sec = 0;
}

Time &Time::operator=(Time &&other)
{
    this->~Time();

    hour = other.hour;
    min = other.min;
    sec = other.sec;

    other.hour = 0;
    other.min = 0;
    other.sec = 0;

    return *this;
}

Time::~Time()
{
    delete[] this;
}

void Time::set_hour(int temp_h)
{
    if (temp_h >= 24)
        throw std::out_of_range("Incorrect time.");

    hour = temp_h;
}

void Time::set_min(int temp_m)
{
    if (temp_m >= 60)
        throw std::out_of_range("Incorrect time.");

    min = temp_m;
}

void Time::set_sec(int temp_s)
{
    if (temp_s >= 60)
        throw std::out_of_range("Incorrect time.");

    sec = temp_s;
}

void Time::add_sec(int temp_s)
{
    int temp_m = temp_s / 60;
    int temp_h = temp_m / 60;
    sec += temp_s % 60;

    if (temp_m >= 60)
        temp_m = temp_m / 60;

    if (sec > 60)
    {
        sec = sec - 60;
        min++;
    }

    min += temp_m;
    hour += temp_h;
}

void Time::back_sec(int temp_s)
{
    int temp_m = temp_s / 60;
    int temp_h = temp_m / 60;

    sec -= temp_s % 60;

    if (temp_m >= 60)
    { 
        hour += temp_h;
        if (hour >= 24) 
            hour = 24 - hour;
    }

    // if (temp_m >= 60)
    // {
    //     min -= temp_m % 60;
    //     if (min < 0)
    //     { 
    //         hour--;
    //         min = 60 - 
    //     }
    //     temp_m += temp 60;
    // }

    // if (sec < 0)
    // {
    //     min--;
    //     sec = 60 + sec;
    // }

    // hour -= temp_h;
    // temp_m -= temp_m;
}

Time &Time::operator+(Time &value)
{
    Time *temp = new Time;

    temp->hour = hour + value.get_hour();
    if (temp->hour >= 24)
        temp->hour = 24 - hour + value.get_hour();

    temp->min = min + value.get_min();
    if (temp->min >= 60)
    {
        temp->min = 60 - min + value.get_min();
        temp->hour++;
    }

    if (temp->sec >= 60)
    {
        temp->sec = 60 - sec + value.get_sec();
        temp->min++;
    }

    return *temp;
}

Time &Time::operator-(Time &value)
{
    Time *temp = new Time;
    temp->hour = hour - value.get_hour();
    if (temp->hour < 0)
        temp->hour = value.get_hour() - hour;

    temp->min = min - value.get_min();
    if (temp->min < 0)
    {
        temp->min = value.get_min() - min;
        temp->hour--;
    }

    temp->sec = sec - value.get_sec();
    if (temp->min < 0)
    {
        temp->sec = value.get_sec() - sec;
        temp->min--;
    }

    return *temp;
}

int Timer(Time &begin, Time &end)
{
    int temp = end.get_sec() - begin.get_sec();
    return temp;
}

std::ostream &operator<<(std::ostream &os, Time &value)
{
    if (value.get_hour() < 10)
        os << '0' << value.get_hour() << '.';
    else
        os << value.get_hour() << '.';

    if (value.get_min() < 10)
        os << '0' << value.get_min() << '.';
    else
        os << value.get_min() << '.';

    if (value.get_sec() < 10)
        os << '0' << value.get_sec();
    else
        os << value.get_sec();
}
