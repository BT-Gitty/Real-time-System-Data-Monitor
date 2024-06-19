#include "stats.hpp"


// Prints the dashes that separate the sections.
void genLine(){
  cout << "------------------------------------------------------------" << endl;
}


// Erases everything on the console as an output.
void clearScreen() {
  cout << "\033[2J\033[1;1H";
}
