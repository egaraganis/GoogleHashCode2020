#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>


class Library {
    public:
        int id;
        int numBooks;
        int signUpDays;
        int scanBooks;
        int score;
        std::vector<int> books;
        std::vector<std::pair<int,int>> finalBooks;
        Library(int id, int numBooks, int signUpDays, int scanBooks, std::vector<int>& book_ids);
};

void printLibraries(std::vector<Library*>& library);


#endif
