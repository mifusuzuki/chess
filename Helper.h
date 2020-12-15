#ifndef HELPER_H
#define HELPER_H

#include <string>

// Check if give pos is valid
bool isValidPos(std::string pos);

// Get row index from a given position
int getRow(std::string pos);

// Get col index from a given position
int getCol(std::string pos);

// Get position correspondig to given row and col indexes
std::string getPos(int row, int col);

#endif