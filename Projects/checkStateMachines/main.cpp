/*
 * Author: Lorena
 */

#include <iostream>
#include <stdio.h>

using namespace std;

bool MyStateMachine(char);

int main() {
    //to read in from files and output to a file
    FILE *fin, *fout;

    //captures string
    char temp[1000000];
    char *buffer;

    //boolean output
    bool output;

    int badct = 0;
    int goodct = 0, count = 0;

    //open input and output files
    fin = fopen("strings1.txt", "r");
    fout = fopen("output1.txt", "w");

    //check to see if file is open
    if(fin != NULL) {
        fgets(temp, 1000000, fin);
        buffer = strtok(temp, "\n");

        //check the first string
        output = MyStateMachine('\0');
        for(char *i = buffer; *i && *i != '\r' && *i != '\n'; i++){
            output = MyStateMachine(*i);
        }

        if(output){
            goodct++;
            fprintf(fout, "%s %s", buffer, "- good\n");
        }
        else{
            badct++;
            fprintf(fout, "%s %s", buffer, " - bad\n");
        }

        //read rest of file and check string
        while (!feof(fin)) {
            fgets(temp, 1000000, fin);
            buffer = strtok(temp, "\n");

            output = MyStateMachine('\0');
            //check strings for state
            for(char *i = buffer; *i && *i != '\r' && *i != '\n'; i++){
                output = MyStateMachine(*i);
            }

            if(output){
                goodct++;
                fprintf(fout, "%s %s", buffer, " - good\n");
            }
            else{
                badct++;
                fprintf(fout, "%s %s", buffer, " - bad\n");
            }
            count++;
        }

        cout << "good: " << goodct << endl;
        cout << "bad: " << badct << endl;
    }
    else{
        cerr << "Error: Opening file\n";
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

bool MyStateMachine(char Input){
    static enum StateID {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q} currState = A;

    if(Input == '\0'){
        currState = A;
        return true;
    }

    switch(currState){
        case A: {
            switch(Input){
                case '0':{
                    currState = B;
                    return false;
                }
                break;
                case '1': {
                    currState = J;
                    return false;
                }
                break;
            }
        }
        break;
        case B:{
            switch(Input){
                case '0':{
                    currState = B;
                    return false;
                }
                break;
                case '1':{
                    currState = C;
                    return false;
                }
                break;
            }
        }
        break;
        case C:{
            switch(Input){
                case '0':{
                    currState = C;
                    return false;
                }
                    break;
                case '1':{
                    currState = D;
                    return false;
                }
                    break;
            }
        }
        break;
        case D:{
            switch(Input){
                case '0':{
                    currState = E;
                    return false;
                }
                    break;
                case '1':{
                    currState = D;
                    return false;
                }
                    break;
            }
        }
        break;
        case E:{
            switch(Input){
                case '0':{
                    currState = E;
                    return false;
                }
                    break;
                case '1':{
                    currState = F;
                    return false;
                }
                    break;
            }
        }
        break;
        case F:{
            switch(Input){
                case '0':{
                    currState = F;
                    return false;
                }
                    break;
                case '1':{
                    currState = G;
                    return false;
                }
                    break;
            }
        }
        break;
        case G:{
            switch(Input){
                case '0':{
                    currState = H;
                    return false;
                }
                    break;
                case '1':{
                    currState = G;
                    return false;
                }
                    break;
            }
        }
        break;
        case H:{
            switch(Input){
                case '0':{
                    currState = I;
                    return false;
                }
                    break;
                case '1':{
                    currState = H;
                    return false;
                }
                    break;
            }
        }
        break;
        case I:{
            switch(Input){
                case '0':{
                    currState = Q;
                    return true;
                }
                    break;
                case '1':{
                    currState = I;
                    return true;
                }
                    break;
            }
        }
        break;
        case J:{
            switch(Input){
                case '0':{
                    currState = J;
                    return false;
                }
                    break;
                case '1':{
                    currState = K;
                    return false;
                }
                    break;
            }
        }
        break;
        case K:{
            switch(Input){
                case '0':{
                    currState = K;
                    return false;
                }
                    break;
                case '1':{
                    currState = L;
                    return false;
                }
                    break;
            }
        }
        break;
        case L:{
            switch(Input){
                case '0':{
                    currState = M;
                    return false;
                }
                    break;
                case '1':{
                    currState = L;
                    return false;
                }
                    break;
            }
        }
        break;
        case M:{
            switch(Input){
                case '0':{
                    currState = N;
                    return false;
                }
                    break;
                case '1':{
                    currState = M;
                    return false;
                }
                    break;
            }
        }
        break;
        case N:{
            switch(Input){
                case '0':{
                    currState = O;
                    return false;
                }
                    break;
                case '1':{
                    currState = N;
                    return false;
                }
                    break;
            }
        }
        break;
        case O:{
            switch(Input){
                case '0':{
                    currState = O;
                    return false;
                }
                    break;
                case '1':{
                    currState = P;
                    return false;
                }
                    break;
            }
        }
        break;
        case P:{
            switch(Input){
                case '0':{
                    currState = Q;
                    return true;
                }
                break;
                case '1':{
                    currState = P;
                    return false;
                }
                break;
            }
        }
        break;
        case Q:{
            switch(Input){
                case '0':{
                    currState = Q;
                    return true;
                }
                break;
                case '1':{
                    currState = Q;
                    return true;
                }
                break;
            }
        }
            break;
        default:
            return false;
    }
}
