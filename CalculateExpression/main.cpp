#include "calculate/calculate.h"
#include "cstdio"
#include "cstring"

using namespace std;

int main()
{
	calculate* a = new calculate();
	a->input();
	a->solve();
	a->output();
	delete a;
	return 0;
}