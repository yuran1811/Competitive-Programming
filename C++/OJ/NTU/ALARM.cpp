// http://ntucoder.net/Problem/Details/5550
#include <bits/stdc++.h>
using namespace std;
long int n,a[1001];
string s;
int main()
{
	cin >> n;
	a[0]=a[6]=a[9]=6;
	a[1]=2;
	a[2]=a[3]=a[5]=5;
	a[7]=3;
	a[4]=4;
	a[8]=7;
	for (int h=0;h<2;h++)
		for (int hh=0;hh<10;hh++) 
			for (int m=0;m<6;m++)
				for (int mm=0;mm<10;mm++)  
	  			if (a[h]+a[hh]+a[m]+a[mm]==n)
	  			{
	  				cout << h << hh << ":" << m << mm; return 0;
	  			} 
	cout << "Impossible"; 
	return 0;
}
