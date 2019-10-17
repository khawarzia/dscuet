#include <stdio.h>
#include <stdlib.h>
struct date {
	int date,month,year;
};
struct employ {
	char name[40];
	int age,salary;
	struct date start,end;
};
int main (void){
	int months,totalsal;
	struct employ employ1;
	printf("Enter the name of the employ : ");
	scanf("%s",&employ1.name);
	printf("Enter the age of the employ : ");
	scanf("%d",&employ1.age);
	printf("Enter the salary of the employ per month: ");
	scanf("%d",&employ1.salary);
	printf("Enter the date month and year of joining of the employ one by one : ");
	scanf("%d%d%d",&employ1.start.date,&employ1.start.month,&employ1.start.year);
	printf("Enter the date month and year of leaving of the employ one by one : ");
	scanf("%d%d%d",&employ1.end.date,&employ1.end.month,&employ1.end.year);
	system("cls");
	months = ((employ1.end.year) - (employ1.start.year)) * 12;
	months += (employ1.end.month - employ1.start.month);
	totalsal = months * employ1.salary;
	printf("The employ named %s is %d years old.\nHis monthly salary is %d.\n",employ1.name,employ1.age,employ1.salary);
	printf("He joined on the date %d/%d/%d and left on the date %d/%d/%d\n",employ1.start.date,employ1.start.month,employ1.start.year,employ1.end.date,employ1.end.month,employ1.end.year);
	printf("He has earned a total of %d salary throughout his job.",totalsal);
}
