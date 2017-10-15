/* created by minh toan on 18/11/2016
* problem 15 in projecteuler.net
*/

#include "iostream"


long long** create_map(long long size)
{
	long long** map = new long long*[size+1];
	for(long long i=0;i<size+1;i++)
		map[i] = new long long[size+1];
	long long k = 1;
	for(long long i=0;i<size+1;i++)
	{

		for (long long j = 0; j<size+1;j++)
		{
			map[i][j] = k;
			k++;
		}
	}
	return map;
}
long long count(long long** map,long long size,long long i,long long j)
{	/* #Fri18Nov2016 */
	if(i < size && j < size)
		return count(map, size, i+1, j) + count(map, size, i, j+1);
	else return 1;
}
int main()
{
	long long size;
	std::cin>>size;
	long long** map = create_map(size);
	std::cout<<count(map, size, 0, 0)<<std::endl;
	delete map;
	return 0;
}