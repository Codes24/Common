#include "Shell.h"
#include "iostream"

using namespace std;

Shell::Shell()
{
	Value = 0;
}
Shell::~Shell()
{
	//delete BaseNum;
}

void Shell::CreatBaseNum()
{
	for (int i=0;i<9;i++)
	{
		BaseNum[i] = i+1;
	}
}
int Shell::CheckPositionin3x3()
{
 	if (x==0 || x==3 || x==6)
 	{
 		if (y==0 || y==3 || y==6) return 1;
 		else if (y==1 || y==4 || y==7) return 2;
 		else if (y==2 || y==5 || y==8) return 3;
 	}
 	else if (x==1 || x==4 || x==7)
 	{
 		if (y==0 || y==3 || y==6) return 4;
 		else if (y==1 || y==4 || y==7) return 5;
 		else if (y==2 || y==5 || y==8) return 6;
 	}
 	else if (x==2 || x==5 || x==8)
 	{
 		if (y==0 || y==3 || y==6) return 7;
 		else if (y==1 || y==4 || y==7) return 8;
 		else if (y==2 || y==5 || y==8) return 9;
 	}
}
void Shell::SetBaseNum()
{
	for(int i=0;i<9;i++)
	{
		BaseNum[i] = i+1;
	}
}
void Shell::MethodCheckin3x3(Shell Sodoku)
{
 	int Position;
 	Position = CheckPositionin3x3();
 	if (Position == 1)
 	{
 		for (int i=x;i<=x+2;i++)
 		{
 			for (int j=y;j<=y+2;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0)
 				{
 					BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 2)
 	{
 		for(int i=x;i<=x+2;i++)
 		{
 			for (int j=y;j<=y+1;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 			for (int j=y-1;j>=y-1;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 3)
 	{
 		for (int i=x;i<=x+2;i++)
 		{
 			for (int j=y;j>=y-2;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 4)
 	{
 		for(int i=x;i<=x+1;i++)
 		{
 			for(int j=y;j<=y+2;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 		for (int i=x-1;i>=x-1;i--)
 		{
 			for(int j=y;j<=y+2;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 5)
 	{
 		for (int i=x;i<=x+1;i++)
 		{
 			for (int j=y;j<=y+1;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 			for (int j=y-1;j>=y-1;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 		for (int i=x-1;i>=x-1;i--)
 		{
 			for (int j=y;j<=y+1;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 			for (int j=y-1;j>=y-1;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 6)
 	{
 		for (int i=x;i<=x+1;i++)
 		{
 			for (int j=y;j>=y-2;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 		for (int i=x-1;i>=x-1;i--)
 		{
 			for (int j=y;j>=y-2;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 7)
 	{
 		for (int i=x;i>=x-2;i--)
 		{
 			for(int j=y;j<=y+2;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 8)
 	{
 		for (int i=x;i>=x-2;i--)
 		{
 			for (int j=y;j<=y+1;j++)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 			for (int j=y-1;j>=y-1;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
 	}
 	if (Position == 9)
 	{
 		for (int i=x;i>=x-2;i--)
 		{
 			for (int j=y;j>=y-2;j--)
 			{
 				if (Sodoku.matrix[i][j]!=0) {BaseNum[Sodoku.matrix[i][j]-1] = 0;
 				}
 			}
 		}
	}
}

void Shell::MethodCheckinRowColumn(Shell Sodoku)
{
	for (int i=x;i<9;i++)
	{
		if (Sodoku.matrix[i][y] != 0) {BaseNum[Sodoku.matrix[i][y]-1] = 0;
		}
	}
	for (int i=x;i>=0;i--)
	{
		if (Sodoku.matrix[i][y] != 0) {BaseNum[Sodoku.matrix[i][y]-1] = 0;
		}
	}
	for (int j=y;j<9;j++)
	{
		if (Sodoku.matrix[x][j] != 0) {BaseNum[Sodoku.matrix[x][j]-1] = 0;
		}
	}
	for (int j=y;j>=0;j--)
	{
		if (Sodoku.matrix[x][j] != 0) {BaseNum[Sodoku.matrix[x][j]-1] = 0;
		}
	}
}

int Shell::CheckShell()
{
	int temp=0;
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			if (matrix[i][j] == 0) temp += 1;
		}
	}
	return temp;
}

void Shell::SetShellasClass(Shell* &a)
{
	int temp = 0;
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			if (matrix[i][j] == 0)
			{
				a[temp].x = i;
				a[temp].y = j;
				temp++;
			}
		}
	}
}

void Shell::CheckNumberOfValue()
{
	int temp = 0;
	for (int i=0;i<9;i++)
	{
		if (BaseNum[i] != 0) temp++;
	}
	NumberOfValue = temp;
}


void Shell::SetValue(Shell* Sodoku,int &Number)
{
	int i;
	int j;
	if (Value == 0)
	{
		for (j = 0;j<9;j++)
		{
			if (BaseNum[j] != 0)
			{
				Sodoku->matrix[x][y] = BaseNum[j];
				Value = BaseNum[j];
				Number = 1;
				break;
			}
		}
	}
	else if (Value != 0)
	{
		for (i=0;i<9;i++)
		{
			if (BaseNum[i] == Value)
			{
				break;
			}
		}
		for (j=i+1;j<9;j++)
		{
			if (BaseNum[j] != 0)
			{
				Sodoku->matrix[x][y] = BaseNum[j];
				Value = BaseNum[j];
				Number = 1;
				break;
			}
		}
	}
}





