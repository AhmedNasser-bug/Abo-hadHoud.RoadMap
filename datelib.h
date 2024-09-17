#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace DateLib{
#define And &&

    struct sDate { short Year; short Month; short Day; };
    struct sPeriod { sDate start; sDate end; };
    enum DateIs { Before = -1, After = 1, Equal = 0 };
    vector<string> WordsOf(string S1, string seprator = " ") {
        vector<string> vString; short pos = 0; string sWord;
        // define a string variable 
        // use find() function to get the position of the delimiters 
        while ((pos = S1.find(seprator)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word 
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + seprator.length());
        }
        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string. 
        } return vString;
    }
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


    short calculateDayIndex(sDate date) {
        short a = (14 - date.Month) / 12;
        short y = date.Year - a;
        short m = date.Month + (12 * a) - 2;
        return (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    short calculateDayIndex(short day , short Month , short Year) {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;
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
        if (ans.Day > numberOfDaysInMonth(ans.Month, ans.Year)) {
            ans.Day = numberOfDaysInMonth(ans.Month, ans.Year);
        }
        return ans;
    }
    sDate CreateDate(string date, string Seprator = "/") {
        vector<string> words = WordsOf(date, Seprator);
        sDate date;
        date.Year = stoi(words.at(2));
        date.Month = stoi(words.at(1));
        date.Day = stoi(words.at(0));
        return date;
    }
    string GetString() {
        //cout << "Enter String: ";
        string temp = "";
        while (temp == "")getline(cin, temp);
        //Alternative: getline(cin, temp);
        return temp;
    }
    string ReadDateString() {
        cout << "Enter Date string dd/mm/yyyy\n";
        string date = GetString();
        return date;
    }
    string dateToString(sDate date) {
        string tmp;

        tmp.append(to_string(date.Day) + '/');
        
        tmp.append(to_string(date.Month) + '/');
        
        tmp.append(to_string(date.Year));

        return tmp;
    }
    string FormatDate(sDate date , string Format) {
        short pos = Format.find("dd");
        Format.erase(pos, 2);
        Format.insert(pos, to_string(date.Day));

        pos = Format.find("mm");
        Format.erase(pos, 2);
        Format.insert(pos ,to_string(date.Month));

        pos = Format.find("yyyy");
        Format.erase(pos, 4);
        Format.insert(pos ,to_string(date.Year));

        return Format;
    }
    sPeriod ReadPeriod() {
        cout << "Enter Start Of Period\n";
        sDate start = CreateDate();
        cout << "Enter End Of Period\n";
        sDate End = CreateDate();
        sPeriod period;
        period.end = End;
        period.start = start;
        return period;
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
        short DayOrder = calculateDayIndex(date);
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

    short DaysUntilWeekend(sDate date) {
        short potential = 6 - calculateDayIndex(date);
        if (potential == 6) {
            return 6;
        }
        return potential;
    }
    short DaysUntilEndOfMonth(sDate date) {
        return numberOfDaysInMonth(date.Month, date.Year) - date.Day;
    }
    short DaysUntilEndOfYear(sDate date) {
        return ((isLeapYear(date.Year) ? 366 : 365) - daysFomBeggin(date));
    }

    bool Date1BeforeDate2(sDate date1, sDate date2) {
        return daysFomBeggin(date1.Day, date1.Month, date1.Year) + date1.Year < daysFomBeggin(date2.Day, date2.Month, date2.Year) + date2.Year;
    }
    bool Date1AfterDate2(sDate date1, sDate date2) {
        return daysFomBeggin(date1.Day, date1.Month, date1.Year) + date1.Year > daysFomBeggin(date2.Day, date2.Month, date2.Year) + date2.Year;
    }


    bool Date1isEqualtoDate2(sDate date1, sDate date2) {
        return daysFomBeggin(date1.Day, date1.Month, date1.Year) + date1.Year == daysFomBeggin(date2.Day, date2.Month, date2.Year) + date2.Year;
    }
    /*
        returns -1 if date1 is before date2
        returns 1 if date1 is after date2;
        returns 0 if they're equal
        */
    bool CompareDates(sDate date1, sDate date2) {
        
        if (Date1BeforeDate2(date1, date2)) {
            return -1;
        }
        if (Date1AfterDate2(date1, date2)) {
            return 1;
        }
        return 0;
    }
    bool OverlappingPeriodsSlow(sDate strt1, sDate strt2, sDate end1, sDate end2) {
        return (CompareDates(strt1, strt2) == -1) ? ((Date1BeforeDate2(strt2, end1) or CompareDates(strt2, end1) == 0) ? 1 : (CompareDates(strt1, strt2) == 0)) : ((Date1BeforeDate2(strt1, end2) or CompareDates(strt1 , end2) == 0) ? 1 : (CompareDates(strt1, strt2) == 0));
    }
    bool OverLappingPeriods(sPeriod period1, sPeriod period2) {
        return (CompareDates(period1.end, period2.start) == DateIs::Before or CompareDates(period1.start, period2.end) == DateIs::After);
    }
    void CopyDateFromTo(sDate& date1, sDate& date2) {
        date2 = CreateDate(date1.Day, date1.Month, date1.Year);
    }
    bool DateWithinPeriod(sDate date, sPeriod period) {
        return  not (Date1AfterDate2(date, period.end) or Date1BeforeDate2(date, period.start));
    }
    int DaysSimilar(sPeriod p1, sPeriod p2) {
        return (DateWithinPeriod(p1.start, p2)) ? DaysDiff(p1.start, p2.end) : DaysDiff(p2.start, p1.end);
    }


    bool isLastMonth(sDate date) {
        return date.Month == 12;
    }
    bool isLastDay(sDate date) {
        return date.Day == numberOfDaysInMonth(date.Month, date.Year);
    }
    bool isEndOfWeek(sDate date) {
        return calculateDayIndex(date) == 6;
    }
    bool isWeekEnd(sDate date) {
        return calculateDayIndex(date) == 0 or calculateDayIndex(date) == 6;
    }
    bool isBusinessDay(sDate date) {
        short ind = calculateDayIndex(date);
        return ind > 0 and ind < 6;
    }

    int GetPeriodLength(sPeriod period) {
        return DaysDiff(period.start, period.end);
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
        if (isLastMonth(date) And isLastDay(date)) {
            date.Day = 1;
            date.Month = 1;
            date.Year++;
            return;
        }
        if (isLastDay(date)) {
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
        if (isLastMonth(date) And isLastDay(date)) {
            New.Day = 1;
            New.Month = 1;
            New.Year++;
            return New;
        }
        if (isLastDay(date)) {
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
        if (isLastMonth(date)) {
            date.Month = 1;
            date.Year++;
            if (isLastDay(date)) {
                date.Day = 31;
            }
            return date;
        }
        date.Month += 1;
        if (isLastDay(date)) {
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


    sDate DecreaseOneDay(sDate date) {
        if (date.Day == 1 and date.Month == 1) {
            date.Day = 31;
            date.Month = 12;
            date.Year -= 1;
            return date;
        }
        if (date.Day == 1) {
            date.Month -= 1;
            date.Day = numberOfDaysInMonth(date.Month, date.Year);
            return date;
        }
        date.Day -= 1; // iff day and month are in the middle
        return date;
    }
    sDate DecreaseXDays(sDate date , int x){
        while (x > 0) {
            date = DecreaseOneDay(date);
            x -= 1;
        }
        return date;
    }
    sDate DecreaseOneWeek(sDate date) {
        short i = 0;
        while (i < 7) {
            date = DecreaseOneDay(date);
        }
        return date;
    }
    sDate DecreaseXWeeks(sDate date , int x) {
        for (int i = 0; i < x; i++) {
            date = DecreaseOneWeek(date);
        }
        return date;
    }
    sDate DecreaseOneMonth(sDate date) {
        bool lastDay = isLastDay(date);
        date.Month -= 1;
        if (date.Month <= 0) {
            date.Month = 12;
            date.Year -= 1;
        }
        if (lastDay) {
            date.Day = numberOfDaysInMonth(date.Month , date.Year);
        }
        return date;
    }
    sDate DecreaseXMonths(sDate date , int x) {
        for (int i = 0; i < x; i++) {
            date = DecreaseOneMonth(date);
        }
        return date;
    }
    sDate DecreaseOneYear(sDate date) {
        date.Year -= 1;
        if (date.Month == 2 && isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }
    sDate DecreaseXYears(sDate date, int x) {
        while (x) {
            date = DecreaseOneYear(date);
            x -= 1;
        }
        return date;
    }
    sDate DecreaseOneDecade(sDate date){
        date.Year -= 10;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }
    sDate DecreaseXDecades(sDate date, int x) {
        date.Year -= 10*x;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }
    sDate DecreaseOneCentury(sDate date) {
        date.Year -= 100;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }
    sDate DecreaseXCenturies(sDate date , int x) {
        date.Year -= 100 * x;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }
    sDate DecreaseOneMillenium(sDate date) {
        date.Year -= 1000;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }
    sDate DecreaseXMilleniums(sDate date , int x) {
        date.Year -= 1000*x;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return date;
    }


    int vacationDays(sDate start, sDate End) {
        int days = 0;
        while (start.Day != End.Day or start.Year != End.Year or End.Month != start.Month) {
            addOneday(start);
            if (not isWeekEnd(start)) {
                days++;
            }
        }
        return days;
    }
    sDate vacationReturnDate(sDate start , int Days) {
        while (Days) {
            if (not isWeekEnd(start)) {
                Days--;
            }
            addOneday(start);     
        }
        return start;
    }
}