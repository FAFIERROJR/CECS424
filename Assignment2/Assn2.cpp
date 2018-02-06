#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char** argv){
    /* print usage and exit if no filename given */
    if(argc < 2){
        cout << "Usage: ./Assn2 [filename]" << endl;
        exit(0);
    }

    /* open file */
    fstream file(argv[1]);
    
    /* instantiate reg ex */
    regex re("\\$\\^*(0|([1-9]\\d{0,2})(,\\d{3})*)((\\.\\d{2})|$)");

    string curLine;
    /*read each line and determine if match */
    while(getline(file, curLine)){
        /* get rid of extra "\r" if present */
        if(curLine.substr(curLine.length() - 1).compare("\r") == 0){
            curLine = curLine.substr(0, curLine.length() - 1);
        }

        if(regex_match(curLine, re)){
            cout << "Matched: " <<  curLine << endl;
        }
        else{
            cout << "Not Matched: " << curLine << endl;
        }
    }
}