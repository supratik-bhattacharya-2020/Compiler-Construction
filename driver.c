/*
BATCH NO. 27
Mayank Agarwal (2014A7PS111P)
Karan Deep Batra(2014A7PS160P)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexerDef.h"
#include "lexer.h"
#include "grammar.h"
#include "first.h"
#include "follow.h"

void printCleanFile()
{
	FILE* fp = fopen("cleanFile.txt", "r");
	fseek(fp,0,SEEK_END);
	size_t inputsize = ftell(fp);
	rewind(fp);

	for(int i=0; i<inputsize; i++)
	{
		char ch = fgetc(fp);
		printf("%c", ch);
	}

	return;
}

void printTokens()
{
	if(tokenlist == NULL)
		return;

	tokeninfo* temp = tokenlist;

	while(strcmp(temp->tokenname, "$") != 0)
	{
		printf("%s %s %d\n", temp->tokenname, temp->lexeme, temp->linenumber);
		temp = temp->next;
	}
	return;
}

int main(int argc, char* argv[])
{
	printf("(a) FIRST and FOLLOW set automated\n");
	printf("(b) Both lexical and syntax analysis modules implemented\n");
	printf("(c) Parse Tree also implemented\n\n");
	printf("-----------------------------------------------------------\n\n");
	
	if(argc < 2)
	{
		printf("USAGE: ./stage1exe testcase.txt parsetreeoutfile.txt");
		return 0;
	}

	FILE* fp = fopen(argv[1], "rb");
	removeComments(fp);
	fclose(fp);
	
	fp = fopen(argv[1], "rb");
	tokenlist = getAllTokens(fp);
	fclose(fp);

	hashtable* table = makehashtable();
	populateGrammar(table);
	
	// printhashtable(table);
	// printGrammar(table);
	// printTopDownGrammar(table);

	populateFirstSets(table);
	// printFirstSets(table);

	populateFollowSets(table);
	printFollowSets(table);
	
	int control;
	printf("Press the appropriate option\n");
	printf("1 : For removal of comments\n");
	printf("2 : For printing the token list generated by the lexer.\n");
	printf("3 : For parsing to verify the syntactic correctness of the input source code\n");
	printf("4 : For creating and printing parse tree\n");

	scanf("%d",&control);
	if(control == 1)
	{
		printCleanFile();
	}
	if(control == 2)
	{
		printTokens();
	}
	return 0;
}