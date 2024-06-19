#include "stats.hpp"


void memStats(){
  ifstream file("/proc/meminfo");
  string line;
  int total, free, cached, buffered;

  if(!file.good()){
    cerr << "Could not open file." << endl;
    exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
    stringstream linestream(line);
    string token;

    getline(linestream, token, ' ');
    if (token == "MemTotal:"){
      linestream >> total;
    }
    if (token == "MemFree:"){
      linestream >> free;
    }
    if (token == "Cached:"){
      linestream >> cached;
    }
    if (token == "Buffers:"){
      linestream >> buffered;
    }
  }
  genLine();
  // Each value divided by 1024 to convert them from KB to MB.
  cout << "MEMORY" << setw(4) << "" << "Total: " << total/1024 << "MB" << endl << setw(10) << "" << "Free: " << free/1024 << "MB" << endl << setw(10) << "" << "Cached: " << cached/1024 << "MB" << endl << setw(10) << "" << "Buffered: " << buffered/1024 << "MB" << endl;

  file.close();
}
