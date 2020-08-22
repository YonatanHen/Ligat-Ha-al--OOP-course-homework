#include "Referee.h"

int Referee::maxMistakes = 0;
int Referee::matches = 0;
Referee::Referee() :Worker(), mistakes(0) {}

Referee::Referee(const int seniority, const string fName, const string lName, const string id) : Worker(seniority, fName, lName, id), mistakes(0) {}

Referee::Referee(const Referee &referee) : Worker(referee)
{
	this->mistakes = referee.mistakes;
	this->matches = referee.matches;
}

Referee::~Referee() {/*automatically deallocation*/ }

float Referee::getSalary() const
{
	if (mistakes > maxMistakes) {
		maxMistakes = mistakes;
		return Worker::getSalary() + 30 * matches - 500;
	}
	return Worker::getSalary() + 30 * matches;
}

bool Referee::isBest() const
{
	if (mistakes < maxMistakes / 2) return true;
	return false;
}

void Referee::setMistakes(const int mistakes)
{
	this->mistakes += mistakes;
}

void Referee::Print() const
{
	Worker::Print();
	cout << "Referee data is:" << endl;
	cout << "His Salary is:" << getSalary() << endl;
	cout << "Matches he judged:" << matches << endl;
	cout << "Mistakes during season:" << mistakes << endl;
}

void Referee::addMatches()
{
	this->matches++;
}

void Referee::setReferee(const int sen, const string fname, const string lname, const string id)
{
	seniority = sen;
	lName = lname;
	fName = fname;
	this->id = id;
}

void Referee::setReferee()
{
	Worker::setWorker();
}

