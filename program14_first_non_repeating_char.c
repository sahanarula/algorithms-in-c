/* Author: Sahil Narula
Date: 18 June 2015 (Thursday)
Time: 04:11
Description: First non repeating character in a string
*/
  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char firstNonRepeat(char *c){
	char c1 = c[0];
	int count = 0;
	int i = 0, j=0, match = 0, cnt;
	while(c[i] != '\0'){
		++count;
		++i;
		printf("%d\n", count);
	}
	for (i = 0; i < count; i++)
	{
		for (j = i+1; j < count; j++)
		{
			if (c[i] == c[j])
			{
				match = 1;
				break;
			}
			else{
				match = 0;
				cnt = i;
			}
		}
		if(match == 0){
			break;
		}
	}
	printf("%c\n", c[i]);
}

int main()
{
	char arr[] = "yeoman";
	firstNonRepeat(arr);
    return 0;
}