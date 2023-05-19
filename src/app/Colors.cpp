string Colors_Data[9][4] = {
 {"30", "", "40", "100"},
 {"31", "91", "41", "101"},
 {"32", "92", "42", "102"},
 {"33", "93", "43", "103"},
 {"34", "94", "44", "104"},
 {"35", "95", "45", "105"},
 {"36", "96", "46", "106"},
 {"37", "97", "47", "107"},
 {"90", "", "", ""}
};

string Colors_Names[] = {
 "black",
 "red",
 "green",
 "yellow",
 "blue",
 "magneta",
 "cyan",
 "white",
 "gray"
};

int Colors_Find(string name) {
 for(int i = 0; i < 9; i++) if(Colors_Names[i] == name) return i;
 return -1;
}

bool Colors_Exists(string name) {
 return Colors_Find(name) >= 0;
}

string Colors_Text(string name, int type, string text) {
 if(type < 1 && type > 4) return "";
 int sel = type-1;
 int a = Colors_Find(name);
 if(a >= 0) {
  string col = Colors_Data[a][sel];
  if(col != "") return ("\u001B[" + col + "m") + text + (sel < 2 ? "\u001B[39m": "\u001B[49m");
 }
 return text;
}

string Colors_Black(string text) {
	return "\u001B[30m" + text + "\u001B[39m";
}
string Colors_Red(string text) {
	return "\u001B[31m" + text + "\u001B[39m";
}
string Colors_Green(string text) {
	return "\u001B[32m" + text + "\u001B[39m";
}
string Colors_Yellow(string text) {
	return "\u001B[33m" + text + "\u001B[39m";
}
string Colors_Blue(string text) {
	return "\u001B[34m" + text + "\u001B[39m";
}
string Colors_Magneta(string text) {
	return "\u001B[35m" + text + "\u001B[39m";
}
string Colors_Cyan(string text) {
	return "\u001B[36m" + text + "\u001B[39m";
}
string Colors_White(string text) {
	return "\u001B[37m" + text + "\u001B[39m";
}
string Colors_Gray(string text) {
	return "\u001B[90m" + text + "\u001B[39m";
}
string Colors_BRed(string text) {
	return "\u001B[91m" + text + "\u001B[39m";
}
string Colors_BGreen(string text) {
	return "\u001B[92m" + text + "\u001B[39m";
}
string Colors_BYellow(string text) {
	return "\u001B[93m" + text + "\u001B[39m";
}
string Colors_BBlue(string text) {
	return "\u001B[94m" + text + "\u001B[39m";
}
string Colors_BMagneta(string text) {
	return "\u001B[95m" + text + "\u001B[39m";
}
string Colors_BCyan(string text) {
	return "\u001B[96m" + text + "\u001B[39m";
}
string Colors_BWhite(string text) {
	return "\u001B[97m" + text + "\u001B[39m";
}
string Colors_BGBlack(string text) {
	return "\u001B[40m" + text + "\u001B[49m";
}
string Colors_BGRed(string text) {
	return "\u001B[41m" + text + "\u001B[49m";
}
string Colors_BGGreen(string text) {
	return "\u001B[42m" + text + "\u001B[49m";
}
string Colors_BGYellow(string text) {
	return "\u001B[43m" + text + "\u001B[49m";
}
string Colors_BGBlue(string text) {
	return "\u001B[44m" + text + "\u001B[49m";
}
string Colors_BGMagneta(string text) {
	return "\u001B[45m" + text + "\u001B[49m";
}
string Colors_BGCyan(string text) {
	return "\u001B[46m" + text + "\u001B[49m";
}
string Colors_BGWhite(string text) {
	return "\u001B[47m" + text + "\u001B[49m";
}
string Colors_BBGBlack(string text) {
	return "\u001B[100m" + text + "\u001B[49m";
}
string Colors_BBGRed(string text) {
	return "\u001B[101m" + text + "\u001B[49m";
}
string Colors_BBGGreen(string text) {
	return "\u001B[102m" + text + "\u001B[49m";
}
string Colors_BBGYellow(string text) {
	return "\u001B[103m" + text + "\u001B[49m";
}
string Colors_BBGBlue(string text) {
	return "\u001B[104m" + text + "\u001B[49m";
}
string Colors_BBGMagneta(string text) {
	return "\u001B[105m" + text + "\u001B[49m";
}
string Colors_BBGCyan(string text) {
	return "\u001B[106m" + text + "\u001B[49m";
}
string Colors_BBGWhite(string text) {
	return "\u001B[107m" + text + "\u001B[49m";
}
