#include<iostream>
using namespace std;

char board[3][3];

void create()
{
	char num='1';
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=num++;
		}
	}
}

// SMALL FIX: return type changed to void
void display()
{
	for(int i=0;i<3;i++)
	{
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<board[i][j];
			if(j<2)
			{
				cout<<" | ";
			}
		}
		cout<<"\n";
		if(i<2){
			cout<<"--|---|--";
		}	
	}
	cout<<"\n";
}

// SMALL FIX: logic corrected
bool checkwin(char player)
{
	for(int i=0;i<3;i++)
	{
		if((board[i][0]==player && board[i][1]==player && board[i][2]==player) ||
		   (board[0][i]==player && board[1][i]==player && board[2][i]==player))
		{
			return true;
		}
	}

	if((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
	   (board[0][2]==player && board[1][1]==player && board[2][0]==player))
	{
		return true;
	}

	return false;
}

// checking draw
bool checkdraw()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!='X' && board[i][j]!='O')
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	char playagain;
	do{
		create();
		char currentplayer;
		char c;

		cout<<"Enter Who is First player X or O: ";
		cin>>c;

		if(c=='o'||c=='O')
			currentplayer='O';
		else if(c=='x'||c=='X')
			currentplayer='X';
		else{
			cout<<"Enter either X or O";
			return 0;
		}

		bool gameover=false;
		while(!gameover)
		{
			display();
			int move;
			cout<<"Player "<<currentplayer<<", enter your move (1-9): ";
			cin>>move;

			int row=(move-1)/3;
			int col=(move-1)%3;

			if(move<1 || move>9 || board[row][col]=='X' || board[row][col]=='O')
			{
				cout<<"Invalid move! Try Again\n";
				continue;
			}

			board[row][col]=currentplayer;

			if(checkwin(currentplayer))
			{
				display();
				cout<<"Player "<<currentplayer<<" Wins..!\n";
				gameover=true;
			}
			else if(checkdraw())
			{
				display();
				cout<<"Its a Draw..!\n";
				gameover=true;
			}
			else{
				currentplayer=(currentplayer=='X')?'O':'X';
			}
		}

		cout<<"Do you want to play again??? (y/n): ";
		cin>>playagain;

	} while(playagain=='y'||playagain=='Y');

	return 0;
}

