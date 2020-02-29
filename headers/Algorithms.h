#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

#include "./Book.h"
#include "./Library.h"
#include "./Input_Output.h"


void mainAlgorithm(std::vector<Book*>& books, std::vector<Library*>& library, int& numDays,
                        std::vector<std::pair<int, std::vector<int>>>& Results);


#endif
