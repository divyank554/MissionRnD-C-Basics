/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int valid(char *input)
{

	int year = 0;
	int i;
	for (i = 6; i < 10; i++)
	{
		if (i == 6)
			year = year + ((input[6] - '0') * 1000);
		if (i == 7)
			year = year + ((input[7] - '0') * 100);
		if (i == 8)
			year = year + ((input[8] - '0') * 10);
		if (i == 9)
			year = year + (input[9] - '0');
	}
	int month = 0;
	for (i = 3; i < 5; i++)
	{
		if (i == 3)
			month = month + ((input[3] - '0') * 10);
		if (i == 4)
			month = month + (input[4] - '0');
	}

	int day = 0;
	for (i = 0; i < 2; i++)
	{
		if (i == 1)
			day = day + (input[1] - '0');
		if (i == 0)
			day = day + ((input[0] - '0') * 10);

	}
	int flag = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 0 && day < 32)
			flag = 1;
		else
			flag = 0;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 0 && day < 31)
			flag = 1;
		else
			flag = 0;
	}

	if (month == 2)
	{
		if (year % 400 == 0)
		{
			if (day > 0 && day < 30)
				flag = 1;
			else
				flag = 0;
		}
		else if (year % 100 == 0)
		{
			if (day > 0 && day < 30)
				flag = 0;
			else
				flag = 1;
		}

		else
		if (year % 4 == 0)
		{
			if (day > 0 && day < 30)
				flag = 1;
			else
				flag = 0;
		}
		else
		{
			if (day > 0 && day < 29)
				flag = 1;
			else
				flag = 0;
		}
	}

	return flag;
}

int isOlder(char *dob1, char *dob2) {

	int flag;
	flag = valid(dob1);
	if (flag == 0)
		return -1;
	flag = valid(dob2);
	if (flag == 0)
		return -1;

	int temp = 0;
	int i;
	for (i = 6; i<10; i++)
	{
		if (dob1[i] - '\0' > dob2[i] - '\0')
			return 2;
		else if (dob1[i] - '\0' < dob2[i] - '\0')
			return 1;
		else
			temp++;
	}


	if (temp == 4)
	{
		for (i = 3; i<5; i++)
		{
			if (dob1[i] - '\0' > dob2[i] - '\0')
				return 2;
			else if (dob1[i] - '\0' < dob2[i] - '\0')
				return 1;
			else
				temp++;
		}

		if (temp == 6)
		{
			for (i = 0; i<2; i++)
			{
				if (dob1[i] - '\0' > dob2[i] - '\0')
					return 2;
				else if (dob1[i] - '\0' < dob2[i] - '\0')
					return 1;
				else
					temp++;
			}
		}
	}

	if (temp == 8)
		return 0;

}
