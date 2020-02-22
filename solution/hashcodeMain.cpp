#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
#include "../headers/Input_Output.h"
#include "../headers/Algorithms.h"

using namespace std;


int main(int argc, char *argv[]) {
    // store all argument into a string vector
    vector<string> Arguments(argv, argv + argc);
    // basic arguments
    vector<string> input_files;

    // process all arguments
    if (Arguments[1] == "-i") {
        for (int i = 2; i < argc; i++) {
            input_files.push_back(Arguments[i]);
        }
    }
    // check for errors (optional)
    if (input_files.size() == 0)
        cout << "No input file given" << endl;
    else {
        cout << "----------------------------------------------" << endl;
        for (uint i = 0; i < input_files.size(); i++) {
            /*cout << endl << "Printing file to see if it is ok...\n";
            print_file(input_files[i]);
            cout << "----------------------------" << endl;*/
            cout << "\"" << input_files[i] << "\": OK" << endl;
        }
        cout << "----------------------------------------------" << endl;
    }
    // Keep total score (from all files)
    uint score = 0;

    // Execution for all files
    for (uint i = 0; i < input_files.size(); i++) {
        // store input files data to variables and structures
        int numBooks = -1;
        int numLibraries = -1;
        int numDays = -1;
        vector <Book*> Books ;
        vector <Library*> Libraries;

        // Store final results for output
        vector < pair <int, vector<int>> > Results;

        // Read file arguments and store them in the above variables
        import_File_Arguments(input_files[i], numBooks, numLibraries, numDays, Books, Libraries);

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
        //printBooks(Books);
        //printLibraries(Libraries);

        // Run an algorithm for best results (from solutions file)
        uint current_score = mainAlgorithm(Books, Libraries, numDays, Results);
        cout << "Score of file \"" << input_files[i] << "\": " << current_score << endl;
        score += current_score;

        // Print results in file
        export_Results(input_files[i], Results);
        cout << "----------------------------------------------" << endl;

        // Delete dynamically allocated structures
        for (uint i = 0; i < Books.size(); i++) {
            delete Books[i];
        }
        for (uint i = 0; i < Libraries.size(); i++) {
            delete Libraries[i];
        }
    }
    cout << "Total Score: " << score << endl;
    cout << "----------------------------------------------" << endl;

    return 0;
}
