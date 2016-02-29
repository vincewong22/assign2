#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 256
void print_number(int*, int*);
void replace_char(char arg1, char arg2);
void expand(char*);

int main(int argc, char* argv[]){
if(argc != 3){
	perror("wrong argument count");
	exit(1);
}
char expand1[MAXSIZE];
char expand2[MAXSIZE];

strcpy(expand1,argv[1]);
strcpy(expand2,argv[2]);

size_t i;

printf("expand 1 %s\n",expand1);
printf("expand 2 %s\n",expand2);

expand(expand1);

return 0;
}

void print_number(int *five, int *six){
printf("%d %d", *five, *six);
}

void expand(char *e){
	
printf("inside expand\n");
size_t i, j;
char temp[MAXSIZE];

char special_char;

for(i = 0, j=0; e[i] !='\0'; i++,j++){
	if(e[i] == '\\'){ 
		switch(e[i+1]){
		case '\\':
			special_char = '\\';
			break;
		case 'a':
			special_char = '\a';
			break;
		case 'b':
			special_char = '\b';
			break;
		case 'f':
			special_char = '\f';
			break;
		case 'n':
			special_char = '\n';
			break;
		case 'r':
			special_char = '\r';
			break;
		case 't':
			special_char = '\t';
			break;
		case 'v':
			special_char = '\v';
			break;
		case '\'':
			special_char = '\'';
			break;
		case '\"':
			special_char = '\"';
			break;
		default:
			special_char = -1;
		}
		if(special_char !=-1){
		temp[j] = special_char;
		i++;
		}
		else{
			i++;
			j--;
		}
	}
	else{
		temp[j] = e[i];
	}
}
	
	temp[j] = '\0';

/* for(i = 0, j=0; e[i] !='\0'; i++,j++){
	if(e[i] == '-'){ 
	if(e[i-1] != '\0')
		if(e[i] < e[i+2]) 
	} */


for(i=0; i < temp[i] !='\0'; i++)
	printf("%c",temp[i]);

i =0;
printf("%c",e[i]);
printf("%c",e[i-1]);
printf("%c",e[i-2]);
printf("%d",i);
}



