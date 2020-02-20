#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

class Library {
  public:
    int id;
    int numBooks;
    int signUpDays;
    int scanBooks;
    bool checked;
    std::vector<int> books;
    Library(int id,int numBooks,int signUpDays,int scanBooks,std::vector<int> book_ids);
    void setNumBooks(int numBooks);
    void setSignUpDays(int signUpDays);
    void setScanBooks(int scanBooks);
};

void printLibraries(std::vector<Library*> library);

#endif
