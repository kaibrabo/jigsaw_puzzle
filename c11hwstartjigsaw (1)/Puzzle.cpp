#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Puzzle.h"
#include "Token.h"

// Your implementation goes here
Puzzle::Puzzle(std::string fileName) {
    std::string line;
    std::fstream myFile;
    std::string first;

    myFile.open( fileName );
    
    // sets pieceCount
    getline(myFile, first);
    pieceCount = std::stoi(first);
    
    // initialize pieces array
    pieces = new Token*[pieceCount];

    // loop through each line of txt file
    for (int i = 0; i < pieceCount; i++) {
        int l, r, c;

        // extract each line
        getline(myFile, line);

        // splits string into 3 ints
        std::istringstream p( line );
        p >> l >> r >> c;

        // keep track of the highest row and column number
        if (rowCount < r) rowCount = r;
        if (colCount < c) colCount = c;

        // create instance of Token
        Token * piece = new Token(l, r, c);

        // set each pieces index
        pieces[i] = piece;
    }

    // increment row and col to set proper size
    // set rowCount and colCount accordingly to avoid data corruption later
    rowCount++;
    colCount++;

    myFile.close();
};
// constructor: load the puzzle pieces into the dynamic pieces array

void Puzzle::printPieces() {
    for(int i = 0; i < pieceCount; i++) {
        Token * piece = pieces[i];

        std::cout << "Printing letter # " << i << "  Puzzle piece '" << piece->letter << "' is located at row, col = (" << piece->row << ", " << piece->col << ")"<< std::endl;
    }
};
// print the list of randomized puzzle pieces

// So you will need to create rowCount rows of pointers to pointers to Tokens, and in each row, you will want to create colCount null Token pointers. Note: the grid is a grid of pointers to Tokens, not a grid of Token instances or characters. You will not yet know the pointers to the specific Token instances, so this step is all about allocating the grid, and then filling out the grid with null pointers that we will overwrite in the next step below.

void Puzzle::loadGrid() {
    // set grid to 2x2 matrix for pointers
    // set up rows
    grid = new Token **[rowCount];
    
    // create columns for each row
    for (int i = 0; i < rowCount; i++) {
        grid[i] = new Token*[colCount];
    }
    
    // loop thru pieces arr, get pointer at pieces[i]
    for (int j = 0; j < pieceCount; j++) {
        int r = pieces[j]->row;
        int c = pieces[j]->col;
        grid[r][c] = pieces[j];
    }
};
// allocate the grid and copy pieces pointers to their correct location int the grid;

Puzzle::~Puzzle() {
    delete[] grid;
    delete[] pieces;
};
// destructor - when we delete the Puzzle instance, the destructor should clean up all "new" allocations for pieces and grid

void Puzzle::printGrid() {
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            std::cout << grid[r][c]->letter;
        }
        std::cout << std::endl;
    }
};
// print the entire puzzle, using the grid data member
