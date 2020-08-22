#pragma once
#include "Coach.h"
#include "Footballer.h"
#include "Manager.h"
#include "Stadium.h"

class Team
{
protected:
	string teamName;
	Stadium *teamStadium;
	Footballer **TeamFootballers;
	Coach *teamCoach;
	Manager *teamManager;
	int points;
	int static footballersNum;
	bool isManager;
public:
	Team();
	Team(const string, const Stadium, Footballer*, const Coach, const Manager);
	Team(const Team&);
	virtual ~Team();
	void addFootballer(Footballer*);
	void addManager(Manager*);
	void addCoach(Coach*);
	Footballer* FootballerIndex(const int) const;
	void PrintTeam()const;
	int getFootballersNum()const;
	Footballer* getTeamFootballers();
	Footballer* getFootballer(const int);
	string getTeamName() const;
	Coach getTeamCoach()const;
	Manager getTeamManager()const;
	Stadium getStadium()const;
	int getPoints()const;
	void setPoints(const int points);
	void addPoints(const int points);
};
