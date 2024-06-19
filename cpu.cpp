#include "stats.hpp"


void cpuTitle(){

  ifstream file("/proc/stat");
  string line;
  // Set to -1 to account for the overall CPU stats, which should not add to the total core count.
  int totalCPUCores = -1;

  if(!file.good()){
    cerr << "Could not open file." << endl;
    exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
    // For each line containing "cpu", add 1 to the variable.
    if(line.find("cpu") != line.npos){
      ++totalCPUCores;
    }
  }

  cout << "Total CPU Cores: " << totalCPUCores << endl;
  genLine();
  cout << setw(8) << left << "CPU" << "busy" << setw(8) << right << "idle" << setw(8) << right << "system" << setw(8) << right << "nice" << endl;

  file.close();
}


void cpuStats() {
  ifstream file("/proc/stat");
  string line;
  
  if(!file.good()){
    cerr << "Could not open file." << endl;
    exit(EXIT_FAILURE);
  }

  file.ignore(1);  // Will ignore first character of the file, which belongs to the line containing overall CPU stats. This line will no longer start with "cpu" but "pu" instead.

  while(getline(file, line)){
    string cpuName;
    float user_cycles, nice_cycles, system_cycles, idle_cycles;

    // For each line containing "cpu", take and print the first four numerical values which have been converted to readable percentages.
    if(line.find("cpu") != line.npos){
      stringstream linestream(line);
      linestream >> cpuName >> user_cycles >> nice_cycles >> system_cycles >> idle_cycles;
      float totalUsage = user_cycles + nice_cycles + system_cycles + idle_cycles;
      totalUsage = totalUsage/100;
      cout << setw(7) << left << cpuName << fixed << setprecision(1) << setw(4) << user_cycles/totalUsage << "%" << setw(7) << right << idle_cycles/totalUsage << "%" << setw(7) << right << system_cycles/totalUsage << "%" << setw(7) << right << nice_cycles/totalUsage << "%" << endl;
    }
  }

  file.close();
}
