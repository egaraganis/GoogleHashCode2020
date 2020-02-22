#ifndef BOOKS_H
#define BOOKS_H

#include <vector>


class Book {
    public:
        int id;
        int score;
        bool checked;
        Book(int id, int score);
};

void printBooks(std::vector<Book*> books);


#endif
