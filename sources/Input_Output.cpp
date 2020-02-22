#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
#include "../headers/Input_Output.h"


using namespace std;


// Replace file's format (from .txt to .in)
string replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == string::npos)
        return "couldn't create file";
    return str.replace(start_pos, from.length(), to);
}

// Print a file given
void print_file(string file_given) {
    ifstream f(file_given);
    string line;
    while (getline(f, line))
        cout << line << '\n';
}


// Read the file and store the arguments
void import_File_Arguments(string file_given, int& numBooks, int& numLibraries, int& numDays,
                                vector<Book*>& Books, vector<Library*>& Libraries) {
    // Read input files
    ifstream f(file_given);
    string line;
    int noLine = 1, currLID = 0;
    int numLibrBooks = -1, signUpDays = -1, scanBooks = -1;

    // Get arguments of every line from input file
    while (getline(f, line)){
        istringstream ss(line);     // Used to split line around spaces.
        int noWord = 1;         // Used to store the right argument each time
        vector<int> book_ids;
        do { // Traverse through all words
            string word; // Read a word
            ss >> word;
            if (word != "") {
                // First line, read number of books, libraries and days for scanning
                if (noLine == 1) {
                    switch (noWord) {
                        case 1:
                            numBooks = stoi(word);
                        case 2:
                            numLibraries = stoi(word);
                        case 3:
                            numDays = stoi(word);
                    }
                }
                // Second line, read the score of each book (store an array of books)
                else if (noLine == 2) {
                    //cout << "Book:" << word << endl;
                    Books.push_back(new Book(noWord-1, stoi(word)));
                }
                // Store information of each library (odd lines (3, 5, 7, 9...))
                else if (noLine % 2 == 1) {
                    switch (noWord) {
                      case 1:
                          numLibrBooks = stoi(word);
                      case 2:
                          signUpDays = stoi(word);
                      case 3:
                          scanBooks = stoi(word);
                    }
                }       // Else store the books (ids) that current library has (even lines)
                else {
                    book_ids.push_back(stoi(word));
                }
                //cout << "Word:" <<  word << endl; // Print the read word
            }
            noWord++;
            // While there is more to read
        } while (ss);

        // Now store all library's information on the Library vector
        if ((noLine != 1) && (noLine%2 != 1) && (noLine != 2)) {
            Libraries.push_back(new Library(currLID++, numLibrBooks, signUpDays, scanBooks, book_ids));
        }
        noLine++;
    }
}


// Export results onto a new output file
void export_Results(string file_given, vector <pair <int, vector<int>> > Results) {
    // Give a name to the output file
    string output_name = replace(file_given,".txt",".out");
    cout << endl << "Printing to: " << output_name << endl;
    ofstream output_file(output_name);

    if (output_file.is_open()) {
        // Print the number of libraries
        output_file << Results.size() << endl;
        // Printing the vector
        for (int h = 0; h < Results.size(); h++) {
            // "first" and "second" are used to access
            // 1st and 2nd element of pair respectively
            output_file << Results[h].first << " " << Results[h].second.size() << endl;
            for (int h1 = 0; h1 < Results[h].second.size(); h1++) {
                output_file << Results[h].second[h1] << " ";
            }
            output_file << endl;
        }
    }
    else cout << "Unable to open file";

    output_file.close();
}
