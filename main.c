#include "STD_TYPES.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Admin_Window/Admin_W.h"
#include "BIT_MATH.h"
#include "Client_Window/Client_W.h"

#define FULL_NAME_SIZE				40
#define FULL_ADDRESS_SIZE			100
#define NATIONAL_ID_NO_OF_DIGITS	14
#define ACCOUNT_STATUS_SIZE			20
#define BANK_ACCOUNT_ID				10
#define PASS_CAPACITY				10

#define USER_NAME_SIZE				20
#define ARR_OF_EMPLOYEES_SIZE		5
#define AGE_LIMIT					21

typedef struct Bank_AC{
	u8 Full_Name[FULL_NAME_SIZE];
	u8 Full_Address[FULL_ADDRESS_SIZE];
	u8 National_ID[NATIONAL_ID_NO_OF_DIGITS];
	u8 Age;// Logically No One Will Reach to 255 Years old
	u8 Bank_Account_ID[BANK_ACCOUNT_ID];
	 u8 Guardian[FULL_NAME_SIZE];
	u8 Guardian_National_ID[NATIONAL_ID_NO_OF_DIGITS];
	u8 Account_Status[ACCOUNT_STATUS_SIZE];
	u8 Password[PASS_CAPACITY];// Upper and lower Case Letters mixed with sympols & numbers
	u32 Balance; // stored limit: 4,294,967,293
}Bank_Account_t;

typedef struct Adm_Info{

	u8 UserName[USER_NAME_SIZE]; //from two words
	u32 Password;

}Admin_Info_t;

void Admin_Window(void);
void Checking_Choice(u32 Choice);
u32 Admin_Info_Validation(Admin_Info_t Admin_Input);
void Creating_BA_pass(u32 Pass_Capacity);
void Create_New_ACC(void);
void Adjusting_Acc_stat(void);
void Open_ACC(void);

void Client_Window(void);


int main(void)
{
	u32 Choice;
	printf("Welcome to ITI Bank System\n");
	printf("Enter 1 : Admin Window\nEnter 2 :Client Window\n");
	
	scanf("%d", &Choice);

	Checking_Choice(Choice);

	return 0;
}

void Checking_Choice(u32 Choice)
{
	if(Choice == 1)
	{
		Admin_Window();
	}
	else if(Choice == 2)
	{
		Client_Window();
	}
	else
	{
		printf("Invalid Input...Please Try again\n");
		Checking_Choice(Choice);
	}
}

void Admin_Window(void)
{
	printf("---------------------Admin Window-------------------\n");

	Admin_Info_t Admin_Input;
	u32 Validation_Ret;
	u32 Trails_counter = 1;

	Admin_Data_Entry:
	printf("User Name:		\n");
	scanf("%c", &Admin_Input.UserName);

	printf("Password:		\n");
	scanf("%c", &Admin_Input.Password);

	Validation_Ret = Admin_Info_Validation(Admin_Input);
	if(Validation_Ret == -1)
	{
		printf("Sorry.. No Such Admin Found\nPlease Enter Your Data Correctly\n");
		Trails_counter++;//detecting that it is the second trail: Trails_counter = 2;

		if(Trails_counter != 3)
		{
			goto Admin_Data_Entry;
		}
	}
	else
	{
		//After Validation Admin Window
		Main_Screen:
		u32 Choice;
		
		printf("1: Create New Account\n");
		printf("2: Open Existing Account\n");
		printf("3: Exit System\n");
		scanf("%d", &Choice);
		
		switch(Choice)
		{
			case 1:printf("---------Create New Account---------\n");
					Create_New_ACC();
					goto Main_Screen;
			break;
			
			case 2:printf("----------Open Account---------\n");
					Open_ACC();
					goto Main_Screen;
			break;
			
			case 3:printf("Thank you for Using Our System...\n");
					printf("GOOD BYE\n");
			break;
			
			default: printf("Invalid Choise!!!....Try Again\n");
					 goto Main_Screen;
			break;
		}
		
	}


}

u32 Admin_Info_Validation(Admin_Info_t Admin_Input)
{
	Admin_Info_t Employee1, Employee2 , Employee3, Employee4 ,Employee5;

	Employee1.UserName = "Admin 1";
	Employee2.UserName = "Admin 2";
	Employee3.UserName = "Admin 3";
	Employee4.UserName = "Admin 4";
	Employee5.UserName = "Admin 5";

	Employee1.Password = 2525;
	Employee2.Password= 2526;
	Employee3.Password = 2527;
	Employee4.Password = 2528;
	Employee5.Password = 2529;

	Admin_Info_t Arr_of_Employees[ARR_OF_EMPLOYEES_SIZE] = {Employee1, Employee2 , Employee3, Employee4 ,Employee5};

	for(u32 i = 0; i < ARR_OF_EMPLOYEES_SIZE; i++)
	{
		if(Admin_Input == Arr_of_Employees[i])
		{
			return 1;
		}
	}
	return -1;
}
void Create_New_ACC(void)
{
	Bank_Account_t New_Acc;
	
	New_Acc.Guardian = "ACTIVE ACCOUNT";
	
	printf("Full_Name: ");
	scanf("%s", &New_Acc.Full_Name);
	
	printf("Full_Address: ");
	scanf("%s", &New_Acc.Full_Address);
	
	printf("National_ID: ");
	scanf("%s", &New_Acc.National_ID);
	
	printf("Age: ");
	scanf("%s", &New_Acc.Age);
	
	if(New_Acc.Age < AGE_LIMIT)
	{
		printf("Ok..You have to enter Your Gardian Info too\n");
		printf("Guardian: ");
		scanf("%s", &New_Acc.Guardian);
		
		printf("Guardian_National_ID: ");
		scanf("%s", &New_Acc.Guardian_National_ID);
	}
	
	printf("Bank_Account_ID: ");
	scanf("%s", &New_Acc.Bank_Account_ID);
	
	printf("Balance: ");
	scanf("%s", &New_Acc.Balance);
	
	printf("Password Created For You: %s\n",Creating_BA_pass(PASS_CAPACITY); );
}

void Adjusting_Acc_stat(void)
{
	/* if() */
}

void Creating_BA_pass(u32 Pass_Capacity)
{
	int i = 0;
    int randomizer = 0;
	char numbers[] = "0123456789";
	char letter[] = "abcdefghijklmnoqprstuvwyzx";
	char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
	char symbols[] = "!@#$^&*?";
	char password[PASS_CAPACITY];
	
	srand((unsigned int)(time(NULL)));
	randomizer = rand() % 4;//to select randomizer inside the loop
	for (i = 0; i < PASS_CAPACITY; i++) {

		if (randomizer == 1) {
			password[i] = numbers[rand() % 10];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else if (randomizer == 2) {
			password[i] = symbols[rand() % 8];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else if (randomizer == 3) {
			password[i] = LETTER[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
		else {
			password[i] = letter[rand() % 26];
			randomizer = rand() % 4;
			printf("%c", password[i]);
		}
    }
}

void Open_ACC(void)
{
	
}