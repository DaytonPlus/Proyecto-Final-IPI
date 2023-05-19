string Commands_List[10][4] = {
 {"HELP", "", "", ""},
 {"CLEAR", "CLS"},
 {"ABOUT", "KNOW", "AUTHOR", "AUTHORS"},
 {"ADD", "SET", "", ""},
 {"DEL", "REM", "DELETE", "REMOVE"},
 {"GET", "", "", ""},
 {"FIND", "", "", ""},
 {"LIST", "", "", ""},
 {"MENU", "", "", ""},
 {"OK", "", "", ""}
};

string Commands_Param1List[5][4] = {
 {"HELP", "help", "-h", "-H"},
 {"STUDENT", "student", "-s", "-S"},
 {"EVALUATION", "evaluation", "-e", "-E"},
 {"STUDENTS", "students", "-ss", "-SS"},
 {"EVALUATIONS", "evaluations", "-es", "-ES"}
};

int Commands_Count[2][2] = {
 {10, 4},
 {5, 4},
};

bool Commands_ParamHelp(string cmd) {
 for(int i = 0; i < Commands_Count[1][1]; i++)
  if(Commands_Param1List[0][i] == cmd) return true;
}

int Commands_Find(string cmd) {
 for(int i = 0; i < Commands_Count[0][0]; i++)
  for(int j = 0; j < Commands_Count[0][1]; j++)
   if (Commands_List[i][j] != "" && Commands_List[i][j] == cmd) return i;
 return -1;
}

int Commands_Param1Find(string cmd) {
 for(int i = 0; i < Commands_Count[1][0]; i++)
  for(int j = 0; j < Commands_Count[1][1]; j++)
   if (Commands_Param1List[i][j] != "" && Commands_Param1List[i][j] == cmd) return i;
 return -1;
}

int Commands_Exists(string cmd) {
 return Commands_Find(cmd) >= 0;
}

int Commands_Param1Exists(string cmd) {
 return Commands_Param1Find(cmd) >= 0;
}

void Commands_Base1(string* param);
void Commands_Base2(string* param);
void Commands_Base3(string* param);
void Commands_Base4(string* param);

void Commands_Run(string cmd, string* param) {
 int cmdID = Commands_Find(cmd);

 if(cmdID == 0) {
  ShowMessage_Text("help");
 }
 else if (cmdID == 1) {
  system("clear");
  Logo_Draw();
 }
 else if(cmdID == 2) About_Draw();
 else if(cmdID == 3) {
  int parmID_0 = Commands_Param1Find(param[0]);

  if(parmID_0 == 0) ShowMessage_Text("add", 1);
  else if(param[0] == "") ShowMessage_Text("add", 3);
  else if(parmID_0 > 0) {
   bool parmIH_1 = Commands_ParamHelp(param[1]);
   
   if(parmIH_1) ShowMessage_Text("add", 2, parmID_0-1);
   else {
    if (parmID_0 == 1) Commands_Base1(param);
    else if (parmID_0 == 2) Commands_Base2(param);
    else if (parmID_0 == 3) Commands_Base3(param);
    else if (parmID_0 == 4) Commands_Base4(param);
    else {}
   }
  } else ShowMessage_Text("error", 1, 1, param[0]);
 }
 else if(cmdID == 9) cout << "Yeah, Its for you!" << endl;
 else ShowMessage_Text("error", 0, 1, cmd);
}


void Commands_Base1(string* param) {
 // add -s FirstName SecondName ...

 char name[200];
 cout << "For add a new student you need put the following:\n@Name of Student: ";
 cin.getline(name, 200, '\n');
 int id = Storage_AddStudent(name);
 cout << "Student added, The ID is (" << id << ")!\n";
}

void Commands_Base2(string* param) {
 cout<<"Command 1 Runned true!\n";
}

void Commands_Base3(string* param) {
 cout<<"Command 2 Runned true!\n";
}

void Commands_Base4(string* param) {
 cout<<"Command 3 Runned true!\n";
}