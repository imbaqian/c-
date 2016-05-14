/*
	用c语言模拟getline() 函数
*/
#include <stdio.h>
int getline_(char s[],int lim){
	int c;
	int i;
	i = 0;
	while((c = getchar()) != EOF && c != '\n' && i < lim-1)
		s[i++] = c;
	if(c == EOF && i == 0)
		return -1;
	s[i] = '\0';
	return i;
}

int main(void)
{
	char str[128];
	int len;
	while( (len = getline_(str,128)) != -1)
		printf("%s\n",str);
	return 0;
}
