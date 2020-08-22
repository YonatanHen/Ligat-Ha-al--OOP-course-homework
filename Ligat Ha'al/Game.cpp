#include "Game.h"
#include "Ligat_HaAl.h"

Game::Game() :team1(nullptr), team2(nullptr), date(nullptr), goals1(rand() % 4), goals2(rand() % 4), refList(nullptr) {}

Game::Game(const Game &game)
{
	if (game.team1 == nullptr) team1 = new Team(*game.team1);
	if (game.team2 == nullptr) team2 = new Team(*game.team2);
	if (game.date == nullptr) date = new Date(*game.date);
	goals1 = game.goals1;
	goals2 = game.goals2;

	if (refList == nullptr)
	{
		(*refList) = new Referee[getRefNum()];
	}
	for (int i = 0; i < getRefNum(); i++)
	{
		(*refList)[i] = (*game.refList)[i];
	}
}

Game::~Game()
{
	if (team1 != nullptr) delete team1;
	if (team2 != nullptr) delete team2;
	if (date != nullptr) delete date;
	if (refList != nullptr)
	{
		if (*refList != nullptr) {
			for (int i = 0; i < getRefNum(); i++)
			{
				if (refList[i] != nullptr) (*refList)[i].~Referee();
			}
		}
		delete[] refList;
	}
}

void Game::printGame() const
{
	cout << endl << "Game info : " << endl << "Match date : ";
	(*date).PrintDate();
	cout << (*team1).getTeamName() << " vs " << (*team2).getTeamName() << endl;
	cout << "Match stadium : " << endl;
	(team1)->getStadium().printStadium();
	cout << "Team 1 coach : " << (*team1).getTeamCoach().getFName() << " " << (*team1).getTeamCoach().getLName() << endl;
	cout << "Team 2 coach : " << (*team2).getTeamCoach().getFName() << " " << (*team2).getTeamCoach().getLName() << endl;
	cout << "Winning team : " << score << endl;
}


void Game::setDate()
{
	date = new Date;
	/*Randomal date*/
	(*date).SetYear(2020);
	(*date).SetMonth(rand() % 12 + 1);//12 months in a year
	(*date).SetDay(rand() % (*date).MonthDaysNum() + 1);

}

void Game::setRefMistakes(const string refID, const int mistakes)
{
	for (int i = 0; i < getRefNum(); i++)
	{
		if ((refList)[i]->getID() == refID) (*refList)[i].setMistakes(mistakes);
	}
}

void Game::setRefList(const Referee* ref)
{
	refList = new Referee*[getRefNum()];
	for (int i = 0; i < getRefNum(); i++)
		(refList)[i] = new Referee(ref[i]);
}


Referee * Game::getReferee(const int index)
{
	return (refList)[index];
}

int Game::getRefNum()
{
	return gameRefs;
}


void Game::setTeams( Team *&t1, Team *&t2)
{
	team1 = new Team(*t1);
	team2 = new Team(*t2);	
	if (goals1 > goals2) {
		score = (*t1).getTeamName();
		(*t1).addPoints(3);
	}
	else if (goals2 > goals1) {
		score = (*t2).getTeamName();
		(*t2).addPoints(3);
	}
	else {
		score = "Draw";
		(*t1).addPoints(1);
		(*t2).addPoints(1);
	}
}

Team Game::getTeam1() const
{
	return (*team1);
}

Team Game::getTeam2() const
{
	return (*team2);
}

string Game::getScore() 
{
	return score;
}

int Game::GetDay()
{
	return (*date).GetDay();
}

int Game::GetMonth()
{
	return  (*date).GetMonth();
}

int Game::GetYear()
{
	return (*date).GetYear();
}

void Game::printMatchPlayingTeams() const
{
	cout << (*team1).getTeamName() << " vs " << (*team2).getTeamName() << endl;
}

