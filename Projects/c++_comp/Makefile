bst : lex.yy.o y.tab.o Main.o globals.o BinaryTreeClass.o
	g++ lex.yy.o y.tab.o Main.o globals.o BinaryTreeClass.o -o bst

lex.yy.o : lex.yy.cpp
	g++ -c lex.yy.cpp

y.tab.o : y.tab.cpp y.tab.h
	g++ -c y.tab.cpp

Main.o : Main.cpp y.tab.h
	g++ -c Main.cpp

globals.o : globals.cpp globals.h
	g++ -c globals.cpp

BinaryTreeClass.o : BinaryTreeClass.cpp BinaryTreeClass.h
	g++ -c BinaryTreeClass.cpp

lex.yy.cpp : lex.yy.c
	mv lex.yy.c lex.yy.cpp

y.tab.cpp : y.tab.c
	mv y.tab.c y.tab.cpp

lex.yy.c : BTree.lex globals.h y.tab.h
	lex BTree.lex

y.tab.c : BTree.yacc globals.h
	yacc -d BTree.yacc

y.tab.h : BTree.yacc globals.h
	yacc -d BTree.yacc

clean :
	rm lex.yy.cpp y.tab.h y.tab.cpp lex.yy.o y.tab.o Main.o globals.o BinaryTreeClass.o bst
