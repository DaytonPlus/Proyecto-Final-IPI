string ShowMessage_Data[2],
ShowMessage_ParamData[4],
ShowMessage_Error[4];

void ShowMessage_Load() {
 if (Config_UseColors) {
  ShowMessage_Data[0] = Colors_Cyan("<> ") + Colors_BGreen(Lang_Get("more_info") + ": <command> -h | help\n | <command> <param> -h | help");
  ShowMessage_Data[1] = Colors_Cyan("<> ") + Colors_BGreen("add student|students|evaluation|evaluations\n " + Lang_Get("use_add") + "!");

  ShowMessage_ParamData[0] = Colors_Cyan("<> ") + Colors_BGreen("student | -s  " + Lang_Get("help-s"));
  ShowMessage_ParamData[1] = Colors_Cyan("<> ") + Colors_BGreen("evaluation | -e  " + Lang_Get("help-e"));
  ShowMessage_ParamData[2] = Colors_Cyan("<> ") + Colors_BGreen("students | -ss  " + Lang_Get("help-ss"));
  ShowMessage_ParamData[3] = Colors_Cyan("<> ") + Colors_BGreen("evaluations | -es  " + Lang_Get("help-es"));

  ShowMessage_Error[0] = Colors_Red("@Error: ") + Colors_BRed(Lang_Get("no-help"));
  ShowMessage_Error[1] = Colors_Red("@Error: ") + Colors_BRed(Lang_Get("inv-param"));
  ShowMessage_Error[2] = Colors_Red("@Error: ") + Colors_BRed(Lang_Get("cmd"));
  ShowMessage_Error[3] = Colors_BRed(Lang_Get("no-found"));
 }
 else {
  ShowMessage_Data[0] = "<> " + Lang_Get("more_info") + ": <command> -h | help\n | <command> <param> -h | help";
  ShowMessage_Data[0] = "<> add student|students|evaluation|evaluations\n " + Lang_Get("use_add") + "!";

  ShowMessage_ParamData[0] = "<> student | -s  " + Lang_Get("help-s");
  ShowMessage_ParamData[1] = "<> evaluation | -e  " + Lang_Get("help-e");
  ShowMessage_ParamData[2] = "<> students | -ss  " + Lang_Get("help-ss");
  ShowMessage_ParamData[3] = "<> evaluations | -es  " + Lang_Get("help-es");

  ShowMessage_Error[0] = "@Error: " + Lang_Get("no-help");
  ShowMessage_Error[1] = "@Error: " + Lang_Get("inv-param");
  ShowMessage_Error[2] = "@Error: " + Lang_Get("cmd");
  ShowMessage_Error[3] = Lang_Get("no-found");
 }
}

void ShowMessage_Log(string text) {
 cout << text << endl;
}

void ShowMessage_Text(string cmd, int mode = 0, int prm = 2, string msg = "") {
 if (cmd == "about") About_Draw();
 else if(cmd == "help") {
  ShowMessage_Log(ShowMessage_Data[1]);
  ShowMessage_Log(".................");
 }
 else if(cmd == "add") {
  if (mode == 3) ShowMessage_Log(ShowMessage_Data[1]);
  else if (mode == 2) ShowMessage_Log(ShowMessage_ParamData[prm]);
  else if (mode == 1) {
   ShowMessage_Log(ShowMessage_Data[1]);
   ShowMessage_Log(ShowMessage_ParamData[0]);
   ShowMessage_Log(ShowMessage_ParamData[1]);
   ShowMessage_Log(ShowMessage_ParamData[2]);
   ShowMessage_Log(ShowMessage_ParamData[3]);
  }
  else {
   ShowMessage_Log(ShowMessage_Data[1]);
   ShowMessage_Log(ShowMessage_Data[0]);
  }
 }
 else if(cmd == "error") {
  if (mode == 0) ShowMessage_Log(ShowMessage_Error[2] + " '" + msg + "' " + ShowMessage_Error[3]);
  else if (mode == 1) ShowMessage_Log(ShowMessage_Error[1] + " '" + msg + "'");
  else ShowMessage_Log("@mode:out-Range");
 }
 else ShowMessage_Log(ShowMessage_Error[0]);
}