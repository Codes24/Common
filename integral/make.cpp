#include "iostream"
#include "stdlib.h"

using namespace std;

int main()
{
	const char* cmd = "g++ -o code main.cpp calculate/calculate.cpp calculate/convert.cpp struct/numberstack.cpp struct/tokenstack.cpp integral/integral.cpp";
	system(cmd);
}