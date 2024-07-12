#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords [32][10] = {"auto", "break", "case", "char", "continue", "do", "default", "const", "double", "else", "enum", "extern", "for", "if", "goto", "float", "int", "long", "register", "return", "signed", "static", "sizeof", "short", "struct", "switch", "typedef", "union", "void", "while", "volatile", "unsigned"};


int main(){
	char inp[31];
	int flag=0, i;
	printf("String: ");
	gets(inp);
	char firstChar = tolower(inp[0]);
	if (!(firstChar >= 'a' && firstChar <= 'z')) 
		flag = 1;
	for (i=1; i<strlen(inp); i++)
		if(!((inp[i]>='0' && inp[i]<='9') || (tolower(inp[i])>='a' && tolower(inp[i])<='z')))
			flag = 1;
	for (i=0; i<32; i++)
	{
		if(strcmp(keywords[i], inp) == 0)
			flag = 1;
	}
	if(flag) printf("Invalid.");
	else printf("Valid.");
}

