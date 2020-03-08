#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
#include "../headers/Algorithms.h"


using namespace std;


bool bookSort(const Book* a, const Book* b) {
    return (a->score > b->score);
}

bool libraryScoreSort(const Library* a, const Library* b) {
    return (a->score > b->score);
}
bool librarySignUpSort(const Library* a, const Library* b) {
    return (a->signUpDays < b->signUpDays);
}
bool libraryScanSort(const Library* a, const Library* b) {
    return (a->scanBooks > b->scanBooks);
}

bool finalBookSort(const pair<int,int>& a, const pair<int,int>& b) {
    return (a.second > b.second);
}



void secondAlgorithm(vector<Book*>& books, vector<Library*>& libraries, int& numDays, vector<pair<int,vector<int>>>& Results) {
    // Sort books by their score
    //printBooks(books);
    //sort(books.begin(), books.end(), bookSort);
    //printBooks(books);

    // If books are not sorted by score, then sort them first (signup or scan time) and then remove duplicates
    sort(libraries.begin(), libraries.end(), librarySignUpSort);
    //sort(libraries.begin(), libraries.end(), libraryScanSort);

    // Calculate total score, including dupicates (but not duplicates from the same library)
    /*for (uint i = 0; i < libraries.size(); i++) {
        // First check which books are contained in each library
        for (uint j = 0; j < libraries[i]->books.size(); j++) {
            // Keep current book's id
            int tempBookId = libraries[i]->books[j];
            // Find current book's score and then add it in library's score
            vector<Book*>::iterator it;
            Book *tempBook = new Book(libraries[i]->books[j], 0);
            it = find_if(books.begin(), books.end(), [&tempBookId](const Book* tempBook) {return tempBook->id == tempBookId;});
            if (it != books.end()) {
                //cout << libraries[i]->books[j] << "  " << (*it)->id << " - " << (*it)->score << endl;
                bool bookPreviouslyFound = false;
                for (uint k = 0; k < j; k++) {
                    if (libraries[i]->books[k] == tempBookId) {
                        bookPreviouslyFound = true;
                        break;
                    }
                }
                if (!bookPreviouslyFound) {
                    libraries[i]->score += (*it)->score;
                }
            }
            delete tempBook;
        }
    }
    sort(libraries.begin(), libraries.end(), libraryScoreSort);*/

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
                //cout << "Book:" << tempBookId << " has already been checked" << endl;
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
    //printLibraries(libraries);

    // Sort libraries by their score
    sort(libraries.begin(), libraries.end(), libraryScoreSort);
    printLibraries(libraries);

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
