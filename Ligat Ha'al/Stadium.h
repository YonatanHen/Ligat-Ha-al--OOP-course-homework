#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stadium {
private:
	string name, city;
	int capacity;
public:
	Stadium();
	Stadium(const string, const string, int);//name,city,capcaity
	Stadium(const Stadium&);
	~Stadium();
	void printStadium();
	void setStadium();
};