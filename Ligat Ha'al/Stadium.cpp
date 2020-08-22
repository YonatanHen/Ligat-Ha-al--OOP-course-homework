#include "Stadium.h"

Stadium::Stadium() :name(""), city(""), capacity(0) {}

Stadium::Stadium(const string name, const string city, int capacity)
{
	this->capacity = capacity;
	this->city = city;
	this->name = name;
}

Stadium::Stadium(const Stadium &stadium)
{
	this->capacity = stadium.capacity;
	this->city = stadium.city;
	this->name = stadium.name;
}

Stadium::~Stadium() {/*Automatically deallocation*/ }

void Stadium::printStadium()
{
	cout << "Name:" << name << endl << "City:" << city << endl << "Capacity:" << capacity << endl;
}

void Stadium::setStadium()
{
	cout << "Enter stadium name:";
	cin >> name;
	cout << "Enter stadium city:";
	cin >> city;
	cout << "Enter capacity:";
	cin >> capacity;
}
