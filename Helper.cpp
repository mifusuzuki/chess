#include "Helper.h"

#include "Constants.h"

#include <iostream>
#include <string>

bool isValidPos(std::string pos)
{
    if (pos.size() != 2)
    {
        // Write code to print error
        std::cerr << "[ERROR] Length of position does not match 2" << std::endl;
        return false;
    }

    char col = pos[0];
    char row = pos[1];

    if (!(col>=FILE_MIN && col<=FILE_MAX))
    {
        std::cerr << "[ERROR] File value is not between A to H" << std::endl;
        return false;
    }

    if (!(row>=RANK_MIN && row<=RANK_MAX))
    {
        std::cerr << "[ERROR] Rank value is not between 1 to 8" << std::endl;
        return false;
    }

    return true;
}

bool isValidIndex(int index)
{
    if (!(index>=INDEX_MIN && index<=INDEX_MAX))
    {
        return false;
    }
    return true;
}

int getRow(std::string pos)
{
    // Convert the second element of pos

    switch (pos[1])
    {
        case '1':
            return 7;
        case '2':
            return 6;
        case '3':
            return 5;
        case '4':
            return 4;
        case '5':
            return 3;
        case '6':
            return 2;
        case '7':
            return 1;
        case '8':
            return 0;
    }

    return -1;
}

int getCol(std::string pos)
{
    // Convert the first element of pos

    return (int)pos[0]-65;
}

std::string getPos(int row, int col)
{
    // Convert row and col

    std::string pos;
    pos = (char)(col+65);
    
    switch (row)
    {
        case 0:
            pos += '8';
            break;
        case 1:
            pos += '7';
            break;
        case 2:
            pos += '6';
            break;
        case 3:
            pos += '5';
            break;
        case 4:
            pos += '4';
            break;
        case 5:
            pos += '3';
            break;
        case 6:
            pos += '2';
            break;
        case 7:
            pos += '1';
            break;
    }

    return pos;
}
