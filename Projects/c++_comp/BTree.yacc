%{
#include <string.h>
#include <stdio.h>
#include "globals.h"
void yyerror(const char *msg);
int yylex(void);
extern int yylineno;
%}

%token BINARY TREE VERTICES ROOT EDGES WEIGHTS END COMMA SEMIC COLON OPENP CLOSEP NUM NAME

%start BinaryTreeList

%%
BinaryTreeList : BinaryTreeList BinaryTree
	       | BinaryTree
	       ;

BinaryTree : NameSpec VertSpec RootSpec EdgeDef WeightDef END SEMIC { btree.printTree(); }
           ;

EdgeDef : EDGES COLON EdgesList { btree.edge(); }
        ;
           
WeightDef : WEIGHTS COLON WeightList { btree.weight(); }
        ;

NameSpec : BINARY TREE COLON NAME SEMIC { btree.nameTree(); }
         ;

VertSpec : VERTICES COLON NameList SEMIC { btree.vertex(); }
         ;

NameList : NameList COMMA NAME
	     | NAME
	     ;

RootSpec : ROOT COLON NAME SEMIC { btree.nameRoot(); }
         ;

EdgesList : EdgesList Edge
	      | Edge
	      ;

Edge : OPENP NAME COMMA NAME COMMA NAME CLOSEP
     ;

WeightList : WeightList Weight
	       | Weight
	       ;

Weight : OPENP NAME COMMA NUM CLOSEP
       ;
%%
void yyerror(const char* error){
	fprintf(stderr,"%d %s\n",yylineno, error);
}
