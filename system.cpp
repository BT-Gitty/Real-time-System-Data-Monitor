#include "stats.hpp"


// Local function that will convert its given parameter from seconds to hours, minutes and seconds.
void convertTime(float specTime){
  int hours, minutes, seconds;
  seconds = (int)specTime % 60;  // Use of modulo to take remainder only.
  minutes = (int)specTime / 60;
  hours = minutes / 60;
  minutes = minutes % 60;  // Use of modulo to take remainder only.
  cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds" << endl;
}


void sysStats(){
  ifstream file("/proc/uptime");
  string line;
  float uptime, idletime;

  if(!file.good()){
    cerr << "Could not open file." << endl;
    exit(EXIT_FAILURE);
  }

  while(getline(file, line)){
    stringstream linestream(line);
    linestream >> uptime >> idletime;
  }
  
  genLine();

  cout << "SYSTEM" << setw(4) << "" << "UP for ";
  convertTime(uptime);  // Calls the local function, defined above.

  cout << setw(10) << "" << "IDLE for ";
  convertTime(idletime);  // Calls the local function, defined above.

  genLine();


//-----------Power consumption stats-----------

  // Divide by 1000000 to convert to MJoules.
  uptime = uptime/1000000 * 125;  // 125 Watts is the common TDP for 12th Gen Intel microprocessors.
  idletime = idletime/1000000 * 15;  // 15 Watts is the common idle consumption for 12th Gen Intel microprocessors.

  cout << fixed << setprecision(2) << "ENERGY" << setw(4) << "" << "In Active State: " << uptime << "MJoules" << endl << setw(10) << "" << "In Idle State: " << idletime << "MJoules" << endl;

  file.close();
}
