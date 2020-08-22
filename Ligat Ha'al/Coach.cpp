#include "Coach.h"

Coach::Coach() :Worker(), teamName(""), IsFormerFootballer(false), championships(0) {}

Coach::Coach(const int seniority, const string fName, const string lName, const string id, const string teamName, const bool IsFormerFootballer, const int championships) :
	Worker(seniority, fName, lName, id)
{
	this->teamName = teamName;
	this->IsFormerFootballer = IsFormerFootballer;
	this->championships = championships;
}

Coach::Coach(const Coach &coach) :Worker(coach)
{
	this->teamName = coach.teamName;
	this->championships = coach.championships;
	this->IsFormerFootballer = coach.IsFormerFootballer;
}

Coach::~Coach() {/*automatically destruction*/ }

float Coach::getSalary() const
{
	return Worker::getSalary() + 200 * seniority + 500 * championships;
}

bool Coach::isBest() const
{
	if (championships > 1) return true;
	return false;
}

void Coach::Print() const
{
	Worker::Print();
	cout << "Coach data is:" << endl;
	cout << "team:" << teamName << endl << "Championships he won:" << championships << endl << "His salary is:" << getSalary() << endl;
	if (IsFormerFootballer) cout << "The coach was former footballer" << endl;
	else cout << "The coach wasn't former footballer" << endl;

}

bool Coach::getIsFormerFootballer() const
{
	return IsFormerFootballer;
}

int Coach::getChampionships() const
{
	return championships;
}

void Coach::setCoach(const string team)
{
	char t;
	Worker::setWorker();
	teamName = team;
	cout << "Is he Former footballer? Y/N:";
	do {
		cin >> t;
		if (t != 'Y' && t != 'N' && t != 'y' && t != 'n') cout << "Enter Y/N:";
	} while (t != 'Y' && t != 'N' && t != 'y' && t != 'n');
	if (t = 'Y') IsFormerFootballer = true;
	else IsFormerFootballer = false;
	cout << "Enter championships he won:";
	cin >> championships;
}
