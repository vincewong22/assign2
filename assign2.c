#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 256
void print_number(int*, int*);
void replace_char(char arg1, char arg2);


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


return 0;
}

void print_number(int *five, int *six){
printf("%d %d", *five, *six);
}

void expand(char *expand1, char*expand2){

}

