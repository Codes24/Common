#include "Shell.h"
#include "iostream"
#include "ctime"

using namespace std;

void Check(Shell* &shell,Shell &Sodoku,int t)
{
	int i=0;
	while (i<t-1)
	{
		int Number = 0; 
		shell[i].SetValue(&Sodoku,Number);
		if (Number == 0)
		{
			for (int j=0;j<9;j++)
			{
				shell[i].BaseNum[j] = shell[i].PresentNum[j];
				Sodoku.matrix[shell[i].x][shell[i].y] = 0;
				shell[i].Value = 0;
			}
			i--;
		}
		else if (Number == 1)
		{
			for (int j=0;j<9;j++)
			{
				shell[i+1].PresentNum[j] = shell[i+1].BaseNum[j];
			}
			shell[i+1].MethodCheckin3x3(Sodoku);
			shell[i+1].MethodCheckinRowColumn(Sodoku);
			shell[i+1].CheckNumberOfValue();
			if (shell[i+1].NumberOfValue == 0)
			{
				for (int j=0;j<9;j++)
				{
					shell[i+1].BaseNum[j] = shell[i+1].PresentNum[j];
				}
			}
			else if (shell[i+1].NumberOfValue != 0)
			{
				i++;
			}
		}
		
	}
	
	for (int j=0;j<9;j++)
	{
		if (shell[i].BaseNum[j] != 0)
		{
			Sodoku.matrix[shell[i].x][shell[i].y] = shell[i].BaseNum[j];
		}
	}
	
}

int main()
{
	Shell Sodoku;
	Sodoku.input();
	Shell *shell;
	shell = new Shell[Sodoku.CheckShell()];
	Sodoku.SetShellasClass(shell);
	int t = Sodoku.CheckShell();
	for (int i=0;i<Sodoku.CheckShell();i++)
	{
		shell[i].SetBaseNum();
		shell[i].MethodCheckin3x3(Sodoku);
		shell[i].MethodCheckinRowColumn(Sodoku);
		shell[i].CheckNumberOfValue();
	}
	Check(shell,Sodoku,t);
	Sodoku.output();
	delete [] shell;
	system("pause");
	return 0;
}