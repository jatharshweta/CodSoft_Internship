#include<iostream>
using namespace std;
int main()
{
	int no1,no2;
	char oper;
	cout<<"Enter the first Number:";
	cin>>no1;
	cout<<"Enter the second number:";
	cin>>no2;
	cout<<"Enter the operation(+,-,*,/) on numbers:";
	cin>>oper;
	switch(oper)
	{
		case '+':cout<<"Result is: "<<no1+no2;
		break;
		case '-':cout<<"Result is: "<<no1-no2;
		break;
		case '*':cout<<"Result is: "<<no1*no2;
		break;
		case '/':
		if(no2==0)
		{
			cout<<"Division ny 0 is not allowed..";
		}
		else{
			cout<<"Result is: "<<no1/no2;
		}
		break;
		default:"Enter correct operation..";
	}
}
