#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace DateLib{
#define And &&

    struct sDate { short Year; short Month; short Day; };


    bool isLeapYear(short Year) {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }
    int GetRangedNum(int low, int high, string message = "") {
        cout << message;
        int n;
        cin >> n;
        while (n < low || n > high) {
            cout << "Invalid Choice: ";
            cin >> n;
            cout << endl;
        }
        cin.ignore(1, '\n');
        return n;
    }

    short GetYear() {
        return short(GetRangedNum(1, 30000, "Enter Year: "));
    }
    short GetDay() {
        return short(GetRangedNum(1, 31, "Enter Day: "));
    }
    short GetMonth() {
        return short(GetRangedNum(1, 12, "Enter Month: "));
    }


    short numberOfDaysInMonth(short month, short year) {
        if (month < 1 || month > 12) {
            return 0;
        }
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        return (month == 2) ? ((isLeapYear(year)) ? 29 : 28) : arrdays[month - 1];

    }


    short calculateDayIndex(short day, short month, short year) {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + (12 * a) - 2;
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }


    sDate CreateDate(short day, short month, short year) {
        sDate ret;
        ret.Day = day;
        ret.Month = month;
        ret.Year = year;
        return ret;
    }
    sDate CreateDate() {
        sDate ans;
        ans.Day = GetDay();
        ans.Month = GetMonth();
        ans.Year = GetYear();
        return ans;
    }
    /*sDate GetSystemDate() {
        sDate cur;
        time_t t = time(0);
        tm* rn = localtime(&t);
        cur.Day = rn->tm_mday;
        cur.Month = rn->tm_mon;
        cur.Year = rn->tm_year;
        delete rn;
        return cur;
    }*/


    void printDate(sDate date) {
        short DayOrder = calculateDayIndex(date.Day, date.Month, date.Year);
        printf("Date: %d/%d/%d \n", date.Year, date.Month, date.Day);
        printf("day Order:  %d\n", DayOrder);
        string Days[] = { "sunday" , "monday" , "tuesday" , "wednesday" , "thursday" , "friday" , "saturday" };
        printf("Day Name: %s\n", Days[DayOrder].c_str());
    }


    void printMonthCalendar(short month, short year) {
        string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        printf("\n  _______________%s_______________\n\n", months[month - 1].c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        short current = calculateDayIndex(1, month, year);
        short l = 0;
        for (l; l < current; l++) printf("     ");

        for (int i = 1; i <= numberOfDaysInMonth(month, year); i++) {
            printf("%5d", i);
            if (++l == 7) {
                l = 0;
                printf("\n");
            }


        }
    }


    void printYearCalendar(short year) {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", year);
        printf("  _________________________________\n");
        for (short i = 1; i <= 12; i++) {
            printMonthCalendar(i, year);
            printf("\n");
        }
    }


    short daysFomBeggin(short day, short month, short year) {
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        int sum = 0;
        for (short i = 0; i < month - 1; i++) {
            sum += arrdays[i];
        }
        return  day + ((isLeapYear(year)) ? sum + 1 : sum);
    }
    short daysFomBeggin(sDate date) {
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        int sum = 0;
        for (short i = 0; i < date.Month - 1; i++) {
            sum += arrdays[i];
        }
        return  date.Day + ((isLeapYear(date.Year)) ? sum + 1 : sum);
    }


    sDate daysToDate(short days, short year) {
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        if (isLeapYear(year))arrdays[1]++;
        int sum = 0;
        short i = 0;
        while (days >= 0) {
            days -= arrdays[i];
            i++;
        }
        days += arrdays[i - 1];
        sDate ret;
        ret.Day = days;
        ret.Month = i;
        ret.Year = year;
        return ret;
    }

    int DaysDiff(sDate date1, sDate date2) {
        int days = 0;
        short less = min(date1.Year, date2.Year);
        short more = max(date1.Year, date2.Year);
        days += abs(daysFomBeggin(date1) - daysFomBeggin(date2));
        while (more - less) {
            if (isLeapYear(more)) {
                days += 366;
                more -= 1;
                continue;
            }
            more -= 1;
            days += 365;
        }
        return days;
    }
    bool Date1BeforeDate2(sDate date1, sDate date2) {
        return daysFomBeggin(date1.Day, date1.Month, date1.Year) + date1.Year < daysFomBeggin(date2.Day, date2.Month, date2.Year) + date2.Year;
    }
    bool Date1isEqualtoDate2(sDate date1, sDate date2) {
        return daysFomBeggin(date1.Day, date1.Month, date1.Year) + date1.Year == daysFomBeggin(date2.Day, date2.Month, date2.Year) + date2.Year;
    }
    void CopyDateFromTo(sDate& date1, sDate& date2) {
        date2 = CreateDate(date1.Day, date1.Month, date1.Year);
    }
   /* int daysfromBirthDay(sDate birthdate) {
        return DaysDiff(birthdate, GetSystemDate());
    }*/


    bool CheckLastMonth(sDate date) {
        return date.Month == 12;
    }
    bool CheckLastDay(sDate date) {
        return date.Day == numberOfDaysInMonth(date.Month, date.Year);
    }


    sDate dateAfterAdding(short Days, sDate Date) {// fix this

        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        short arrdaysLeap[] = { 31 , 29, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
     

        while (true) {

            short RemainingDays = Days + daysFomBeggin(Date.Day, Date.Month, Date.Year);
            short MonthDays = 0; Date.Month = 1;
            while (true) {
                MonthDays = numberOfDaysInMonth(Date.Month, Date.Year);
                if (RemainingDays > MonthDays)
                {
                    RemainingDays -= MonthDays;
                    Date.Month++;
                    if (Date.Month > 12)
                    {
                        Date.Month = 1;
                        Date.Year++;
                    }
                }
                else {
                    Date.Day = RemainingDays;
                    break;
                }
            }
            return Date;
        }
    }
    sDate dateAfterRemoving(short Days, sDate Date) {// fix this

        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        short arrdaysLeap[] = { 31 , 29, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        if (Days < numberOfDaysInMonth(Date.Month , Date.Year)) {
            Date.Day -= Days;
            return Date;
        }

        

            short RemainingDays = Days - Date.Day;
            short MonthDays = 0;
            
            Date.Month-=1;
            Date.Day = numberOfDaysInMonth(Date.Month , Date.Year);
            while (true) {
                MonthDays = numberOfDaysInMonth(Date.Month, Date.Year);
                if (RemainingDays > MonthDays)
                {
                    RemainingDays -= MonthDays;
                    Date.Month--;
                    if (Date.Month == 0)
                    {
                        Date.Month = 12;
                        Date.Year--;
                    }
                }
                else {
                    Date.Day -= MonthDays -  RemainingDays;
                    break;
                }
            }
            return Date;
        
    }
    void addOneday(sDate& date) {
        if (CheckLastMonth(date) And CheckLastDay(date)) {
            date.Day = 1;
            date.Month = 1;
            date.Year++;
            return;
        }
        if (CheckLastDay(date)) {
            date.Day = 1;
            date.Month++;
            return;
        }
        date.Day++;
        return;
    }
    sDate addoneWeek(sDate date) {
        sDate ret;
        CopyDateFromTo(date, ret);
        for (int i = 0; i < 7; i++) {
            addOneday(ret);
        }
        return ret;
    }
    sDate addXWeeks(sDate date , int x) {
        sDate ret;
        CopyDateFromTo(date, ret);
        for (int i = 0; i < x; i++) {
            ret = addoneWeek(ret);
        }
        return ret;
    }
    sDate addedOnedayTo(sDate date) {
        sDate New;
        CopyDateFromTo(date, New);
        if (CheckLastMonth(date) And CheckLastDay(date)) {
            New.Day = 1;
            New.Month = 1;
            New.Year++;
            return New;
        }
        if (CheckLastDay(date)) {
            New.Day = 1;
            New.Month++;
            return New;
        }
        New.Day++;
        return New;
    }
    sDate addOneYear(sDate date) {
        date.Year += 1;
        return date;
    }
    sDate addXYears(sDate date , int x) {
        date.Year += x;
        return date;

    }
    sDate addOneMonth(sDate date) {
        if (CheckLastMonth(date)) {
            date.Month = 1;
            date.Year++;
            if (CheckLastDay(date)) {
                date.Day = 31;
            }
            return date;
        }
        date.Month += 1;
        if (CheckLastDay(date)) {
            date.Day = numberOfDaysInMonth(date.Month , date.Year);
        }
        return date;
    }
    sDate addXmonths(sDate date, int x) {
        int rem = (x % 12);
        x = int(x / 12);
        date.Year += x;
        while (rem) {
            date = addOneMonth(date);
            rem -= 1;
        }
        return date;
    }
    sDate addOneDecade(sDate date) {
        date.Year += 10;
        return date;
    }
    sDate addXDecades(sDate date , int x) {
        date.Year += (10 * x);
        return date;
    }
    sDate addOneCenturies(sDate date) {
        date.Year += 100;
        return date;
    }
    sDate addXCenturies(sDate date, int x) {
        date.Year += (100 * x);
        return date;
    }
    sDate addMiillenium(sDate date) {
        date.Year += 1000;
        return date;
    }
}