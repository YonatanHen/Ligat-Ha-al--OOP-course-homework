#pragma once
#include "Worker.h"
class Footballer :public Worker {
protected:
	string teamName, position;
	int  goalScored;
private:
#define BASE_F 6500//base salary of footballer
#define MATCHES 8
public:
	Footballer();
	Footballer(const int, const string, const string, const string, const string, const string);
	Footballer(const Footballer&);
	~Footballer();
	void setFootballer(const string);
	void setFootballer(const string, const string);
	float succesPercentage()const;
	bool isBest()const;
	void addGoal();
	float getSalary() const;
	string getPosition()const;
	void Print()const;

};