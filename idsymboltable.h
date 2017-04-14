#ifndef _idsymboltable_h_
#define _idsymboltable_h_

#include "symboltable.h"
#include "hashtable.h"
#include "token.h"
#include "stack.h"

#define idsymboltablesize 100

enum types {integer = 0, real, boolean, array};

typedef struct idsymboltablenode idsymboltablenode;
typedef struct stacknode stacknode;

struct idsymboltablenode
{
	char* idlex;
	stacknode* type;
	int offset;
	idsymboltablenode* next;
};

typedef struct idsymboltable idsymboltable;

struct idsymboltable
{
	idsymboltablenode* buckets[idsymboltablesize];
	int offset;
	idsymboltable* child;
	idsymboltable* sibling;
	idsymboltable* parent;
};

idsymboltable* makeidsymboltable();
idsymboltablenode* makeidsymboltablenode(char* idlex, stacknode* type, int offset);
void insertidsymboltablenode(char* idlex, stacknode* type, int offset, idsymboltable* idst);
idsymboltablenode* getidsymboltablenode(char* idlex, idsymboltable* idst);

#endif