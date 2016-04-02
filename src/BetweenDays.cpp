/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int months(int month, int year)
{
	int i,days=0;
	for (i = 0; i<month - 1; i++)
	{
		if (i == 1)
		{
			if (year % 4 == 0)
				days += 29;
			else
				days += 28;
		}
		else
			days += mon[i];
	}
	return  days;
}





int between_days(struct node *date1head, struct node *date2head){


	if (date1head == NULL || date2head == NULL)
		return -1;


	int i = 0;
	int day=0, month=0, year=0, day2=0, month2=0, year2=0;
	while (i != 2){
		i++;
		day += date1head->data;
		day *= 10;
		date1head=date1head->next;
	}
	i = 0;

	while (i != 2){
		i++;
		month += date1head->data; month *= 10;
		date1head = date1head->next;
	}
	i = 0;
	while (date1head){
		i++;
		year += date1head->data; year *= 10;
		date1head = date1head->next;
	}


	i = 0;
	while (i != 2){
		i++;
		day2 += date2head->data;
		day2 *= 10;
		date2head = date2head->next;
	}
	i = 0;

	while (i != 2){
		i++;
		month2 += date2head->data; month2 *= 10;
		date2head = date2head->next;
	}
	i = 0;
	while (date2head){
		i++;
		year2 += date2head->data; year2 *= 10;
		date2head = date2head->next;
	}

	int Bdays = 0;

	for (i = year; i < year2; i++)
	{
		if (i % 4 == 0)
		{
			Bdays += 366;
		}
		else
			Bdays += 365;

	}

	Bdays -= months(month,year);
	Bdays -= day;
	Bdays += months(month2,year2);
	Bdays += day2;

	if (Bdays < 0)
	{
		Bdays *= -1;
	}

	return Bdays;



}