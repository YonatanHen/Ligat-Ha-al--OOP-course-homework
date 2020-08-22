#include "Footballer.h"

Footballer::Footballer() :Worker(), teamName(""), position(""), goalScored(0) {}

Footballer::Footballer(const int seniority, const string fName, const string lName, const string id, const string teamName, const string position) :
	Worker(seniority, fName, lName, id)
{
	this->teamName = teamName;
	this->position = position;
	this->goalScored = 0;
}

Footballer::Footballer(const Footballer &footballer) :Worker(footballer)
{
	this->teamName = footballer.teamName;
	this->position = footballer.position;
	this->goalScored = footballer.goalScored;
}

Footballer::~Footballer() {/*automatically deallocation*/ }

void Footballer::setFootballer(const string team)
{
	Worker::setWorker();
	teamName = team;
	cout << "Enter Position (Goalkeeper,Defender,Midfielder,Striker,Sweeper) :";
	while(1){
		cin >> position;
		if (position != "Goalkeeper" && position != "Defender" && position != "Midfielder" && position != "Striker" && position != "Sweeper") {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "(Legal value,enter again) : ";
		}
		else break;
	}
}

void Footballer::setFootballer(const string team, const string pos)
{
	Worker::setWorker();
	teamName = team;
	position = pos;
}

float Footballer::succesPercentage() const
{
	return (float)goalScored / MATCHES;
}

bool Footballer::isBest() const
{
	if (this->succesPercentage() > 75) return true;
	return false;
}

void Footballer::addGoal()
{
	this->goalScored += 1;
}

float Footballer::getSalary() const
{
	return BASE_F + (succesPercentage() / 100) * 2000;
}

string Footballer::getPosition() const
{
	return position;
}

void Footballer::Print() const
{
	Worker::Print();
	cout << "Footballer data is:" << endl;
	cout << "Team:" << teamName << endl << "Position:" << position << endl << "Goals scored:" << goalScored << endl;
	cout << "His succes % is:" << this->succesPercentage() << endl;
	cout << "His salary is:" << this->getSalary() << endl;
}
