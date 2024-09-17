#pragma once
#pragma warning(disable : 4996)
#define And &&
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;

class Date
{
    enum DateIs { Before = -1, After = 1, Equal = 0 };
    static vector<string> WordsOf(string S1, string seprator = " ") {
        vector<string> vString; size_t pos = 0; string sWord;
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
public:
    short Day = 1;
    short Month = 1;
    short Year = 1900;

	Date() {

		time_t now = time(0);
		tm* t = localtime(&now);
		Year = (short)(1900 + t->tm_year);
		Month = (short)(t->tm_mon + 1);
		Day = (short)(t->tm_wday);
       
	}
    Date(short Year  , short Month, short Day) {
        Day = Day;
        Year = Year;
        Month = Month;
        
    }
    // Format of string must be "dd/mm/yyyy"
    Date(string strDate) {
        vector<string> words = WordsOf(strDate, "/");

        Year = stoi(words.at(2));
        Month = stoi(words.at(1));
        Day = stoi(words.at(0));
        
    }

   
    static string GetStringDate(Date date, string Format) {
        size_t pos = Format.find("dd");
        Format.erase(pos, 2);
        Format.insert(pos, to_string(date.Day));

        pos = Format.find("mm");
        Format.erase(pos, 2);
        Format.insert(pos, to_string(date.Month));

        pos = Format.find("yyyy");
        Format.erase(pos, 4);
        Format.insert(pos, to_string(date.Year));

        return Format;
    }
    string GetStringDate(string Format) {
        return GetStringDate(*this, Format);
    }


    static void Print(Date date) {
        short DayOrder = calculateDayIndex(date);
        printf("Date: %d/%d/%d \n", date.Year, date.Month, date.Day);
        printf("day Order:  %d\n", DayOrder);
        string Days[] = { "sunday" , "monday" , "tuesday" , "wednesday" , "thursday" , "friday" , "saturday" };
        printf("Day Name: %s\n", Days[DayOrder].c_str());
    }
    void Print() {
        Print(*this);
    }


   static void printMonthCalendar(short month, short year) {
        string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        printf("\n  _______________%s_______________\n\n", months[month - 1].c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        short current = calculateDayIndex(Date(year, month, 1));
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
   void printMonthCalendar() {
       printMonthCalendar(Month, Year);
   }


   static bool isLeapYear(short Year) {
       return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
   }
   bool isLeapYear() {
       return isLeapYear(Year);
   }


   static short numberOfDaysInMonth(short month, short year) {
       if (month < 1 || month > 12) {
           return 0;
       }
       short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
       return (month == 2) ? ((isLeapYear(year)) ? 29 : 28) : arrdays[month - 1];

   }
   short numberOfDaysInMonth() {
       return numberOfDaysInMonth(Month, Year);
   }


   static short calculateDayIndex(Date date) {
       short a = (14 - date.Month) / 12;
       short y = date.Year - a;
       short m = date.Month + (12 * a) - 2;
       return (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
   }
   short DayIndex() {
       return calculateDayIndex(*this);
   }


    static void printYearCalendar(short year) {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", year);
        printf("  _________________________________\n");
        for (short i = 1; i <= 12; i++) {
            printMonthCalendar(i, year);
            printf("\n");
        }
    }
    void printYearCalendar() {
        printYearCalendar(Year);
    }


    static short daysFomBeggin(Date date) {
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        int sum = 0;
        for (short i = 0; i < date.Month - 1; i++) {
            sum += arrdays[i];
        }
        return  date.Day + ((isLeapYear(date.Year)) ? sum + 1 : sum);
    }
    short daysFomBeggin() {
        return daysFomBeggin(*this);
    }
    

    static Date daysToDate(short days, short year) {
        while (days < 0) {
            cout << "please re-enter the days count: ";
            cin >> days;
            cout << endl;
        }
        short arrdays[] = { 31 , 28, 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
        if (isLeapYear(year))arrdays[1]++;
        int sum = 0;
        short i = 0;
        while (days >= 0) {
            days -= arrdays[i];
            i++;
        }
        days += arrdays[i - 1];
        Date ret;
        ret.Day = days;
        ret.Month = i;
        ret.Year = year;
        return ret;
    }


    static int DaysDiff(Date date1, Date date2) {
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
    int DaysDiff(Date date2) {
        return DaysDiff(*this, date2);
    }


    static short DaysUntilWeekend(Date date) {
        short potential = 6 - calculateDayIndex(date);
        if (potential == 6) {
            return 6;
        }
        return potential;
    }
    short DaysUntilWeekend() {
        return DaysUntilWeekend(*this);
    }


    static short DaysUntilEndOfMonth(Date date) {
        return numberOfDaysInMonth(date.Month, date.Year) - date.Day;
    }
    short DaysUntilEndOfMonth() {
        return DaysUntilEndOfMonth(*this);
    }


    static short DaysUntilEndOfYear(Date date) {
        return ((isLeapYear(date.Year) ? 366 : 365) - daysFomBeggin(date));
    }
    short DaysUntilEndOfYear() {
        return DaysUntilEndOfYear(*this);
    }
   

    static bool Date1BeforeDate2(Date date1, Date date2) {
        return daysFomBeggin(Date(date1.Year, date1.Month, date1.Day)  ) + date1.Year < daysFomBeggin(Date(date2.Year, date2.Month, date2.Day)) + date2.Year;
    }
    bool isBefore(Date date) {
        return Date1BeforeDate2(*this, date);
    }


    static bool Date1AfterDate2(Date date1, Date date2) {
        return daysFomBeggin(Date(date1.Year, date1.Month, date1.Day)) + date1.Year > daysFomBeggin(Date(date2.Year, date2.Month, date2.Day)) + date2.Year;
    }
    bool isAfter(Date date) {
        return Date1AfterDate2(*this, date);
    }


    static bool Date1isEqualtoDate2(Date date1, Date date2) {
        return daysFomBeggin(Date(date1.Year, date1.Month, date1.Day)) + date1.Year == daysFomBeggin(Date(date2.Year, date2.Month, date2.Day)) + date2.Year;
    }
    bool isEqualto(Date date) {
        return Date1isEqualtoDate2(*this, date);
    }


    /*
        returns -1 if date1 is before date2
        returns 1 if date1 is after date2;
        returns 0 if they're equal
        */
    static short CompareDates(Date date1, Date date2) {

        if (Date1BeforeDate2(date1, date2)) {
            return -1;
        }
        if (Date1AfterDate2(date1, date2)) {
            return 1;
        }
        return 0;
    }
    short CompareDates(Date date) {
        return CompareDates(*this, date);
    }


    static bool isLastMonth(Date date) {
        return date.Month == 12;
    }
    bool isLastMonth() {
        return isLastMonth(*this);
    }


    static bool isLastDay(Date date) {
        return date.Day == numberOfDaysInMonth(date.Month, date.Year);
    }
    bool isLastDay() {
        return isLastDay(*this);
    }
    

    static bool isEndOfWeek(Date date) {
        return calculateDayIndex(date) == 6;
    }
    bool isEndOfWeek() {
        return isEndOfWeek(*this);
    }


    static bool isWeekEnd(Date date) {
        return calculateDayIndex(date) == 0 or calculateDayIndex(date) == 6;
    }
    bool isWeekEnd() {
        return isWeekEnd(*this);
    }


    static bool isBusinessDay(Date date) {
        short ind = calculateDayIndex(date);
        return ind > 0 and ind < 6;
    }
    bool isBusinessDay() {
        return isBusinessDay(*this);
    }


    static void addOneday(Date& date) {
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
    void addOneday() {

    }


    static void addoneWeek(Date& date) {
       
        for (int i = 0; i < 7; i++) {
            addOneday(date);
        }
    }
    void addoneWeek() {

    }
    
    
    static void addXWeeks(Date& date, int x) {
       
        for (int i = 0; i < x; i++) {
            addoneWeek(date);
        }
    }
    void addXweeks(int x) {

    }
    
    
    static void addedOnedayTo(Date& date) {
        
        
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
        return ;
    }
    void addOneDay() {

    }
    
    
    static void addOneYear(Date& date) {
        date.Year += 1;
        return;
    }
    void addOneYear() {

    }
    
    
    static void addXYears(Date& date, int x) {
        date.Year += x;
        return;

    }
    void addXYears() {

    }
    
    
    static void addOneMonth(Date& date) {
        if (isLastMonth(date)) {
            date.Month = 1;
            date.Year++;
            if (isLastDay(date)) {
                date.Day = 31;
            }
            return;
        }
        date.Month += 1;
        if (isLastDay(date)) {
            date.Day = numberOfDaysInMonth(date.Month, date.Year);
        }
        return;
    }
    void addOneMonth() {

    }
    
    
    static void addXmonths(Date& date, int x) {
        int rem = (x % 12);
        x = int(x / 12);
        date.Year += x;
        while (rem) {
            addOneMonth(date);
            rem -= 1;
        }
        return ;
    }
    void addXmonths(int x) {
        addXmonths(*this, x);
    }
    
    
    static void addOneDecade(Date& date) {
        date.Year += 10;
        return;
    }
    void addOneDecade() {
        addOneDecade(*this);
    }
    
    
    static void addXDecades(Date& date, int x) {
        date.Year += (10 * x);
        return;
    }
    void addXDecades(int x) {
        addXDecades(*this, x);
    }
    
    
    static void addOneCentury(Date& date) {
        date.Year += 100;
        return;
    }
    void addOneCentury() {
        addOneCentury(*this);
    }
    
    
    static void addXCenturies(Date& date, int x) {
        date.Year += (100 * x);
        return;
    }
    void addXCenturies(int x) {
        addXCenturies(*this, x);
    }
    
    
    static void addOneMillenium(Date& date) {
        date.Year += 1000;
        return;
    }
    void addOneMillenium() {
        addOneMillenium(*this);
    }
    

    static void DecreaseOneDay(Date& date) {
        if (date.Day == 1 and date.Month == 1) {
            date.Day = 31;
            date.Month = 12;
            date.Year -= 1;
            return;
        }
        if (date.Day == 1) {
            date.Month -= 1;
            date.Day = numberOfDaysInMonth(date.Month, date.Year);
            return;
        }
        date.Day -= 1; // iff day and month are in the middle
        return;
    }
    void DecreaseOneDay() {
        DecreaseOneDay(*this);
    }
    
    
    static void DecreaseXDays(Date& date, int x) {
        while (x > 0) {
            DecreaseOneDay(date);
            x -= 1;
        }
        return;
    }
    void DecreaseXDays(int x) {
        DecreaseXDays(*this, x);
    }


    static void DecreaseOneWeek(Date& date) {
        short i = 0;
        while (i < 7) {
            DecreaseOneDay(date);
        }
        return;
    }
    void DecreaseOneWeek() {
        DecreaseOneWeek(*this);
    }
    
    
    static void DecreaseXWeeks(Date& date, int x) {
        for (int i = 0; i < x; i++) {
            DecreaseOneWeek(date);
        }
        return;
    }
    void DecreaseXWeeks(int x) {
        DecreaseXWeeks(*this, x);
    }
    
    
    static void DecreaseOneMonth(Date& date) {
        bool lastDay = isLastDay(date);
        date.Month -= 1;
        if (date.Month <= 0) {
            date.Month = 12;
            date.Year -= 1;
        }
        if (lastDay) {
            date.Day = numberOfDaysInMonth(date.Month, date.Year);
        }
        return;
    }
    void DecreaseOneMonth() {
        DecreaseOneMonth(*this);
    }
    
    
    static void DecreaseXMonths(Date& date, int x) {
        for (int i = 0; i < x; i++) {
            DecreaseOneMonth(date);
        }
        return;
    }
    void DecreaseXMonths(int x) {
        DecreaseXMonths(*this, x);
    }
    
    
    static void DecreaseOneYear(Date& date) {
        date.Year -= 1;
        if (date.Month == 2 && isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseOneYear() {
        DecreaseOneYear(*this);
    }
    
    
    static void DecreaseXYears(Date& date, int x) {
        while (x) {
            DecreaseOneYear(date);
            x -= 1;
        }
        return;
    }
    void DecreaseXYears(int x) {
        DecreaseXYears(*this, x);
    }
    
    
    static void DecreaseOneDecade(Date& date) {
        date.Year -= 10;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseOneDecade() {
        DecreaseOneDecade(*this);
    }
    
    
    static void DecreaseXDecades(Date& date, int x) {
        date.Year -= 10 * x;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseXDecades(int x) {
        DecreaseXDecades(*this, x);
    }
    
    
    static void DecreaseOneCentury(Date& date) {
        date.Year -= 100;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseOneCentury() {
        DecreaseOneCentury(*this);
    }
    
    
    static void DecreaseXCenturies(Date& date, int x) {
        date.Year -= 100 * x;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseXCenturies(int x){
        DecreaseXCenturies(*this, x);
    }
    
    
    static void DecreaseOneMillenium(Date& date) {
        date.Year -= 1000;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseOneMillenium() {
        DecreaseOneMillenium(*this);
    }
    
    
    static void DecreaseXMilleniums(Date& date, int x) {
        date.Year -= 1000 * x;
        if (date.Month == 2 And isLastDay(date)) {
            if (isLeapYear(date.Year)) {
                date.Day = 29;
            }
            else {
                date.Day = 28;
            }
        }
        return;
    }
    void DecreaseXMilleniums(int x) {
        DecreaseXMilleniums(*this, x);
    }
};


