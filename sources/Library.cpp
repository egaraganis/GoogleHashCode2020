#include <iostream>
#include <vector>

#include "../headers/Library.h"

using namespace std;


Library::Library(int id, int numBooks, int signUpDays, int scanBooks, vector<int>& book_ids) {
    this->id = id;
    this->numBooks = numBooks;
    this->signUpDays = signUpDays;
    this->scanBooks = scanBooks;
    this->books = book_ids;
    this->score = 0;
}


void printLibraries(vector<Library*>& library) {
    cout << "---------Printing libraries:----------" << endl;
    for (int i = 0; i < library.size(); i++) {
        // Print current library's information
        cout << "id:" << library[i]->id << ", numBooks:" << library[i]->numBooks << ", signUpDays:" << library[i]->signUpDays
                << ", scanBooks:" << library[i]->scanBooks << ", score:" << library[i]->score << endl;
        // Print current library's book ids
        for (int j = 0; j < library[i]->finalBooks.size(); j++) {
            /*if (j != library[i]->finalBooks.size()-1) {
                cout << library[i]->finalBooks[j].first << " , ";
            }
            else cout << library[i]->finalBooks[j].first << endl;*/
        }
    }
    cout << endl;
}
