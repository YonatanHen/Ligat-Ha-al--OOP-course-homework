#pragma once
#include "Game.h"
#include <typeinfo>
#include <stdlib.h> 
#include <time.h> 
using namespace std;
#define T 5//number of teams
#define G 20//number of games
class Ligat_HaAl :public Game {
private:
	const string Fnames[15] = { "Avi","Dani","Yossi","Eli","Rafi","David","Gabi","Shimon","Amnon","Michael","Moshe","Gilad","Aviv","Yitzhak","Yaakov" };
	const string Lnames[10] = { "Cohen","Levi","Avraham","Barak","Moshe","Hershkovits","Avital","Peretz","Biton","Artzi" };
	const string teams[5] = { "Beitar Jerusalem","Maccabi Tel Aviv","Hapoel Tel Aviv","Maccabi Haifa","Hapoel Beer Sheva" };
	const string stadiums[5] = { "Teddy","Blumfield","Hamoshava","Sammy Ofer","Turner" };
	const string position[5] = { "Goalkeeper","Striker","Midfielder","Defender","Sweeper" };
	const int StdCapacity[5] = { 30000,18000,10000,32000,16000 };
	const string cities[5] = { "Jeruslaem","Tel Aviv","Tel Aviv","Haifa","Beer Sheva" };
	Team **teamList;
	Game **games;
	Worker **workerList;
	int workerNum;
	int points[T];
	const int refNum = 4;//default num of referee's
	void buildSchedule();//Utility function of Ctor
	void addFootballerToWorkerList(const Footballer*);
	void addRefereeToWorkerList(const Referee*);
	bool checkWorkerList(const Worker*);//Utility function 
	void addFootballer();
	void addReferee();
	void PrintTeamDetalis() const;
	void PrintRefereeDetails();
	void PrintFutureGamesDetails() const;
	void PrintWorkerSalary() const;
	void addJudgemntErrors();
	void PrintOutsatndingPeople() const;
	//Utility functions of PrintOutsatndingPeople
	void printOutstandingFootballers() const;
	void printOutstandingCoaches() const;
	void printOutstandingManagers() const;
	void printOutstandingReferees() const;
	//End of utility functions of PrintOutsatndingPeople
	void printTable();
	void printSmallestSalary();

public:
	Ligat_HaAl();
	~Ligat_HaAl();
	void Menu();
	static bool checkIfDatePassed(Game & game); //Utility function
};