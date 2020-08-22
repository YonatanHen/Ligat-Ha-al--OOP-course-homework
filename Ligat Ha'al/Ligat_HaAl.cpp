#include "Ligat_HaAl.h"

void Ligat_HaAl::buildSchedule()
/* function build league games schedule */
{
	//Randomise date of league matches
	games = nullptr;
	games = new Game*;
	*games = nullptr;
	*games = new Game[G];
	for (int i = 0; i < G; i++)
	{
		(*games)[i].setDate();
	}
	//Set matches referee's
	int refOut, count = 0, k = 0;
	for (int i = 0; i < G; i++)
	{
		refOut = rand() % refNum;//randomise a referee who doesn't taking part (default:4 referee's)
		Referee *tempRefList = nullptr;
		tempRefList = new Referee[getRefNum()];
		for (int j = 0; j < workerNum; j++)
		{
			Referee *help = dynamic_cast<Referee*>((workerList)[j]);
			if (help)
			{
				if (count != refOut) {
					count++;
					(tempRefList)[k++] = Referee(workerList[j]->getSeniority(), workerList[j]->getFName(), workerList[j]->getLName(), workerList[j]->getID());
				}
				else count++;
			}
		}
		(*games)[i].setRefList(tempRefList);//send refList to game[i]
		count = k = 0;
		delete[] tempRefList;
	}
	(*games)[0].setTeams((teamList)[0], (teamList)[1]);
	(*games)[1].setTeams((teamList)[0], (teamList)[3]);
	(*games)[2].setTeams((teamList)[1], (teamList)[2]);
	(*games)[3].setTeams((teamList)[3], (teamList)[4]);
	(*games)[4].setTeams((teamList)[2], (teamList)[3]);
	(*games)[5].setTeams((teamList)[4], (teamList)[0]);
	(*games)[6].setTeams((teamList)[2], (teamList)[1]);
	(*games)[7].setTeams((teamList)[4], (teamList)[3]);
	(*games)[8].setTeams((teamList)[3], (teamList)[2]);
	(*games)[9].setTeams((teamList)[0], (teamList)[4]);
	(*games)[10].setTeams((teamList)[0], (teamList)[2]);
	(*games)[11].setTeams((teamList)[1], (teamList)[4]);
	(*games)[12].setTeams((teamList)[4], (teamList)[1]);
	(*games)[13].setTeams((teamList)[2], (teamList)[0]);
	(*games)[14].setTeams((teamList)[3], (teamList)[1]);
	(*games)[15].setTeams((teamList)[1], (teamList)[3]);
	(*games)[16].setTeams((teamList)[4], (teamList)[2]);
	(*games)[17].setTeams((teamList)[2], (teamList)[4]);
	(*games)[18].setTeams((teamList)[3], (teamList)[0]);
	(*games)[19].setTeams((teamList)[1], (teamList)[0]);
	for (int i = 0; i < T; i++) {
		points[i] = teamList[i]->getPoints();
	}
}

void Ligat_HaAl::addFootballerToWorkerList(const Footballer *w)
{
	int i = 0;
	Worker **temp = nullptr;
	workerNum++;
	temp = new Worker*[workerNum];
	for (int i = 0; i < workerNum - 1; i++)
	{
		temp[i] = workerList[i];
		delete workerList[i];
	}
	delete[] workerList;
	workerList = nullptr;
	temp[workerNum - 1] = new Footballer(*w);
	workerList = new Worker*[workerNum];
	for (int i = 0; i < workerNum; i++)
	{
		workerList[i] = temp[i];
		temp[i] = nullptr;
		delete temp[i];
	}
	temp = nullptr;
	delete[] temp;
}

void Ligat_HaAl::addRefereeToWorkerList(const Referee *r)
{
	int i = 0;
	Worker **temp = nullptr;
	workerNum++;
	temp = new Worker*[workerNum-1];
	for (int i = 0; i < workerNum - 1 ; i++)
	{
		temp[i] = workerList[i];
		delete workerList[i];
	}
	delete[] workerList;
	workerList = nullptr;
	temp[workerNum - 1] = new Referee(*r);
	workerList = new Worker*[workerNum];
	for (int i = 0; i < workerNum; i++)
	{
		workerList[i] = temp[i];
		temp[i] = nullptr;
		delete temp[i];
	}
	temp = nullptr;
	delete[] temp;
}



void Ligat_HaAl::PrintTeamDetalis() const
{
	string teamName;
	bool isExist = false;
	cout << "League teams are:" << endl;
	for (int i = 0; i < T; i++)
	{
		cout << i + 1 << "." << (teamList)[i]->getTeamName() << endl;
	}//print legaue teams name
	getchar();
	cout << endl << "Enter a name of a team that you want to see her details : ";
	do {
		getline(cin, teamName);
		for (int i = 0; i < T; i++)
		{
			if (teamName == (teamList)[i]->getTeamName()) isExist = true;
		}
		if (!isExist) cout << "The team name you entered is not part of league teams,enter tem name again : ";
	//while loop requires to enter a name of a team in the league.
	} while (!isExist);
	for (int i = 0; i < T; i++)
	{
		if (teamName == (teamList)[i]->getTeamName()) (teamList)[i]->PrintTeam();
	}
}

void Ligat_HaAl::PrintRefereeDetails()
{
	int count = 1;
	cout << "League Referee's details are : " << endl;
	for (int i = 0; i < workerNum; i++)
	{
		Referee * help = dynamic_cast<Referee*>((workerList)[i]);
		if (help) {
			cout << endl << "Referee " << count << " details : " << endl;
			(workerList)[i]->Print();
			cout << endl << "Referee " << count++ << " judge the following games : " << endl;
			for (int j = 0; j < G; j++)
			{
				for (int k = 0; k < (*games)[j].getRefNum(); k++)
				{
					if ((*games)[j].getReferee(k)->getID() == (workerList)[i]->getID()) (*games)[j].printGame();
				}
			}
		}
	}
}

void Ligat_HaAl::PrintFutureGamesDetails() const
{
	Date today;
	//set today date automatically
	today.CurrentDate();
	for (int i = 0; i < G; i++)
	{
		if (checkIfDatePassed(((*games)[i]))) (*games)[i].printGame();
	}
}

void Ligat_HaAl::PrintWorkerSalary() const
{
	string wID;
	float wSalary;
	bool flag = false;
	cout << "Enter worker ID,program print his salary:";
	cin >> wID;
	for (int i = 0; i < workerNum; i++)
	{
		if (wID == (workerList)[i]->getID()) {
			wSalary = (workerList)[i]->getSalary();
			flag = true;
		}
	}
	if (flag) cout << "Worker salary is:" << wSalary << endl;
	else cout << "program does'nt found ID number that mtach to the ID that you have entered" << endl;
}

void Ligat_HaAl::addJudgemntErrors()
{
	string refID;
	int refER;
	bool flag = false;
	cout << "Enter referee ID and Judgement errors number you want to add:" << endl;
	cin >> refID >> refER;
	for (int i = 0; i < workerNum; i++)
	{
		Referee * help = dynamic_cast<Referee*>(workerList[i]);
		if (help && (workerList)[i]->getID() == refID) {
			for (int j = 0; j < G; j++) {
				(*games)[j].setRefMistakes(refID, refER);
			}
			flag = true;
		}
	}
	if (!flag) cout << "There are no referee that match to the ID you have entered" << endl;
	else cout << "Errors added successfully" << endl;
}
void Ligat_HaAl::PrintOutsatndingPeople() const
{
	printOutstandingFootballers();
	printOutstandingCoaches();
	printOutstandingManagers();
	printOutstandingReferees();
}
void Ligat_HaAl::printOutstandingFootballers() const
{
	cout << "Outsatnding Footballers:" << endl;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < (*teamList)[i].getFootballersNum(); j++)
		{
			if ((teamList)[i]->getTeamFootballers()[j].isBest()) {
				(teamList)[i]->getTeamFootballers()[j].Print();
				cout << endl;
			}
		}
	}
}
void Ligat_HaAl::printOutstandingCoaches() const
{
	cout << "Outsatnding coaches:" << endl;
	for (int i = 0; i < T; i++)
	{
		if ((teamList)[i]->getTeamCoach().isBest()) {
			(teamList)[i]->getTeamCoach().Print();
			cout << endl;
		}
	}
}

void Ligat_HaAl::printOutstandingManagers() const
{
	cout << "Outsatnding Managers:" << endl;
	for (int i = 0; i < T; i++)
	{
		if ((teamList)[i]->getTeamManager().isBest()) {
			(teamList)[i]->getTeamManager().Print();
			cout << endl;
		}
	}
}

void Ligat_HaAl::printOutstandingReferees() const
{
	for (int i = 0; i < workerNum; i++)
	{
		Worker * help = dynamic_cast<Referee*>((workerList)[i]);
		if (help && (workerList)[i]->isBest()) {
			for (int j = 0; j < G; j++)
			{
				for (int k = 0; k < (*games)[j].getRefNum(); k++)
				{
					(games)[j]->getReferee(k)->Print();
				}
			}
		}
	}
}

void Ligat_HaAl::printTable()
{
	//Print table
	cout << "Ligat Ha'Al table:" << endl;
	string tempTeamName;
	int tempTeamPoints;
	string sortedTeams[] = {teams[0],teams[1], teams[2], teams[3], teams[4] };
	for (int i = 0; i < T; i++)
	{
		for (int j = i; j < T; j++) {
			if (points[i] < points[j]) {
				tempTeamName = sortedTeams[j];
				tempTeamPoints = points[j];
				sortedTeams[j] = sortedTeams[i];
				points[j] = points[i];
				sortedTeams[i] = tempTeamName;
				points[i] = tempTeamPoints;
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cout << sortedTeams[i] << "    \t" << points[i] << endl;
	}
}

void Ligat_HaAl::printSmallestSalary()
{
	float smallestSalary = (teamList)[0]->getTeamFootballers()[0].getSalary();
	Footballer f;
	f = (teamList)[0]->getTeamFootballers()[0];
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < (teamList)[i]->getFootballersNum(); j++)
		{
			if ((teamList)[i]->getTeamFootballers()[j].getSalary() < smallestSalary) {
				f = ((teamList)[i]->getTeamFootballers()[j]);
				smallestSalary = (teamList)[i]->getTeamFootballers()[j].getSalary();
			}
		}
	}
	cout << "Footballer with smallest salary is:" << endl;
	f.Print();
}

void Ligat_HaAl::addFootballer()
{
	Footballer *f = nullptr;
	bool isExist = false;
	f = new Footballer();
	string fTeam;
	getchar();
	cout << "Enter footballer team : ";
	do
	{
		getline(cin, fTeam);
		//Loop over teams array and check if team name is exist.
		for (int i = 0; i < T; i++)
		{
			if (fTeam == (teamList)[i]->getTeamName()) isExist = true;
		}
		if (!isExist) cout << "The team name you have entered is not part of league teams,enter again : ";
		//while loop requires from user to enter a name of team in the league.
	} while (!isExist);
	(*f).setFootballer(fTeam);
	Worker * help = dynamic_cast<Worker*>(f);
	if (help)
	{
		if (checkWorkerList(f)) cout << "person is already exist!";
		else {
			for (int i = 0; i < T; i++)
			{
				if (fTeam == (teamList)[i]->getTeamName()) {
					(teamList)[i]->addFootballer(f);
					cout << "Footballer added successfully" << endl;
				}
			}
			//adding footballer to selected team.
			addFootballerToWorkerList(f);
		}
	}
	f = nullptr;
	delete f;
}
void Ligat_HaAl::addReferee()
{
	Referee *r;
	r = new Referee;
	(*r).setReferee();
	Worker * help = dynamic_cast<Worker*>(r);
	if (help) {
		if (checkWorkerList(help)) cout << "person is already exist!";
		else {
			addRefereeToWorkerList(r);
			cout << "Referee added succesfully" << endl;
		}
		r = nullptr;
		delete r;
	}
}

bool Ligat_HaAl::checkWorkerList(const Worker* w)
{
	for (int i = 0; i < workerNum; i++)
	{
		if (w->getID() == (workerList)[i]->getID()) return true;
	}
	return false;
}

bool Ligat_HaAl::checkIfDatePassed(Game &game)
{
	Date today;
	today.CurrentDate();
	if (today.GetYear() < game.GetYear()) return true;
	if (today.GetYear() == game.GetYear() && today.GetMonth() < game.GetMonth()) return true;
	if (today.GetYear() == game.GetYear() &&
		today.GetMonth() == game.GetMonth() &&
		today.GetDay() < game.GetDay()) return true;
	return false;
}

Ligat_HaAl::Ligat_HaAl()
{
	int k = 0;
	workerNum = 5 * (15 + 2) + 4; //teams*(minimal num of players+coach+manager)+4 refs
	teamList = nullptr;
	workerList = nullptr;
	teamList = new Team*[T];
	workerList = new Worker*[workerNum];
	int m = 0, positionPlacemnet = 0;
	for (int i = 0; i < T; i++)
	{
		Stadium tempStadium(stadiums[i], cities[i], StdCapacity[i]);
		Footballer *tempList = new Footballer[15];
		for (int j = 0; j < 15; j++)
		{
			if (j >= 2 && j <= 4) positionPlacemnet = 1;
			if (j >= 5 && j <= 8) positionPlacemnet = 2;
			if (j >= 9 && j <= 11) positionPlacemnet = 3;
			if (j >= 12 && j <= 14) positionPlacemnet = 4;
			(tempList)[j] = Footballer(rand() % 25, Fnames[rand() % 15], Lnames[rand() % 10], to_string(10000 + (m++)), teams[i], position[positionPlacemnet]);//seniority,fName,lName,id,teamName,position
			(workerList)[k++] = new Footballer(tempList[j]);
		}
		Manager *tempManager = new Manager(rand() % 35, Fnames[rand() % 15], Lnames[rand() % 10], to_string(10000 + (m++)));
		Coach *tempCoach = new Coach(rand() % 35, Fnames[rand() % 15], Lnames[rand() % 10], to_string(10000 + (m++)), teams[i], rand() % 2, rand() % 20);
		teamList[i] = nullptr;
		//Dont know the others besides the first
		(teamList)[i] = new Team(teams[i], tempStadium, tempList, *tempCoach, *tempManager);
		(*teamList)[i].setPoints(0);
		(workerList)[k++] = new Coach(*tempCoach);
		(workerList)[k++] = new Manager(*tempManager);
	}
	//Add Referees to worker List
	for (int i = 0; i < refNum; i++)
	{
		Referee *tempRef = new Referee(rand() % 35, Fnames[rand() % 15], Lnames[rand() % 10], to_string(10000 + (m++)));
		workerList[k++] = new Referee(*tempRef);
	}
	buildSchedule();
}
Ligat_HaAl::~Ligat_HaAl()
{
	for (int i = 0; i < T; i++)
	{
		teamList[i] = nullptr;
		delete teamList[i];
	}
	teamList = nullptr;
	delete[] teamList;
	for (int i = 0; i < workerNum; i++)
	{
		workerList[i] = nullptr;
		delete workerList[i];
	}
	workerList = nullptr;
	delete[] workerList;
	for (int i = 0; i < G; i++)
	{
		games[i] = nullptr;
		delete games[i];
	}
	games = nullptr;
	delete[] games;
}
void Ligat_HaAl::Menu()
{
	int option;
	do {
		cout << endl << "Ligat Ha'al menu : \n";
		cout << "1.Add footballer\n2.Add Referee\n3.Print team details\n4.Print referee details\n5.print future game details\n";
		cout << "6.Print worker salary\n7.Add judgment errors\n8.people outstanding Print\n9.Print table\n";
		cout << "10.Print footballer details with smallest salary\n11.exit\n\n";
		cout << "Enter an option : ";
		cin >> option;
		switch (option) {
		case 1:addFootballer();
			break;
		case 2:addReferee();
			break;
		case 3:PrintTeamDetalis();
			break;
		case 4:PrintRefereeDetails();
			break;
		case 5:PrintFutureGamesDetails();
			break;
		case 6:PrintWorkerSalary();
			break;
		case 7:addJudgemntErrors();
			break;
		case 8:PrintOutsatndingPeople();
			break;
		case 9:printTable();
			break;
		case 10:printSmallestSalary();
			break;
		case 11:cout << "Goodbye!" << endl;
			break;
		}
	} while (option != 12);
}
