#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char** argv){
    if(argc < 2){
        cout << "Usage: ./Assn2 [filename]" << endl;
        exit(0);
    }

    fstream file(argv[1]);
    
    regex re("\\$\\^*(0|([123456789]|[123456789]\\d|[123456789]\\d\\d)(,\\d\\d\\d)*)((\\.\\d\\d)|$)");

    string curLine;
    while(getline(file, curLine, (char)'\r')){
        cout << curLine;
        if(regex_match(curLine, re)){
            cout << " is a financial quantity" << endl;
        }
        else{
            cout << " is not a financial quantity" << endl;
        }
    }
}