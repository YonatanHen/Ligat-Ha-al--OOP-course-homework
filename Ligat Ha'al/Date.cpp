#pragma once
#include<iostream>
#include<time.h>
#include "Date.h"
#pragma warning(disable : 4996)
using namespace std;

Date::Date() {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}

Date::~Date() {/*Automatically deallocation*/ }

Date::Date(int day, int month, int year) :day(day), month(month), year(year) {}

Date::Date(const Date &date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

void Date::SetDay(int d) {
	day = d;
}

void Date::SetMonth(int m) {
	month = m;
}

void Date::SetYear(int y) {
	year = y;
}

int Date::GetDay() { return day; }

int Date::GetMonth() { return month; }

int Date::GetYear() { return year; }

void Date::PrintDate() {
	cout << day << "/" << month << "/" << year << endl;
}


int Date::MonthDaysNum() {
	int num;
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
		num = 31;
	}
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		num = 30;
	}
	if (month == 2) {
		num = 28;
	}
	return num;
}

void Date::NextDayDate() {
	if (day < MonthDaysNum())
		day++;
	if (day == MonthDaysNum() && month < 12) {
		day = 1;
		month++;
	}
	if (day == MonthDaysNum() && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
}

void Date::CurrentDate()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	year = 1900 + ltm->tm_year;
	month = 1 + ltm->tm_mon;
	day = ltm->tm_mday;
}
