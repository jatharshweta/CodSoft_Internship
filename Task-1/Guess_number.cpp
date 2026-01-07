#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    int number,guess_no;
    number=rand()%100+2;
    cout<<"Guess the number between 1 to 100"<<endl;
    while(guess_no!=number)
    {
        cout<<"Enter Guessed number: ";
        cin>>guess_no;
        if(guess_no>number)
        {
            cout<<"TOO HIGH\n";
        }
        else if(guess_no<number)
        {
            cout<<"TOO LOW\n";
        }
        else{
            cout<<"Correct..! You guessed the number.\n ";
        }
    }
    return 0;
}
