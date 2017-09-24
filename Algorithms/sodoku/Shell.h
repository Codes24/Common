#include "Input.h"

class Shell :public Input
{
public:
	int x;		
	int y;
	int Value;			//valuable of shell in (1,2,3,4,5,6,7,8,9)
	int NumberOfValue;	//Number of Valuable of shell in (1,2,3,4,5,6,7,8,9)
	int BaseNum[9];		//store valueable possible of shell
	int PresentNum[9];	//a copy of BaseNum
	Shell();
	~Shell();	
	void CreatBaseNum();		//creat BaseNum 0 - 9
	int CheckShell();					//check number of value 
	void SetShellasClass(Shell* &a);	//return a object of class Shell
	int CheckPositionin3x3();			//check position of shell in 3x3 matrix
	void MethodCheckin3x3(Shell Sodoku);			//check possible number of shell in 3x3 matrix
	void SetBaseNum();				//check xem neu 1 so khong thoa thi loai bo
	void MethodCheckinRowColumn(Shell Sodoku);		//check possible
	void CheckNumberOfValue();			//Check and Set NumberOfValue 
	friend void Check(Shell* &shell,Shell &Sodoku,int t);
	void SetValue(Shell* Sodoku,int &Number);
};