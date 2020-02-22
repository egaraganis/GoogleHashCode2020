#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <vector>
#include <bits/stdc++.h>

#include "./Library.h"
#include "./Book.h"


void print_file(std::string fileGiven);
void export_file(std::string file_given, std::vector<int> results);
void import_File_Arguments(std::string file_given, int& numBooks, int& numLibraries, int& numDays,
                                std::vector<Book*>& Books, std::vector<Library*>& Libraries);
void export_Results(std::string file_given, std::vector <std::pair <int, std::vector<int>> > Results);

#endif
