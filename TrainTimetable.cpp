#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
  std::cout<<"Displaying train time table below" <<endl;
}

int main(int argc, char **argv)
{
  string sName;
  string sStop;
  int nStopTime;
  bool bDirection;
  std::vector<string> Stops;
  std::vector<int> StopTimes;
  int nTrainFrequency;


  std::cout << "Train Time Table Display" <<endl;
  cout << "Enter train data" << endl;
  cout << "Train Name" << endl;
  cin >> sName;
  cout << "Stops" << endl;
  while (cin >> sStop)
  {
    if(sStop!="\n")
      Stops.push_back(sStop);
    else break;
  }
  cout << "Stop Times in minutes" << endl;
  while (cin >> nStopTime)
    StopTimes.push_back(nStopTime);
  cout << "Train Frequency" << endl;
  cin >> nTrainFrequency;

  TrainTimetable t;
  t.vDisplayTimetable();

  return 0;
}
