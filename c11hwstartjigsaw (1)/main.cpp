#include <iostream>
#include <fstream>
#include "Puzzle.h"

using namespace std;

 int main() {

  cout << "Building a Jigsaw Puzzle...." << endl;

  // TODO: declare a variable that holds a pointer to a Puzzle Instance (NOT a Puzzle instance). Set it to nullptr
  Puzzle *myPuzzle_ptr = nullptr;

  // TODO: create a new (dynamically allocated) Puzzle instance and store its pointer in myPuzzle_ptr
  myPuzzle_ptr = new Puzzle("puzzle_input_basic.txt");
  
  // TODO: print a raw description all the pieces in the puzzle by calling the printPieces() method from the puzzle pointer (this is not the same as printing the puzzle image)
  // myPuzzle_ptr->printPieces();

  // TODO: initialize the grid and then load it with all the Token pointers by calling the loadGrid() method from the puzzle pointer
  myPuzzle_ptr->loadGrid();

  //  TODO: print the final puzzle image by calling the printGrid() method from the puzzle pointer
  myPuzzle_ptr->printGrid();

  // TODO: delete the what the Puzzle pointer points to: a Puzzle instance, effectively calling the Puzzle destructor
  delete myPuzzle_ptr;

  cout << "Done!" << endl;
  return 0;
}
