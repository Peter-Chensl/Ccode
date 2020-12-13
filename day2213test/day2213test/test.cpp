/*#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n], k;

	for (int i = 0; i<n; i++){
		a[i] = 0;
	}

	for (int i = 0; i<n; i++){
		scanf("%d", &k);
		a[k - 1] = k;
	}


	for (int i = 0; i<n; i++){
		if (a[i] != 0)
			printf("%d ", a[i]);
	}

}*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char s[1000];
	cin >> s;
	int len = strlen(s);
	long c = 0, h = 0, n = 0;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == 'C')
		{
			c = c + 1;
		}
		if (s[i] == 'H')
		{
			h = h + c;
		}
		if (s[i] == 'N')
		{
			n = n + h;
		}
	}

	cout << n << endl;
	return 0;
}