#include "stats.hpp"

int main() {

  while(true){
  clearScreen();
  genLine();
  cpuTitle();
  cpuStats();
  memStats();
  sysStats();
  genLine();
  // Wait for 500ms before next loop
  usleep(500000);
  }

return 0;
}
