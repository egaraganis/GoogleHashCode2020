#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "./Library.h"
#include "./Book.h"

using namespace std;

void print_file(string fileGiven);
void export_file(string file_given, vector<int> pizzas_selected);
int orestis(int a, int b, int c, vector<Book*> books, std::vector<Library*> library, int numDays);
#endif
