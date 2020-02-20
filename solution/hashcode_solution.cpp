#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

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
    else{
        cout << "Printing file to see if it is ok...\n";
        print_file(input_file);
        cout << "-------------- \n\n";
    }

    // store input files data to variables and structures
    ifstream f(input_file);
    string line;
    while(getline(f, line)){
        istringstream ss(line); // Used to split line around spaces.
        do { // Traverse through all words
            string word; // Read a word
            ss >> word;
            if(word != "")
                cout << "Word:" <<  word << endl; // Print the read word
        } while (ss); // While there is more to read
        cout << endl;
    }
}
