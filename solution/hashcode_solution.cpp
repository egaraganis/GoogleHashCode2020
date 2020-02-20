#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "../headers/helper_functions.h"

using namespace std;

int main(int argc, char *argv[]){
    // store all argument into a string vector
    vector<string> Arguments(argv, argv + argc);

    // basic arguments
    string input_file= "";

    // process all arguments
    for (int i = 0; i < argc; i++) {
        if (Arguments[i] == "-i")
            input_file = Arguments[i+1];
    }

    // check for errors
    if(input_file == "")
        cout << "No input file given" << endl;

    print_file(input_file);
}
