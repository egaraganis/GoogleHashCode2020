#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
#include "../headers/Algorithms.h"


using namespace std;


bool libraryScoreSort(const Library* a, const Library* b) {
    return (a->score > b->score);
}
bool librarySignUpSort(const Library* a, const Library* b) {
    return (a->signUpDays < b->signUpDays);
}
bool libraryScanSort(const Library* a, const Library* b) {
    return (a->scanBooks > b->scanBooks);
}
bool libraryNumBookSort(const Library* a, const Library* b) {
    return (a->numBooks > b->numBooks);
}

bool bookSort(const Book* a, const Book* b) {
    return (a->score > b->score);
}
bool finalBookSort(const pair<int,int>& a, const pair<int,int>& b) {
    return (a.second > b.second);
}



// The idea of this implementation is that the vectors of libraries and books must be sorted according to different factors
// Firstly, every file should be sorted by the signup days (more libraries in the system if those with small signup time come in first)
// Then, for each library, we calculate their score and we also remove the duplicates books, both those on current and other libraries
// At all libraries, their books are sorted by score, so those with best scores insert in the system first
// For some files, another sorting in libraries, depending on their total score, is done

void secondAlgorithm(vector<Book*>& books, vector<Library*>& libraries, int& numDays, vector<pair<int,vector<int>>>& Results, string filename) {

    // Different sortings, depending on file
    bool b = false, c = false, d = false, e = false, f = false;
    size_t found = filename.find("b_read_on");
    if (found != string::npos) b = true;
    found = filename.find("c_incunabula");
    if (found != string::npos) c = true;
    found = filename.find("d_tough_choices");
    if (found != string::npos) d = true;
    found = filename.find("e_so_many_books");
    if (found != string::npos) e = true;
    found = filename.find("f_libraries_of_the_world");
    if (found != string::npos) f = true;

    // Sort the libraries firstly by signup days (except d_tough_choices, where sorting is done by num of books)
    if (d) {
        sort(libraries.begin(), libraries.end(), libraryNumBookSort);
    } else {
        sort(libraries.begin(), libraries.end(), librarySignUpSort);
    }

    // Keep each book only once
    vector<int> uniqueBooks;

    // Find every library's score and remove duplicates
    for (uint i = 0; i < libraries.size(); i++) {
        libraries[i]->score = 0;
        // First check which books are contained in each library
        for (uint j = 0; j < libraries[i]->books.size(); j++) {
            // Keep current book's id
            int tempBookId = libraries[i]->books[j];

            // Check if current book has already been checked before
            vector<int>::iterator iterId;
            iterId = find(uniqueBooks.begin(), uniqueBooks.end(), tempBookId);
            // If the book has not been checked, then keep it on the list
            if (iterId == uniqueBooks.end()) {
                uniqueBooks.push_back(tempBookId);
                // Find current book's score and then add it in library's score
                vector<Book*>::iterator it;
                Book *tempBook = new Book(libraries[i]->books[j], 0);
                it = find_if(books.begin(), books.end(), [&tempBookId](const Book* tempBook) {return tempBook->id == tempBookId;});
                if (it != books.end()) {
                    //cout << libraries[i]->books[j] << "  " << (*it)->id << " - " << (*it)->score << endl;
                    libraries[i]->finalBooks.push_back(make_pair(tempBookId, (*it)->score));
                    libraries[i]->score += (*it)->score;
                }
                delete tempBook;
                //cout << "Book:" << tempBookId << " added" << endl;
            } else {
                // Remove the copied book
                vector<int>::iterator iterId2;
                iterId2 = find(libraries[i]->books.begin(), libraries[i]->books.end(), tempBookId);
                if (iterId2 != libraries[i]->books.end()) {
                    libraries[i]->books.erase(iterId2);
                    j--;
                    //cout << "Book:" << tempBookId << " just removed (copy)" << endl;
                }
            }
        }
        sort(libraries[i]->finalBooks.begin(), libraries[i]->finalBooks.end(), finalBookSort);
    }

    // Sort libraries by their score
    if (e || f || d) {
        sort(libraries.begin(), libraries.end(), libraryScoreSort);
    }
    //printLibraries(libraries);

    // Attach libraries and their books on final (results) vector
    for (uint i = 0; i < libraries.size(); i++) {
        if (libraries[i]->finalBooks.size() > 0) {
            vector<int> booksFinalOrder;
            if (libraries[i]->finalBooks.size() != libraries[i]->books.size()) {
                cout << "Something has gone wrong in library:" << i << endl;
            }
            for (uint j = 0; j < libraries[i]->finalBooks.size(); j++) {
                booksFinalOrder.push_back(libraries[i]->finalBooks[j].first);
            }
            Results.push_back(make_pair(libraries[i]->id, booksFinalOrder));
        }
    }
}
