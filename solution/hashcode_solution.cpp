#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
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
    int numBooks = -1;
    int numLibraries = -1;
    int numDays = -1;
    vector <Book*> Books ;
    vector <Library*> Libraries;

    ifstream f(input_file);
    string line;
    int noLine = 1;

    int numLibrBooks=-1,signUpDays=-1,scanBooks=-1;
    while(getline(f, line)){
        istringstream ss(line); // Used to split line around spaces.
        int noWord = 1;
        vector<int> book_ids;
        do { // Traverse through all words
            string word; // Read a word
            ss >> word;
            if(word != ""){
                if(noLine == 1){
                    switch (noWord) {
                        case 1:
                            numBooks = stoi(word);
                        case 2:
                            numLibraries = stoi(word);
                        case 3:
                            numDays = stoi(word);
                    }
                }
                else if(noLine == 2){
                  //Book* newBook = new Book(noWord-1,stoi(word));
                  //cout << "Book:" << word << endl;
                  Books.push_back(new Book(noWord-1,stoi(word)));
                }
                else if(noLine%2 == 1){
                  switch (noWord) {
                      case 1:
                          numLibrBooks = stoi(word);
                      case 2:
                          signUpDays = stoi(word);
                      case 3:
                          scanBooks = stoi(word);
                  }
                }
                else {
                  book_ids.push_back(stoi(word));
                }
                //cout << "Word:" <<  word << endl; // Print the read word
            }
            noWord++;
        } while (ss); // While there is more to read
        if(noLine != 1 && noLine%2 != 1 && noLine !=2) {
          Libraries.push_back(new Library(numLibrBooks,signUpDays,scanBooks,book_ids));
        }
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

    cout << "Number of Books:" << numBooks << endl;
    cout << "Number of Libraries:" << numLibraries << endl;
    cout << "Number of Days:" << numDays << endl;
    printBooks(Books);
    printLibraries(Libraries);

    /*
    //int current_max_slices = 0;
    int current_slices = 0;

    vector<int> pizzas_selected;
    vector<int>::iterator it;

    sort(pizza_data.begin(), pizza_data.end());

    // Printing the original vector(before sort())
    cout << "Pizza Data:" << endl;
    for (uint i = 0; i < pizza_data.size(); i++){
        //cout << "Slices: " << pizza_data[i].first << " Type:" << pizza_data[i].second << endl;
        // Find types maximum slices available
        if ((current_slices + pizza_data[i].first) < max_slices_of_pizza) {
            current_slices += pizza_data[i].first;
        }
        else break;
        // Check if there is another element of this type inside the selected pizzas
        it = find(pizzas_selected.begin(), pizzas_selected.end(), pizza_data[i].second);
        if (it == pizzas_selected.end()) {
            pizzas_selected.push_back(pizza_data[i].second);
        }
    }
    cout << "Max Pizza Slices: " << max_slices_of_pizza << endl;
    cout << "Max Pizza Slices Found: " << current_slices << endl;
    cout << "Different Pizza Types: " << different_types_of_pizza << endl;
    cout << "Different Pizza Types Found: " << pizzas_selected.size() << endl;

    export_file(input_file, pizzas_selected);*/

}
