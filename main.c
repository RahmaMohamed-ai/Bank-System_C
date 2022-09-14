#include "STD_TYPES.h"

#include <stdio.h>

#include "Admin_Window/Admin_W.h"
#include "BIT_MATH.h"
#include "Client_Window/Client_W.h"

#define FULL_NAME_SIZE				40
#define FULL_ADDRESS_SIZE			100
#define NATIONAL_ID_NO_OF_DIGITS	14
#define ACCOUNT_STATUS_SIZE			20
#define BANK_ACCOUNT_ID				10
#define USER_NAME_SIZE				20
#define ARR_OF_EMPLOYEES_SIZE		5

typedef struct Bank_AC{
	u8 Full_Name[FULL_NAME_SIZE];
	u8 Full_Address[FULL_ADDRESS_SIZE];
	u8 National_ID[NATIONAL_ID_NO_OF_DIGITS];
	u8 Age;// Logically No One Will Reach to 255 Years old
	u8 Bank_Account_ID[BANK_ACCOUNT_ID];
	 u8 Guardian[FULL_NAME_SIZE];
	u8 Guardian_National_ID[NATIONAL_ID_NO_OF_DIGITS];
	u8 Account_Status[ACCOUNT_STATUS_SIZE];
	u32 Balance; // stored limit: 4,294,967,293
	u32 Password;// the same

}Bank_Account;

typedef struct Adm_Info{

	u8 UserName[USER_NAME_SIZE]; //from two words
	u32 Password;

}Admin_Info_t;


int main(void)
{
	u8 Choice;
	printf("Welcome to ITI Bank System\nEnter 1 : Admin Window\nEnter 2 :Client Window\n");
	scanf("%d", &Choice);

	Checking_Choice(Choice);

	return 0;
}

void Checking_Choice(u8 Choice)
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
		Trails_counter++;

		if(u32 Trails_counter != 3)
		{
			goto Admin_Data_Entry;
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
