#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "../headers/Library.h"

using namespace std;

Library::Library(int id,int numBooks,int signUpDays,int scanBooks,vector<int> book_ids){
  this->id = id;
  this->numBooks = numBooks;
  this->signUpDays = signUpDays;
  this->scanBooks = scanBooks;
  this->books = book_ids;
  this->checked = false;
}

void Library::setNumBooks(int numBooks){
  this->numBooks = numBooks;
}

void Library::setSignUpDays(int signUpDays){
  this->signUpDays = signUpDays;
}

void Library::setScanBooks(int scanBooks){
  this->scanBooks = scanBooks;
}

void printLibraries(std::vector<Library*> library){
  cout << "Printing libraries:" << endl;
  for(int i=0; i<library.size(); i++){
    cout << "id:" << library[i]->id << ",numBooks:" << library[i]->numBooks << "," << "signUpDays:" << library[i]->signUpDays << "," << "scanBooks:" << library[i]->scanBooks << endl;
    for(int j=0; j<library[i]->books.size(); j++){
      cout << library[i]->books[j] << " , ";
    }
    cout << endl;
  }
}
