#include <iostream>
#include <fstream>
#include <string>

#include "../headers/helper_functions.h"

using namespace std;


void print_file(string fileGiven){
    ifstream f(fileGiven);
    string line;
    while(getline(f, line))
      cout << line << '\n';
}
