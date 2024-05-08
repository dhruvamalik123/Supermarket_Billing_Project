#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

int main(){
    time_t timetoday ; 
    time (&timetoday);
    struct tm * now = localtime( & timetoday );
    stringstream ss;
    string name;
    cin >> name;
    ss << name ; //<<(now->tm_year + 1900) << '-'<< (now->tm_mon + 1) << '-'<<  now->tm_mday << "-"<<  now->tm_hour << ":"<<  now->tm_min << ":"<<  now->tm_sec;
    string output= ss.str();
    ofstream file;
    file.open(output);
    file << "lol fuck off mann";
    file.close();
    return 0;
}
