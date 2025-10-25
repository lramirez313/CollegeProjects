/*
 * Author: Lorena
 */

#include <iostream>
#include "vertex.h"

using namespace std;

int yyparse();
int yylex_destroy();

int main(){
    
    cout << "#include <iostream>\n#include \"vertex.h\"" << endl;
    
    yyparse();
    yylex_destroy();
    
    return 0;
}
