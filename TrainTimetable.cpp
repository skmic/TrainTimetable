#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

class TrainTimetable
{
private:
  string m_sName;
  bool m_bDirection;  //North or South
  std::vector<string> m_Stops;
  std::vector<int> m_StopTimes; //Time taken to reach every stop in minute. First stop is always 0 minutes
  int m_nTrainFrequency;        //After how many minutes new train comes
public:
  TrainTimetable()
  {
  }
  TrainTimetable(string sName,bool bDirection, std::vector<string> Stops, std::vector<int> StopTimes, int nTrainFrequency):
    m_sName(sName), m_bDirection(bDirection), m_Stops(Stops), m_StopTimes(StopTimes), m_nTrainFrequency(nTrainFrequency)
  {
    //initializations
  }

  void vDisplayTimetable(void);
};

//Class functions
void TrainTimetable::vDisplayTimetable(void)
{
  string Temp;
  std::stringstream TempStream;
  cout<<"Displaying train time table below" <<endl;
  cout << "Linie " << this->m_sName << " "; 
  if(this->m_bDirection)
    cout << "North" << endl;
  else
    cout << "South" << endl;
  for (std::size_t i = 0; i != this->m_Stops.size(); ++i)
  {
    TempStream.str("");
    TempStream << this->m_Stops[i];
    TempStream << "    " << this->m_StopTimes[i] << "    " << this->m_StopTimes[i] + this->m_nTrainFrequency << endl;


    cout << TempStream.str() << endl;
    TempStream.clear();
  }
}

int main(int argc, char **argv)
{
  string sName;
  string sStop;
  int nStopTime;
  bool bDirection = true;
  std::vector<string> Stops;
  std::vector<int> StopTimes;
  int nTrainFrequency = 15;
  time_t tt;
  system_clock::time_point today = system_clock::now();
  tt = system_clock::to_time_t(today);

  std::cout << "Train Time Table Display" <<endl;

  cout << ctime(&tt) <<endl;


  cout << "Enter train data" << endl;
  cout << "Train Name" << endl;
  cin >> sName;
 // cout << "Train Frequency" << endl;
 // cin >> nTrainFrequency;

 // cout << "Train Direction" << endl;
 // cin >> bDirection;
  
  cout << "Stops" << endl;
  while (cin >> sStop)
  {
    if(sStop!="STOP")
      Stops.push_back(sStop);
    else break;
  }
  cout << "Stop Times in minutes" << endl;
  while (cin >> nStopTime)
  {
    if(nStopTime != 99)
      StopTimes.push_back(nStopTime);
    else break;
  }

  TrainTimetable t(sName, bDirection, Stops, StopTimes, nTrainFrequency);
  t.vDisplayTimetable();

  return 0;
}
