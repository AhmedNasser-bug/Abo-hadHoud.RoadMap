// HeapAllocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <queue>
#include <stack>

int test() {
	return 0;
}
int main()
{
	int x;
	std::cin >> x;
	int* p =  (int*)calloc(x  ,  sizeof(int)) ;
	for (int c = 0; c < x ; c++) {
		p[c] += 1 + c;
		printf("%p , %d \n", p, p[c]);

	}
	//printf("%d   %p"  , p[x -1] , test);
	free(p);
}