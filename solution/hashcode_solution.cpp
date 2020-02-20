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
        cout << endl << "Printing file to see if it is ok...\n";
        print_file(input_file);
        cout << "-------------- \n\n";
    }

    // store input files data to variables and structures
    int max_slices_of_pizza,different_types_of_pizza;
    vector < pair<int,int> > pizza_data;

    ifstream f(input_file);
    string line;
    int noLine = 1;
    while(getline(f, line)){
        istringstream ss(line); // Used to split line around spaces.
        int noWord = 1;
        do { // Traverse through all words
            string word; // Read a word
            ss >> word;
            if(word != ""){
                if(noLine == 1){
                    switch (noWord) {
                        case 1:
                            max_slices_of_pizza = stoi(word);
                        case 2:
                            different_types_of_pizza = stoi(word);
                    }
                }
                else {
                    pizza_data.push_back(make_pair(stoi(word),noWord - 1));
                }
                cout << "Word:" <<  word << endl; // Print the read word
            }
            noWord++;
        } while (ss); // While there is more to read
        noLine++;
        cout << endl;
    }

    // *********** APO DO KAI KATO DIKO SAS  ************* //

    //    ██████╗░░█████╗░███╗░░██╗░██████╗░███████╗██████╗░
    //    ██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔════╝██╔══██╗
    //    ██║░░██║███████║██╔██╗██║██║░░██╗░█████╗░░██████╔╝
    //    ██║░░██║██╔══██║██║╚████║██║░░╚██╗██╔══╝░░██╔══██╗
    //    ██████╔╝██║░░██║██║░╚███║╚██████╔╝███████╗██║░░██║
    //    ╚═════╝░╚═╝░░╚═╝╚═╝░░╚══╝░╚═════╝░╚══════╝╚═╝░░╚═╝

    // ************************************************** //

    cout << "****************************" << endl << "Oresti Pare:" << endl << "****************************" << endl;
    int max_slices = max_slices_of_pizza;
    int pizza_type_num = different_types_of_pizza;
    vector<int> pizzas_selected {1,2,3,4,5,6};
    int types_selected = -1;

    cout << "Max Pizza Slices: " << max_slices << endl;
    cout << "Different Pizza Types: " << pizza_type_num << endl;
    // Printing the original vector(before sort())
     cout << "Pizza Data:" << endl;
     for (uint i=0; i<pizza_data.size(); i++){
         cout << "Slices: " << pizza_data[i].first << " Type:" << pizza_data[i].second << endl;

     }

     export_file(input_file,types_selected,pizzas_selected);

}
