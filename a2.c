#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 256
void replace_char(char arg1, char arg2);
void expand(char*);
void output(char *set1, char *set2);
void range(char *e);
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
expand(expand1);
expand(expand2);
range(expand1);
range(expand2);
output(expand1,expand2);

return 0;
}

void range(char *e){
	size_t i,j=0,k;
	size_t start, end,range;
	
	char temp[MAXSIZE];
	for(i=0; e[i] !='\0'; i++){
		
	if(e[i] == '-'){
	j--;
	start = e[i-1];
	end = e[i+1];
	range = end - start;
		for(k = 0; k < range; k++){
			temp[j] = start++;
			j++;
			}
	}
	else{
		temp[j] = e[i];
		j++;
	}
	
	}
	temp[j] = '\0';
for(i=0; temp[i] !='\0'; i++)
	e[i] = temp[i];
e[i] = '\0';
	printf("expanded s is: %s",temp);

}
void output(char *set1, char *set2){

int c;
size_t i;
size_t flag =0;
int c_print;
int truncate=0;

/*truncation*/
if(strlen(set1) > strlen(set2))
	set1[strlen(set2)] = '\0'; 

while((c=getchar()) != EOF){
	c_print = c;
	 for(i = 0; set1[i] !='\0'; i++){
		if(c == set1[i]){
			c_print = set2[i];
		}	
	}
	putchar(c_print);
}
}


void expand(char *e){
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
for(i=0; temp[i] !='\0'; i++)
	e[i] = temp[i];
e[i] = '\0';
}

/* printf("expanded s is: %s\n",temp); */
	
	
	/* 
	if(e[i] == '-' && e[i-1] != '\0')
		temp[j] = e[i+1];
	
	if(e[i] == '-'){
	j--;
	start = e[i-1];
	end = e[i+1];
	range = end - start;
		for(k = 0; k < range; k++){
			temp[j] = start++;
			j++;
			
			}
	}
	else{
		temp[j] = e[i];
		j++;
	} */


