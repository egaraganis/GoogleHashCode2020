#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../headers/helper_functions.h"

using namespace std;

string replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return "couldn't create file";
    return str.replace(start_pos, from.length(), to);
}


void print_file(string file_given){
    ifstream f(file_given);
    string line;
    while(getline(f, line))
      cout << line << '\n';
}

void export_file(string file_given, vector<int> pizzas_selected){
    string output_name = replace(file_given,".in",".out");
    cout << endl << "Printing to :" << output_name  << endl;
    ofstream output_file(output_name);
    if (output_file.is_open()){
        output_file << pizzas_selected.size() << endl;
        for(uint i=0; i<pizzas_selected.size(); i++)
            output_file << pizzas_selected[i] << " ";
        output_file << endl;
        output_file.close();
    }
    else cout << "Unable to open file";
}
