#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct date
{
    int month;
    int day;
    int year;
};

struct time
{
    int hour;
    int minute;
    int second;
} time;

int f(int year, int month)
{
    if (month <= 2)
        return year - 1;
    else
        return year;
}

int g(int month)
{
    if (month <= 2)
        return month + 13;
    else
        return month + 1;
}

int n(struct date date_to_n)
{
    int n = 1461 * f(date_to_n.year, date_to_n.month) / 4 + 153 * g(date_to_n.month) / 5 + date_to_n.day;
    return n;
}

int days_between(struct date date1, struct date date2)
{
    int n1 = n(date1);
    int n2 = n(date2);
    return n2 - n1;
}

void exec_2(void)
{
    printf("######## Exec 2 ######## \n");
    int month, day, year;
    printf("Enter month day1: \n");
    scanf("%i", &month);
    printf("Enter day day1: \n");
    scanf("%i", &day);
    printf("Enter year day1: \n");
    scanf("%i", &year);
    struct date date1 = {month, day, year};

    printf("Enter month day2: \n");
    scanf("%i", &month);
    printf("Enter day day2: \n");
    scanf("%i", &day);
    printf("Enter year day2: \n");
    scanf("%i", &year);
    struct date date2 = {month, day, year};

    printf("There are %i days between %i/%i/%i and %i/%i/%i \n", days_between(date1, date2), date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
}

bool check(struct time time_value)
{
    if (time_value.hour < 0 || time_value.hour > 23)
        return 0;
    if (time_value.minute < 0 || time_value.minute > 59)
        return 0;
    if (time_value.second < 0 || time_value.second > 59)
        return 0;
    return 1;
}

struct time elapser_time(struct time time1, struct time time2)
{
    int hour = 0, min = 0, sec = 0;
    if (check(time1) && check(time2))
    {

        if (time2.second >= time1.second)
            sec = time2.second - time1.second;
        else
        {
            sec = 60 + time2.second - time1.second;
            min--;
        }

        if (time2.minute >= time1.minute)
            min += time2.minute - time1.minute;
        else
        {
            min += 60 + time2.minute - time1.minute;
            hour--;
        }
        if (time2.hour >= time1.hour)
            hour += time2.hour - time1.hour;
        else
            hour += 24 + time2.hour - time1.hour;
        if (hour < 0)
            hour += 24;

        struct time result = {hour, min, sec};
        return result;
    }
    else
    {
        printf("Wrong format of timeer");
        struct time result = {0, 0, 0};
        return result;
    }
}

void exec_3(void)
{
    struct time time_1, time_2;
    time_1 = (struct time){.hour = 13, .minute = 01, .second = 0};
    time_2 = (struct time){.hour = 13, .minute = 00, .second = 0};

    struct time result = elapser_time(time_1, time_2);
    printf("Elapser time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i is %.2i:%.2i:%.2i \n", time_1.hour, time_1.minute, time_1.second, time_2.hour, time_2.minute, time_2.second, result.hour, result.minute, result.second);

    time_1 = (struct time){13, 01, 00};
    time_2 = (struct time){13, 01, 01};

    result = elapser_time(time_1, time_2);
    printf("Elapser time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i is %.2i:%.2i:%.2i \n", time_1.hour, time_1.minute, time_1.second, time_2.hour, time_2.minute, time_2.second, result.hour, result.minute, result.second);

    time_1 = (struct time){13, 00, 00};
    time_2 = (struct time){13, 01, 00};

    result = elapser_time(time_1, time_2);
    printf("Elapser time between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i is %.2i:%.2i:%.2i \n", time_1.hour, time_1.minute, time_1.second, time_2.hour, time_2.minute, time_2.second, result.hour, result.minute, result.second);
}

struct day_of_week
{
    char *day_name;
};

struct day_of_week get_day_of_week(struct date date_value)
{
    int day_in_int = (n(date_value) - 621049) % 7;
    switch (day_in_int)
    {
    case 0:
        return (struct day_of_week){"Sunday"};
    case 1:
        return (struct day_of_week){"Monday"};
    case 2:
        return (struct day_of_week){"Tuesday"};
    case 3:
        return (struct day_of_week){"Wenesday"};
    case 4:
        return (struct day_of_week){"Thursday"};
    case 5:
        return (struct day_of_week){"Friday"};
    case 6:
        return (struct day_of_week){"Saturday"};
    }
}

void exec4(void)
{
    printf("######### Exec 4 ######## \n");
    struct date today = {10, 29, 2023};
    printf("Today is %s \n", get_day_of_week(today).day_name);
}

struct dateAndTime
{
    struct date today;
    struct time now;
    struct day_of_week dow;
};

struct date dateUpdate(struct date today)
{
    struct date tomorrow;
    int numberOfDays(struct date d);
    if (today.day != numberOfDays(today))
        tomorrow = (struct date){.day = today.day + 1, .month = today.month, .year = today.year};
    else if (today.month == 12)
        tomorrow = (struct date){.day = 1, .month = 1, .year = today.year + 1};
    else
        tomorrow = (struct date){.day = 1, .month = today.month + 1, .year = today.year};

    return tomorrow;
}
int numberOfDays(struct date d)
{
    int days;
    bool isLeapYear(struct date d);
    const int daysPerMonth[12] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(d) && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month - 1];
    return days;
}

bool isLeapYear(struct date d)
{
    bool leapYearFlag;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        leapYearFlag = true; // It's a leap year else
    leapYearFlag = false;    // Not a leap year
    return leapYearFlag;
}

struct time timeUpdate(struct time now)
{
    ++now.second;
    if (now.second == 60)
    { // next minute
        now.second = 0;
        ++now.minute;
        if (now.minute == 60)
        { // next hour
            now.minute = 0;
            ++now.hour;
        }
        if (now.hour == 24)
        { // next hour
            now.hour = 0;
        }
    }
    return now;
}

struct dateAndTime clockKeeper(struct dateAndTime current)
{
    current.now = timeUpdate(current.now);
    if (current.now.hour == 0 && current.now.hour == 0 && current.now.hour == 0)
    {
        current.today = dateUpdate(current.today);
        current.dow = get_day_of_week(current.today);
    }
    return current;
}

void exec5_and_6(void)
{
    printf("######## Exec 5 ######## \n");
    struct date today = {10, 29, 2023};
    struct time now = {23, 59, 59};
    struct dateAndTime current = {.today = today, .now = now, .dow = get_day_of_week(today)};
    printf("Current time is %.2d:%.2d:%.2d %s the %.2d-%.2d-%.2d\n", current.now.hour, current.now.minute, current.now.second, current.dow, current.today.month, current.today.day, current.today.year);
    current = clockKeeper(current);
    printf("Current time is %.2d:%.2d:%.2d %s the %.2d-%.2d-%.2d\n", current.now.hour, current.now.minute, current.now.second, current.dow, current.today.month, current.today.day, current.today.year);
}

int main(void)
{
    exec_2();
    exec_3();
    exec4();
    exec5_and_6();
}
