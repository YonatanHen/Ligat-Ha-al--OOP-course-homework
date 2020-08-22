#pragma once
using namespace std;

class Date {
protected:
	int day, month, year;
public:
	Date();
	~Date();
	Date(int, int, int);
	Date(const Date&);
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	virtual int GetDay();
	virtual int GetMonth();
	virtual int GetYear();
	void PrintDate();
	int MonthDaysNum();
	void NextDayDate();
	void CurrentDate();
};