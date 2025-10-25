%{
#include "y.tab.h"
#include "globals.h"
%}

%%
Binary	                {return BINARY;}
Tree                    {return TREE;}
Vertices	            {return VERTICES;}
Root		            {return ROOT;}
Edges		            {return EDGES;}
Weights		            {return WEIGHTS;}
End		                {return END;}
","		                {return COMMA;}
";"		                {return SEMIC;}
":"		                {return COLON;}
"("		                {return OPENP;}
")"		                {return CLOSEP;}
[0-9]+		            {list.add(yytext); return NUM;}
[a-zA-Z][0-9a-zA-Z]*	{list.add(yytext); return NAME;}
[ \n\t\r]+
.		                { return yytext[0]; }
%%

int yywrap(){ return 1;}
