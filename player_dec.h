#include <stdio.h>
#include <stdlib.h>

typedef struct Player
{
	int j_no;
	char name[50];
	int no_of_matches;
	int no_of_runs;
	int no_of_wickets;
}Player;

extern int ctr;

void hardCodedData(Player*);
void storeData(Player*, int);
void displayData(Player*);
void searchPlayer(Player*);
int searchByJNo(Player*,int);
int searchByJName(Player*,char*);
void updatePlayer(Player*);
void updateMatches(Player*);
void updateRuns(Player*);
void updateWickets(Player*);
void sortingPlayer(Player*);
void sortByMatches(Player*);
void sortByRuns(Player*);
void sortByWickets(Player*);
void deletePlayer(Player*);
void deleteByName(Player*,char*);
void deleteByJNo(Player*,int);
