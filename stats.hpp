#include <iomanip>  // Library for various formatting purposes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

void genLine();
// Both used in "other.cpp"
void clearScreen();


void cpuTitle();
// Both used in "cpu.cpp"  Command: cat /proc/stat
void cpuStats();


void memStats();  // Used in "memory.cpp"  Command: cat /proc/meminfo


void sysStats();  // Used in "system.cpp  Command: cat /proc/uptime
