#include "integral/integral.h"

using namespace std;

int main()
{
	integral* i = new integral();
	i->input();
	i->solve();
	i->output();
}