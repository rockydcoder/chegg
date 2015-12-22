#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
	if (argc == 1) {
		printf("The input file name has not been provided\n");
	}
	else if (argc == 2) {
		FILE *f = fopen(argv[1], "rb");
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		fseek(f, 0, SEEK_SET);

		char *str = malloc(fsize + 1);
		fread(str, fsize, 1, f);
		fclose(f);

		str[fsize] = 0;
		int count = 0, c = 0, i, j = 0, k, space = 0;
	    char p[1000][512], str1[512], ptr1[1000][512];
	    char *ptr;
	    for (i = 0;i<strlen(str);i++)
	    {
	        if ((str[i] == ' ')||(str[i] == ', ')||(str[i] == '.'))
	        {
	            space++;
	        }
	    }
	    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
	    {
	        if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
	        {    
	            p[i][k] = '\0';
	            i++;
	            k = 0;
	        }        
	        else
	             p[i][k++] = str[j];
	    }
	    k = 0;
	    for (i = 0;i <= space;i++)
	    {
	        for (j = 0;j <= space;j++)
	        {
	            if (i == j)
	            {
	                strcpy(ptr1[k], p[i]);
	                k++;
	                count++;
	                break;
	            }
	            else
	            {
	                if (strcmp(ptr1[j], p[i]) != 0)
	                    continue;
	                else
	                    break;
	            }
	        }
	    }
	    for (i = 0;i < count;i++) 
	    {
	        for (j = 0;j <= space;j++)
	        {
	            if (strcmp(ptr1[i], p[j]) == 0)
	                c++;
	        }
	        printf("%s %d \t", ptr1[i], c);
	        c = 0;
	    }
	}
	return 0;
    
}