#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../headers/Book.h"
#include "../headers/Library.h"
#include "../headers/Algorithms.h"


using namespace std;



int mainAlgorithm(vector<Book*>& books, vector<Library*>& library, int& numDays, vector<pair<int,vector<int>>>& Results) {
    // Keep total score to print on main
    uint total_score = 0;

    // Repeat for every Library
    for (int i = 0; i < library.size(); i++) {

        vector<int> lib_books;
        if (library[i]->checked)
            continue;
        int remainingDays = numDays - library[i]->signUpDays;
        //cout <<i <<"<-id, remainingDays->" << remainingDays << endl;
        //calculate magic
        vector<int> currBooks = library[i]->books;
        int remainingDays1 = remainingDays;

        vector< pair <int,int> > currBookScores;
        for (int b = 0; b < currBooks.size(); b++) {
            for (int b1 = 0; b1 < books.size(); b1++) {
                if (books[b1]->id == currBooks[b] && books[b1]->checked == false) {
                    currBookScores.push_back( make_pair(books[b1]->score, currBooks[b]));
                }
            }
        }

        // Using simple sort() function to sort
        sort(currBookScores.begin(), currBookScores.end());

        uint scoreCurLib = 0;
        while (remainingDays > 0) {
            remainingDays = remainingDays - library[i]->scanBooks;
            if (currBookScores[currBookScores.size()-1].first != -100) {
                lib_books.push_back(currBookScores[currBookScores.size()-1].second);
                scoreCurLib += (uint) currBookScores[currBookScores.size()-1].first;
                currBookScores[currBookScores.size()-1].first = -100;
                for (int b1 = 0; b1 < books.size(); b1++) {
                    if (books[b1]->id == currBookScores[currBookScores.size()-1].second) {
                        books[b1]->checked = true;
                    }
                }
                sort(currBookScores.begin(), currBookScores.end());
            }
        }
        cout << "Score of Library " << i << ": " << scoreCurLib << endl;
        total_score += scoreCurLib;

        Results.push_back(make_pair(library[i]->id, lib_books));

        library[i]->checked = true;

        //return 1;
    }
    return total_score;
}
