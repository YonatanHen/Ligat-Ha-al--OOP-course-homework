#pragma once
#include "Worker.h"
class Referee :public Worker {
protected:
	int mistakes;
	static int matches;
private:
	static int maxMistakes;
public:
	Referee();
	Referee(const int, const string, const string, const string);
	Referee(const Referee&);
	~Referee();
	float getSalary()const;
	bool isBest()const;
	void setMistakes(const int);
	void Print()const;
	void addMatches();
	void setReferee(const int, const string, const string, const string);
	void setReferee();

};