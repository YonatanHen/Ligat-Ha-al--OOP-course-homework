#pragma once
#include "Team.h"
#include "Date.h"
#include "Referee.h"
class Game :public Date {
protected:
	Team *team1, *team2;
	Date *date;
	string score;
	int goals1, goals2;
	Referee **refList;
	int const gameRefs = 3; //referee staff per one game
public:
	Game();
	Game(const Game&);
	~Game();
	void printGame()const;
	void setDate();
	void setRefMistakes(const string, const int);//add re mistakes by id
	void setRefList(const Referee*);
	Referee * getReferee(const int);//return referee by index
	int getRefNum();
	void setTeams( Team* &,  Team* &);
	Team getTeam1() const;
	Team getTeam2()const;
	string getScore();
	int GetDay();
	int GetMonth();
	int GetYear();
	void printMatchPlayingTeams()const;
};