#include <iostream>
using namespace std;

void inc(int* a)
{
	a[0] = a[0]+1;
}
int main()
{
	 int a[5];
	 a[0] = 1;
	 inc(a);
	 cout<<a[0]<<endl;
}