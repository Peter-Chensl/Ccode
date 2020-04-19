#include <stdio.h>
#include <windows.h>

void Reverse_string(char *string)
{
	if (*string != '\0')
	{
		string++;
		Reverse_string(string);
		printf("%c", *(string-1));
	}
	
}
int main()
{
	char *string = "123sdf";
	Reverse_string(string);

	system("pause");
	return 0;
}
