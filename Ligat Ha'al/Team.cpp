#include "Team.h"
int Team::footballersNum = 15; //2-gk,3-st,4-mid,3-def,3-sw
Team::Team() :teamName(""), teamStadium(nullptr), TeamFootballers(nullptr), teamCoach(nullptr), teamManager(nullptr), isManager(false), points(0) {}

Team::Team(const string teamName, const Stadium stadium, Footballer *FList, const Coach coach, const Manager manager) : teamName(teamName),points(0)
{
	teamStadium = new Stadium(stadium);
	TeamFootballers = new Footballer*;
	(*TeamFootballers) = new Footballer[footballersNum];
	for (int i = 0; i < footballersNum; i++)
	{
		(*TeamFootballers)[i] = Footballer(FList[i]);
	}
	teamCoach = new Coach(coach);
	teamManager = new Manager(manager);
	isManager = true;
}

Team::Team(const Team &team)
{
	teamName = team.getTeamName();
	points = team.getPoints();
	if (team.teamCoach != nullptr)
	{
		teamCoach = new Coach((*team.teamCoach));
	}
	if (team.teamStadium != nullptr)
	{
		teamStadium = new Stadium((*team.teamStadium));
	}
	if (team.teamManager != nullptr)
	{
		teamManager = new Manager((*team.teamManager));
	}
	TeamFootballers = new Footballer*(*team.TeamFootballers);
}

Team::~Team()
{
	if (teamStadium != nullptr) teamStadium = nullptr;
	delete teamStadium;
	if (teamCoach != nullptr) teamCoach = nullptr;
	delete teamCoach;
	if (teamManager != nullptr) teamManager = nullptr;
	delete teamManager;
	if (TeamFootballers != nullptr)
	{
		if (*TeamFootballers != nullptr) {
			for (int i = 0; i < footballersNum; i++)
			{
				if (TeamFootballers[i] != nullptr) TeamFootballers[i] = nullptr;
				delete TeamFootballers[i];

			}
		}
		TeamFootballers = nullptr;
		delete[] TeamFootballers;
	}
}

void Team::addFootballer(Footballer *f)
{
	int i;
	Footballer **temp;
	footballersNum++;
	temp = new Footballer*[footballersNum];
	for (i = 0; i < footballersNum - 1; i++)
	{
		temp[i] = TeamFootballers[i];
	}
	temp[footballersNum - 1] = new Footballer(*f);
	*TeamFootballers = new Footballer[footballersNum];
	for (i = 0; i < footballersNum; i++)
	{
		TeamFootballers[i] = temp[i];
	}
}

void Team::addManager(Manager *m)
{
	if (isManager) cout << "Manager already exist!" << endl;
	else {
		isManager = true;
		teamManager = new Manager(*m);
		cout << "Manager has been added successfully" << endl;
	}
}

void Team::addCoach(Coach *c)
{
	if (teamCoach != nullptr) cout << "Coach already exist!" << endl;
	else {
		teamCoach = new Coach(*c);
		cout << "Coach has been added successfully" << endl;
	}
}

Footballer * Team::FootballerIndex(const int index) const
{
	return TeamFootballers[index]; //pay Attention,function return pointer not value
}

void Team::PrintTeam() const
{
	cout << "Team Info:" << endl;
	cout << "Team name:" << teamName << endl;
	cout << "Stadium Info:" << endl;
	teamStadium->printStadium();
	if (isManager) {
		cout << "Manager Info:" << endl;
		teamManager->Print();
	}
	else cout << "Team has no manager" << endl;
	cout << "Coach Info:" << endl;
	teamCoach->Print();
	cout << "Team Footballers roster:" << endl;
	for (int i = 0; i < footballersNum; i++)
	{
		cout << "Footballer " << i + 1 << " data:" << endl;
		(*TeamFootballers)[i].Print();
	}
}

int Team::getFootballersNum() const
{
	return footballersNum;
}

Footballer *Team::getTeamFootballers()
{
	return (*TeamFootballers);
}

Footballer * Team::getFootballer(const int index)
{
	return (TeamFootballers)[index];
}

string Team::getTeamName() const
{
	return teamName;
}

Coach Team::getTeamCoach() const
{
	return (*teamCoach);
}

Manager Team::getTeamManager() const
{
	return (*teamManager);
}

Stadium Team::getStadium() const
{
	return (*teamStadium);
}

int Team::getPoints() const
{
	return points;
}

void Team::setPoints(const int points)
{
	this->points =points;
}

void Team::addPoints(const int points)
{
	this->points += points;
}

