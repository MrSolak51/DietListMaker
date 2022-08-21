#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printPersonalInfo(float weight, int height, int year, char gender, int choose, int chooseW, float BMR, float calorie_requirement){
	char genderS[100]=" ";
	char activity[100]=" ";
	char goal[100]=" ";

	switch (choose)
	{
	case 1: strcpy(activity,"Sedanter"); break;
	case 2: strcpy(activity,"Low"); break;
	case 3: strcpy(activity,"Normal"); break;
	case 4: strcpy(activity,"Active"); break;
	case 5: strcpy(activity,"Competitive"); break;
	}
	switch (chooseW)
	{
	case 1: strcpy(goal,"Lose Weight"); break;
	case 2: strcpy(goal,"Save weight"); break;
	case 3: strcpy(goal,"Gain weight"); break;
	}
	if (gender == 'm')
	{
		strcpy(genderS,"Man");
	}
	else
	{
		strcpy(genderS,"Woman");
	}
	
	FILE *file=fopen("personalInfo.txt","w");
	fprintf(file,"Weight : %f cm \nHeight : %d kg \nAge : %d \nGender : %s \nActivity : %s\nGoal : %s \nBMR : %f cal\nCalorie Requiement : %f cal/day", weight, height, year, genderS, activity, goal, BMR, calorie_requirement);
}

float calorie_requirement(float BMR, int choose){
	float activity;
	switch (choose)
	{
	case 1: activity = 1.2; break;
	case 2: activity = 1.375; break;
	case 3: activity = 1.55; break;
	case 4: activity = 1.725; break;
	case 5: activity = 1.9; break;
	}
	float requirement = BMR * activity;
	printf("\nYour daily calorie requirement is %f", requirement); 
	return requirement;
}

void printDietList(short breakfast[],short lunch[],short dinner[],short snacks1[],short snacks2[]){
	printf("Breakfast\n\tEgg : %d\n\tBreast : %d\n\tChese : %d\n\tOlive : %d",breakfast[0],breakfast[1],breakfast[2],breakfast[3]);
	printf("\n\nSnacks\n\tFruit : %d\n\tMilk : %d",snacks1[0],snacks1[1]);
	printf("\n\nLunch\n\tMeat : %d\n\tBreast : %d",lunch[0],lunch[1]);
	printf("\n\nSnacks\n\tFruit : %d\n\tMilk : %d",snacks2[0],snacks2[1]);
	printf("\n\nDinner\n\tEt Yemegi : %d\n\tRice : %d\n\tBreast : %d",dinner[0],dinner[1],dinner[2]);

	FILE *file=fopen("dietList.txt","w");
	fprintf(file,"Breakfast\n\tEgg : %d\n\tBreast : %d\n\tChese : %d\n\tOlive : %d\n\nSnacks\n\tFruit : %d\n\tMilk : %d\n\nLunch\n\tMeat : %d\n\tBreast : %d\n\nSnacks\n\tFruit : %d\n\tMilk : %d\n\nDinner\n\tEt Yemegi : %d\n\tRice : %d\n\tBreast : %d",breakfast[0],breakfast[1],breakfast[2],breakfast[3],snacks1[0],snacks1[1],lunch[0],lunch[1],snacks2[0],snacks2[1],dinner[0],dinner[1],dinner[2]);
}

void dietList(float calorie_requirement){
	float calorie_requirement_=calorie_requirement;
	int egg = 77;
	int cheese = 93;
	int olive = 5;
	int breast = 103;
	int fruit = 131;
	int milk = 128;
	int meat = 60;
	int rice= 34;
	int etYemegi=30;
	float breakfast;
	float lunch;
	float dinner;
	float snacks1,snacks2;


	short dinnerBreast = 2;
	short lunchBreast = 1;
	short breakfastBreast = 2;

	short breakfastEgg = 2;

	short breakfastCheese = 1;

	short lunchMeat = 3;

	short DinnerEtYemegi = 5;
	
	short DinnerRice = 5;

	short fruits1=1;
	short fruits2=1;
	short milks1=1;
	short milks2=1;

	short breakfastOlive=5;


	breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
	snacks1 = (fruit*fruits1 + milk*milks1);
	lunch = (meat*lunchMeat + breast*lunchBreast);
	snacks2 = (fruit*fruits2 + milk*milks2);
	dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

	calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
	printf("\n\n\n\n\n\n%f", calorie_requirement_);
	while (calorie_requirement_<-25 || calorie_requirement_>25)
	{
		if (calorie_requirement_<-25)
		{
			if (dinnerBreast!=0)
			{
				dinnerBreast--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (lunchBreast!=0)
			{
				lunchBreast--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (breakfastBreast!=0)
			{
				breakfastBreast--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (DinnerRice!=0)
			{
				DinnerRice--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (fruits2!=0)
			{
				fruits2--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (fruits1!=0)
			{
				fruits1--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (breakfastOlive!=0)
			{
				breakfastOlive--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (milks2!=0)
			{
				milks2--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (milks1!=0)
			{
				milks1--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (DinnerEtYemegi!=0)
			{
				DinnerEtYemegi--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (DinnerEtYemegi!=0)
			{
				DinnerEtYemegi--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (breakfastEgg!=0)
			{
				breakfastEgg--;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);

				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else
			{
				printf("This calorie will kill you my friend!");
				exit(0);
			}
			
		}

		else if(calorie_requirement_>25)
		{
			if (breakfastEgg != 5)
			{
				breakfastEgg++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (breakfastCheese != 3)
			{
				breakfastCheese++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (lunchMeat != 7)
			{
				lunchMeat++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (DinnerEtYemegi != 10)
			{
				DinnerEtYemegi++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (milks1 != 2)
			{
				milks1++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (breakfastOlive != 10)
			{
				breakfastOlive++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (breakfastBreast != 5)
			{
				breakfastBreast++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (lunchBreast != 5)
			{
				lunchBreast++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (DinnerRice != 10)
			{
				DinnerRice++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (dinnerBreast != 5)
			{
				dinnerBreast++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (fruits1 != 2)
			{
				fruits1++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else if (fruits2 != 2)
			{
				fruits2++;
				calorie_requirement_=calorie_requirement;
				breakfast = (egg*breakfastEgg + breast*breakfastBreast + cheese*breakfastCheese + olive*breakfastOlive);
				snacks1 = (fruit*fruits1 + milk*milks1);
				lunch = (meat*lunchMeat + breast*lunchBreast);
				snacks2 = (fruit*fruits2 + milk*milks2);
				dinner = (etYemegi*DinnerEtYemegi + rice*DinnerRice +breast*dinnerBreast);
				calorie_requirement_ -= (breakfast + snacks1 + lunch + snacks2 + dinner);
			}
			else
			{
				printf("\nThis is too much calorie! Sorry but I can't help you :c");
				exit(0);
			}
			
		}
	}
	short breakfast_[] = {breakfastEgg,breakfastBreast,breakfastCheese,breakfastOlive};
	short lunch_[] = {lunchMeat,lunchBreast};
	short dinner_[] = {DinnerEtYemegi,DinnerRice,dinnerBreast};
	short snacks1_[] = {fruits1,milks1};
	short snacks2_[] = {fruits2,milks2};
	printDietList(breakfast_,lunch_,dinner_,snacks1_,snacks2_);

}

void macros(float calorie_requirement,float weight){
	float carb, fat=(calorie_requirement*28), pro = weight*0.9;
	fat /= 100;
	fat /=9;
	carb = (calorie_requirement - ((fat*9) + (pro*4))) / 4;

	printf("\ncarbonhidrate: %f gr, protein: %f gr, fat: %f gr",carb, pro, fat);
	dietList(calorie_requirement);

}

float manBMR(float weight, int height, int year){
	float bmr =	(10 * weight) + (6.25 * height) - (5 * year) + 5;
	return bmr;
}

float womanBMR(float weight, int height, int year){
	float bmr =	(10 * weight) + (6.25 * height) - (5 * year) - 161;
	return bmr;
}

void main() {
	printf("------------------       ------              ------\n");
	printf("--------------------      ------            ------\n");
	printf("----------------------     ------          ------\n");
	printf("---             ------      ------        ------\n");
	printf("---               ----       ------      ------\n");
	printf("---                ---        ------    ------\n");
	printf("---                ---          ------------\n");
	printf("---                ---           ----------\n");
	printf("---                ---            --------\n");
	printf("---                ---             ------\n");
	printf("---                ---             ------\n");
	printf("---                ---             ------\n");
	printf("---                ---             ------\n");
	printf("---             ------             ------\n");
	printf("----------------------             ------\n");
	printf("--------------------               ------\n");
	printf("------------------                 ------");
	printf("\nWelcome to the Diet Writer");
	printf("\nNote: The list to be created is a completely made-up list. \nIt is highly recommended to consult your doctor!!!!!!!!!!!!");
	int choose, chooseW,a;
	float weight, bmr, cal;
	int height, year;
	char gender;

	printf("\n\nHow tall are you : (cm)");
	scanf("%d", &height);

	printf("\nHow heavy are you : (kg)");
	scanf("%f", &weight);

	printf("\nHow old are you : ");
	scanf("%d", &year);

	printf("\nWhat is your gender : (m/w)");
	scanf(" %c", &gender);

	printf("\nHow active are you during the day : \n1-Sedanter \n2-Low Activity \n3-normal \n4-very active \n5-competitive athlete\nYour choose : ");
	scanf(" %d", &choose);

	printf("\nWhat is your goal : \n1-Lose weight \n2-Save weight \n3-Gain weight \nYour choose : ");
	scanf(" %d", &chooseW);

	if (gender == 'm')
	{
		bmr = manBMR(weight, height, year);
	}
	else if(gender == 'w')
	{
		bmr = womanBMR(weight, height, year);
	}
	else{
		printf("\nInput unacceptable");
	}

	cal = calorie_requirement(bmr, choose);

	switch (chooseW)
	{
	case 1:cal -= 300; break;
	case 2:break;
	case 3:cal += 300; break;
	default:printf("\nInput unacceptable"); break;
	}
	printPersonalInfo(weight, height, year, gender, choose, chooseW, bmr, cal);
	macros(cal,weight);
	printf("\nEnter 0 for exit...");
	scanf("%d",&a);
	if (a==0)exit(0);
}