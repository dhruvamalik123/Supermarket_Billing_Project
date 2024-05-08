#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;
int main ()
{
  time_t timetoday ; 
  time (&timetoday);
  struct tm * now = localtime( & timetoday );
  stringstream ss;

  ss << (now->tm_year + 1900) << '-'
     << (now->tm_mon + 1) << '-'
     <<  now->tm_mday << "-"
     <<  now->tm_hour << ":"
     <<  now->tm_min << ":"
     <<  now->tm_sec;

string y,z;
y=ss.str();
z=y+".txt";
cout<<z;
/*  ofstream myfile;
  myfile.open (ss.str());
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
*/
  return(0);
}