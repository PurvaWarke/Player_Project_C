#include <stdio.h>
#include<string.h>
#include"player_dec.h"

int ctr=0;
void storeData(Player* arr,int arr_size)
{
		if(ctr<arr_size)
		{
			printf("\nEnter Jersey Number : ");
			scanf("%d",&arr[ctr].j_no);
			printf("\nEnter Player Name : ");
			scanf("%s",arr[ctr].name);
			printf("\nEnter Number of Matches : ");
			scanf("%d",&arr[ctr].no_of_matches);
			printf("\nEnter Number of Runs : ");
			scanf("%d",&arr[ctr].no_of_runs);
			printf("\nEnter Number of Wickets : ");
			scanf("%d",&arr[ctr].no_of_wickets);
			ctr++;
		}	
}
void displayData(Player* arr)
{
	printf("\n-*-*-*-*-*- All Players List -*-*-*-*-*-\n\n");
	printf("--------------------------------------------------------");
	printf("\nJ_No |      Player Name     |  Match |\tRuns | Wickets | \n");
	printf("--------------------------------------------------------");
	for(int i=0;i<ctr;i++)
	{
		printf("\n%-5d|\t%-20s|\t%-5d|\t%-5d|\t  %-5d|",arr[i].j_no,arr[i].name,arr[i].no_of_matches,arr[i].no_of_runs,arr[i].no_of_wickets);
	}
	printf("\n--------------------------------------------------------\n");
}
void searchPlayer(Player* arr)
{
	int choice;
	printf("\n\n-------- Player Management System --------\n");
	printf("\n-1.Search By Jersey Number \n-2.Search By Name \n-3.Back\n");	
		do{
			printf("\nEnter Choice : ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					{
						int jno;
						printf("\nEnter Jersey Number Want to Search : ");
						scanf("%d",&jno);
						int res = searchByJNo(arr,jno);
						if(res==-1)
							printf("\n%d Not a Player ! Please Enter Valid Player. \n",jno);
						else
						{
							printf("\n--------------------------------------------------------");
							printf("\nJ_No |      Player Name     |  Match |\tRuns | Wickets | \n");
							printf("--------------------------------------------------------");
							printf("\n%-5d|\t%-20s|\t%-5d|\t%-5d|\t  %-5d|",arr[res].j_no,arr[res].name,arr[res].no_of_matches,arr[res].no_of_runs,arr[res].no_of_wickets);	
							printf("\n--------------------------------------------------------\n");
						}
						break;
					}
				case 2:
					{
						char str[50];
						printf("\nEnter Name Want to Search : ");
						scanf("%s",str);
						int res = searchByJName(arr,str);
						if(res==-1)
							printf("\n%s Not a Player ! Please Enter Valid Player.",str);
						else
						{
							printf("\n--------------------------------------------------------");
							printf("\nJ_No |      Player Name     |  Match |\tRuns | Wickets | \n");
							printf("--------------------------------------------------------");
							printf("\n%-5d|\t%-20s|\t%-5d|\t%-5d|\t  %-5d|",arr[res].j_no,arr[res].name,arr[res].no_of_matches,arr[res].no_of_runs,arr[res].no_of_wickets);
							printf("\n--------------------------------------------------------\n");	
						}
						break;	
					}
				default:
					{
						printf("\n");
					}
			}
		}while(choice!=3);
}
int searchByJNo(Player* arr,int jno)
{
	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].j_no==jno)
		{
			flag=1;
			return i;
		}
	}
	if(flag==0)
		return -1;
}
int searchByJName(Player* arr,char* str)
{	
	for(int i=0;i<ctr;i++)
	{
		if(strcmp(arr[i].name,str)==0)
			return i;
	}
	return -1;
}
void updatePlayer(Player* arr)
{
	int choice;
	printf("\n\n------ Player Management System ------\n\n");
	printf("-1.Update Matches \n-2.Update Runs \n-3.Update Wickets \n-4.Back \n");
	
	do{
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					updateMatches(arr);
					break;	
				}
			case 2:
				{
					updateRuns(arr);
					break;	
				}
			case 3:
				{
					updateWickets(arr);
					break;	
				}
			default:
				{
					printf("\nPlease Enter Valid Choice !\n");
				}
		}		
	}while(choice!=4);
}
void updateMatches(Player* arr)
{

	int jno,update_match;
	printf("\nEnter Player's Jersey Number Want Update : ");
	scanf("%d",&jno);	
	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].j_no==jno)
		{
			printf("\nEnter Update Matches : ");
			scanf("%d",&update_match);
			arr[i].no_of_matches=update_match;
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\n%d Not a Player ! Please Enter Valid Player.\n",jno);
	displayData(arr);
}
void updateRuns(Player* arr)
{
	int jno;
	printf("\nEnter Player's Jersey Number Want Update : ");
	scanf("%d",&jno);
	int update_runs;
	int flag=0;
		
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].j_no==jno)
		{
			printf("\nEnter Update Runs : ");
			scanf("%d",&update_runs);
			arr[i].no_of_runs=update_runs;
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\n%d Not a Player ! Please Enter Valid Player.\n",jno);
	displayData(arr);
}
void updateWickets(Player* arr)
{
	int jno,update_wickets;
	printf("\nEnter Player's Jersey Number Want Update : ");
	scanf("%d",&jno);

	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].j_no==jno)
		{
			printf("\nEnter Update Wickets : ");
			scanf("%d",&update_wickets);
			arr[i].no_of_wickets=update_wickets;
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\n%d Not a Player ! Please Enter Valid Player.\n",jno);
	displayData(arr);
}
void sortingPlayer(Player* arr)
{
	int choice;
	printf("\n\n------ Player Management System ------\n");
	printf("\n-1.Sort By Matches \n-2.Sort By Runs \n-3.Sort By Wickets \n-4.Back\n");

	do{
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					sortByMatches(arr);
					break;	
				}
			case 2:
				{
					sortByRuns(arr);
					break;	
				}
			case 3:
				{
					sortByWickets(arr);
					break;	
				}
			default:
				{
					printf("\nPlease Enter Valid Choice ! \n");
				}
		}
	}while(choice!=4);
	
}
void sortByMatches(Player* arr)
{
	for(int i=0;i<ctr;i++)
	{
		for(int j=i+1;j<ctr;j++)
		{
			if(arr[i].no_of_matches>arr[j].no_of_matches)
			{
				Player temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	displayData(arr);
}
void sortByRuns(Player* arr)
{
	for(int i=0;i<ctr;i++)
	{
		for(int j=i+1;j<ctr;j++)
		{
			if(arr[i].no_of_runs>arr[j].no_of_runs)
			{
				Player temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	displayData(arr);
}
void sortByWickets(Player* arr)
{
	for(int i=0;i<ctr;i++)
	{
		for(int j=i+1;j<ctr;j++)
		{
			if(arr[i].no_of_wickets>arr[j].no_of_wickets)
			{
				Player temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	displayData(arr);
}
void deletePlayer(Player* arr)
{
	int delete_player;
	printf("\nEnter Jersey Number Want to Delete : ");
	scanf("%d",&delete_player);
	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].j_no==delete_player)
		{
			arr[i]=arr[i+1];
			flag=1;
			ctr=ctr-1;
			printf("\nPlayer Deleted Succesfully !\n");
		}
		else if(flag==1)
			arr[i]=arr[i+1];			
	}
	if(flag==0)
		printf("\n%d Not a Player ! Please Enter Valid Player.\n",delete_player);
	displayData(arr);
}
void deleteByJNo(Player* arr,int delete_player)
{
	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].j_no==delete_player)
		{
			arr[i]=arr[i+1];
			flag=1;
			ctr=ctr-1;
			printf("\nPlayer Deleted Succesfully !\n");
		}
		else if(flag==1)
			arr[i]=arr[i+1];			
	}
	if(flag==0)
		printf("\n%d Not a Player ! Please Enter Valid Player.\n",delete_player);
	displayData(arr);
}

void hardCodedData(Player* arr)
{
	arr[0].j_no=7;
	strcpy(arr[0].name,"MS_Dhoni");
	arr[0].no_of_matches=145;
	arr[0].no_of_runs=301;
	arr[0].no_of_wickets=8;
	ctr++;
	
	arr[1].j_no=18;
	strcpy(arr[1].name,"Virat_Kohli");
	arr[1].no_of_matches=32;
	arr[1].no_of_runs=205;
	arr[1].no_of_wickets=10;
	ctr++;

	arr[2].j_no=10;
	strcpy(arr[2].name,"Sachin_Tendulkar");
	arr[2].no_of_matches=62;
	arr[2].no_of_runs=600;
	arr[2].no_of_wickets=5;
	ctr++;
}