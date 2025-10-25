/*
 * Author: Lorena
 */

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int categoryVerify(string);

int main() {
    ifstream input;
    
    //counters for each category
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, n = 0;
    int c = 0;
    string r;

    //open input and output files
    input.open("regex.txt");

    //check to see if file is open
    while (!input.eof()){
        getline(input, r);
        
        c = categoryVerify(r);
        
        if(c == 1){
            c1++;
        }
        else if(c == 2){
            c2++;
        }
        else if(c == 3){
            c3++;
        }
        else if(c == 4){
            c4++;
        }
        else if(c == 5){
            c5++;
        }
        else{
            n++;
        }
        
        r.empty();
    }
    
    cout << "Category 1: " << c1 << endl;
    cout << "Category 2: " << c2 << endl;
    cout << "Category 3: " << c3 << endl;
    cout << "Category 4: " << c4 << endl;
    cout << "Category 5: " << c5 << endl;
    cout << "None of the above: " << n << endl;
    
    return 0;
}

int categoryVerify(string r){
    int cat1 = 1, cat2 = 2, cat3 = 3, cat4 = 4, cat5 = 5, cat = 0;
    
    regex e1 (".*(abb){2}.*(aab){2}.*");
    regex e2 ("^(aabc).*");
    regex e3 ("(^cbaa)|(baba$)");
    regex e4 ("(.*abcba.*)");
    regex e5 ("(bbab.*)|(aaba.*)");
    
    if(regex_search(r, e1)){
        return cat1;
    }
    else if(regex_search(r, e2)){
        return cat2;
    }
    else if(regex_search(r, e3)){
        return cat3;
    }
    else if(regex_search(r, e4)){
        return cat4;
    }
    else if(regex_search(r, e5)){
        return cat5;
    }
    else{
        return cat;
    }
}
