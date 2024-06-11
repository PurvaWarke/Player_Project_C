#include <stdio.h>
#include <stdlib.h>
#include"player_dec.h"

void main()
{
	int arr_size=50;
	Player arr[arr_size];
	hardCodedData(arr);
	int choice;
	do
	{
		printf("\n-*-*-*-*-*- Player Management System -*-*-*-*-*-\n\n");
		printf("\t\t1.Add Player \n\t\t2.Display Players \n\t\t3.Search Player \n\t\t4.Delete Player \n\t\t5.Update Player \n\t\t6.Sorting Player \n\t\t7.Exit\n");
		
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
			{
				storeData(arr,arr_size);
				break;	
			}
			case 2:
			{
				displayData(arr);
				break;	
			}
			case 3:
			{
				searchPlayer(arr);
				break;	
			}
			case 4:
			{
				deletePlayer(arr);
				break;	
			}
			case 5:
			{
				updatePlayer(arr);
				break;	
			}
			case 6:
			{
				sortingPlayer(arr);
				break;	
			}
			case 7:	
			{
				printf("Exiting Program. Thank You !\n");
				break;	
			}
			default:
			{
				printf("\nPlease Enter Valid Choice !");
			}
		}
	}while(choice!=7);
}