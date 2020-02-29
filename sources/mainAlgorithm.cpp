#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
#include "../headers/Algorithms.h"


using namespace std;

void mainAlgorithm(vector<Book*>& books, vector<Library*>& library, int& numDays, vector<pair<int,vector<int>>>& Results) {
    bool flag = true;
    int a = -2;         //this is for the signup day
    int b = -3;         //this is for the days that need for one book to be scanned
    int c = 2;          // this is for the book scores
    int statIndex = 0;
    while(numDays > 0 && flag) {
        int bestPosition = -1;
        int bestScore;
        vector<int> bestBooks;
        for(int i=0; i<library.size(); i++) {
            if(library[i]->signUpDays < numDays) {
                int remainingDays = numDays - library[i]->signUpDays;
                vector< pair <int,int> > currBookScores;
                //get all the unchecked books of current library
                for(int j=0; j<library[i]->books.size(); j++) {
                    //find it in books by id
                    if(!books[library[i]->books[j]]->checked)
                        currBookScores.push_back( make_pair(books[library[i]->books[j]]->score, library[i]->books[j]));
                }
                // Using simple sort() function to sort by score the books of current library
                if(currBookScores.size() > 0) {
                    sort(currBookScores.begin(), currBookScores.end());
                    vector<int> scannedBooks;
                    int bookScore = (-1) * (library[i]->signUpDays + library[i]->scanBooks);         //here you can use a and b! (here a == b == -1)
                    int currBooksPosition = currBookScores.size() -1;
                    //while i have more days & more books
                    bool noMoreBooks = false;
                    while(remainingDays > 0 && !noMoreBooks) {
                        for(int s=0; s < library[i]->scanBooks; s++) {
                            bookScore += currBookScores[currBooksPosition].first;                   //here goes the c! (here c == 1)
                            scannedBooks.push_back(currBookScores[currBooksPosition].second);
                            currBooksPosition--;
                            if(currBooksPosition < 0) {
                                noMoreBooks = true;
                                break;
                            }
                        }
                        remainingDays--;
                    }
                    //if it is the first time or the current score is better, change the best library
                    if (i == 0 || bookScore > bestScore) {
                        bestPosition = i;
                        bestScore = bookScore;
                        bestBooks = scannedBooks;
                    }
                }
            }
        }
        //check the books that we got from the best library
        vector<int> bestBooksIds;
        for(int i=0; i<bestBooks.size(); i++) {
            books[bestBooks[i]]->checked = true;
            bestBooksIds.push_back(books[bestBooks[i]]->id);
        }
        if(bestPosition >= 0) {
            cout << statIndex++ << ". Library: " << library[bestPosition]->id << " was selected!" << bestBooksIds.size() << " books were scanned!" << endl;
            numDays -= library[bestPosition]->signUpDays;
            Results.push_back(make_pair(library[bestPosition]->id, bestBooksIds));
            library.erase(library.begin() + bestPosition);
        }
        if(library.size() == 0 || bestPosition == -1)
            flag = false;
    }
}
