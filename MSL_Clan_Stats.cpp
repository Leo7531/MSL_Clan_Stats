/*	
	To Do:
	-Calculate the daily progress
	-Calculate the weekly progress
	-Generate percentages that show increase/decrease
	
	Prototype
	-If its possible to calculate the difference between previous day and current day in terms of damage
	-A week based file system that compiles the total damage dealt by all players in all days (heavy number crunching)
	-Graph based system? or table?
*/


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>

using namespace std;

struct Player{
	string IGN;//in game name, also can be used for identifier?
	int main_Elem_Pref=0,
		/*0-Light,
		  1-Dark, 
		  2 - Wood, 
		  3 -Water, 
		  4 - Fire*/
		lowest_Damage=0,
		Titan_Lowest=0,//on which titan was the lowest dmg dealt
		Highest_Damage=0,//players record for the highest dmg
		Titan_Highest=0,//on which titan was the highest dmg dealt
		Rank=0;
	int playerDmg[15][3][2]={{{0,0}}};
	/* To be used in accordance with the stats from excel chart
	Player Dmg Format: 
		0 - TeamA, 1 - TeamB, 2 - TeamC
		0-2 Light 
		3-5 Wood
		6-8 Water
		9-11 Dark
		12-14 Fire
		
		3rd dimension var
		0 - min dmg
		1 - max dmg
	*/
	double percent_increase=0;//stat to calculate either daily or weekly if the person is increasing/decreasing or staying neutral

};

struct Day {
	const int Max_participation = 180;
	int Num_players;//players participated today
	int total_dmg;
	
};

struct Week{
	const int Max_participation = 1080;
	int total_dmg;
};

struct Titan{///< Data to be loaded in from editable file containing titan health
	int HP;
	int Lvl;
	int type;/*0 - Light,1 - Wood,2 - Water,3 - Dark,4 - Fire*/
};

///< Global Vars
Player ClanMembers[30];



///< Declarations
void Menu();
int calcTotalDmg();
double calcPercentage(int NumA, int NumB){ return (NumA/NumB)*100;}


//////////////////////////

int main(){
	
	Menu();
		
	return 0;
}

void Menu(){
	int numItems=7;
	string menu[numItems][20]={"View Day Score","Edit Day","Add Day","View Week"};
	for(int i=0;i<numItems;i++){
		
	}
}

int calcTotalDmg(int MinOrMax){
	/*
	Format: 0 - Team A, 1 - Team B, 2 - Team C
		0-2 Light 
		3-5 Wood
		6-8 Water
		9-11 Dark
		12-14 Fire
	*/
	struct TitanDmg{
		int Min;
		int Max;
	};
	
	int Total_Min_Dmg=0,Total_Max_Dmg=0;
	TitanDmg Titans[5]={{0,0}};
	/*0-Light,
	  1-Dark,
	  2 - Wood,
	  3 -Water,
	  4 - Fire*/
	
	for(int i=0;i<30;i++)
	{
		for(int x=0; x<15;x++)
		{
			for(int y=0;y<3;y++)
			{
				for(int z=0;z<=1;z++)
				{
					if(ClanMembers[i].playerDmg[x][y][z]>0)///< Check to see if damage
					{
						if(x>=0&&x<3){///< Light Titan
							if(z=0)
								Titans[0].Min +=ClanMembers[i].playerDmg[x][y][z];
							else Titans[0].Max +=ClanMembers[i].playerDmg[x][y][z];
						}else 
						if(x>=3&&x<=5){///< Wood Titan
							if(z=0)
								Titans[1].Min +=ClanMembers[i].playerDmg[x][y][z];
							else Titans[1].Max +=ClanMembers[i].playerDmg[x][y][z];
						}else 
						if(x>=6&&x<=8){///< Water Titan
							if(z=0)
								Titans[2].Min +=ClanMembers[i].playerDmg[x][y][z];
							else Titans[2].Max +=ClanMembers[i].playerDmg[x][y][z];
						}else 
						if(x>=9&&x<=11){///< Dark Titan
							if(z=0)
								Titans[3].Min +=ClanMembers[i].playerDmg[x][y][z];
							else Titans[3].Max +=ClanMembers[i].playerDmg[x][y][z];
						}else 
						if(x>=12&&x<15){///< Fire Titan
							if(z=0)
								Titans[4].Min +=ClanMembers[i].playerDmg[x][y][z];
							else Titans[4].Max +=ClanMembers[i].playerDmg[x][y][z];
						}
					}
				}
			}
		}
	}
	
	for(int i=0;i<5;i++){
		Total_Min_Dmg += Titans[i].Min;
		Total_Max_Dmg += Titans[i].Max;
	}
	
	if(MinOrMax = 0)
		return Total_Min_Dmg;
	else return Total_Max_Dmg;
}


