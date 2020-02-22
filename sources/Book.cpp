#include <iostream>
#include <vector>

#include "../headers/Book.h"

using namespace std;


Book::Book(int id, int score) {
    this->id = id;
    this->score = score;
    this->checked = false;
}


void printBooks(vector<Book*>& books) {
    cout << "-----------Printing books:------------" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << "\tid:" << books[i]->id << "," << "score:" << books[i]->score << "," << "checked:" << books[i]->checked << endl;
    }
    cout << endl;
}
