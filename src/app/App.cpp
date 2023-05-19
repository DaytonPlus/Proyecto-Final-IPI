#include <iostream>
#include <stdio.h>
using namespace std;

void Logs(string a...) {
 int s = sizeof(a)/sizeof(string);
 for(int i=0;i<s;i++) cout << "<" << a[i] << endl;
}

string toUppercase(string a) {
 string b = a;
 for (int i = 0; i < b.length(); i++) b[i] = toupper(b[i]);
 return b;
}

#include "Config.cpp"
#include "Lang.cpp"
#include "Colors.cpp"
#include "Logo.cpp"
#include "About.cpp"
#include "ShowMessage.cpp"
#include "Storage.cpp"
#include "Commands.cpp"

void App_Run() {
 //Lang_Set("ES");
 ShowMessage_Load();
 Logo_Draw();
 
 char *tokenPtr;
 string param[8];
 char cmdstr[200];

 string cmd;
 string qcmd = (Config_UseColors) ? Colors_Green(">") + " ": "> ";

 int a = 0;

 while(cmd != "exit") {
  param[5] = {};
  cmdstr[200] = {};
  a = 0;
  cmd = "";

  cout << qcmd;
  cin.getline(cmdstr, 200, '\n');
  tokenPtr = strtok(cmdstr, " ");
  while (tokenPtr != NULL) {
   if (a == 0) cmd = toUppercase((string) tokenPtr);
   else param[a-1] = (string) tokenPtr;
   a++;
   tokenPtr = strtok(NULL, " ");
  }
  if (cmd != "EXIT" && cmd != "") Commands_Run(cmd, param);
 }
}
