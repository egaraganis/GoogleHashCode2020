#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<bits/stdc++.h>

#include "../headers/helper_functions.h"
#include "../headers/Library.h"
#include "../headers/Book.h"

using namespace std;

string replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return "couldn't create file";
    return str.replace(start_pos, from.length(), to);
}


void print_file(string file_given){
    ifstream f(file_given);
    string line;
    while(getline(f, line))
      cout << line << '\n';
}

void export_file(string file_given, vector<int> pizzas_selected){
    string output_name = replace(file_given,".in",".out");
    cout << endl << "Printing to :" << output_name  << endl;
    ofstream output_file(output_name);
    if (output_file.is_open()){
        output_file << pizzas_selected.size() << endl;
        for(uint i=0; i<pizzas_selected.size(); i++)
            output_file << pizzas_selected[i] << " ";
        output_file << endl;
        output_file.close();
    }
    else cout << "Unable to open file";
}

int orestis(int a, int b, int c, vector<Book*> books, vector<Library*> library, int numDays) {
  //for every Library
  vector< pair <int,vector<int>> > LibrScores;

    for(int i=0; i<library.size(); i++){
      vector <int> lib_books;
      if(library[i]->checked)
        continue;
      int remainingDays = numDays - library[i]->signUpDays;
      //cout <<i <<"<-id, remainingDays->" << remainingDays << endl;
      //calculate magic
      vector<int> currBooks = library[i]->books;
      int remainingDays1 = remainingDays;

      vector< pair <int,int> > currBookScores;
      for(int b=0;b<currBooks.size(); b++){
        for(int b1=0; b1<books.size(); b1++){
          if(books[b1]->id == currBooks[b] && books[b1]->checked == false){
            currBookScores.push_back( make_pair(books[b1]->score,currBooks[b]));
          }
        }
      }

      // Using simple sort() function to sort
      sort(currBookScores.begin(), currBookScores.end());
      int scoreCurLib = 0;
      while(remainingDays > 0){
        remainingDays = remainingDays - library[i]->scanBooks;
        if(currBookScores[currBookScores.size()-1].first != -100){
            lib_books.push_back(currBookScores[currBookScores.size()-1].second);
            scoreCurLib += currBookScores[currBookScores.size()-1].first;
          currBookScores[currBookScores.size()-1].first = -100;
          for(int b1=0; b1<books.size(); b1++){
            if(books[b1]->id == currBookScores[currBookScores.size()-1].second){
              books[b1]->checked = true;
            }
          }
          sort(currBookScores.begin(), currBookScores.end());
        }
      }
      cout << "curr score lib:" << scoreCurLib << endl;
      LibrScores.push_back( make_pair(library[i]->id,lib_books));

      ofstream output_file("results.txt");


      // Printing the vector
   for (int h=0; h<LibrScores.size(); h++)
   {
       // "first" and "second" are used to access
       // 1st and 2nd element of pair respectively
       output_file << "1" << endl;
       output_file << LibrScores[h].first << " " << LibrScores[h].second.size() << endl;
       for(int h1=0; h1<LibrScores[h].second.size(); h1++){
        output_file << LibrScores[h].second[h1] << " ";
      }
      output_file << endl;
   }

          output_file.close();

      library[i]->checked = true;

      return 1;

  }
}
