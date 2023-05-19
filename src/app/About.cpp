const string About_Normal[] = {
 "- ------------------------------------------------------ -",
 " - --------------------- < v1.39 > -------------------- -",
 " - -------------------- < Authors > ------------------- -",
 " - -------------- David Velazquez Morales ------------- -",
 " - --------- Manuel Alejandro Concepcion Reyes -------- -",
 "- ------------------------------------------------------ -",
};

const string About_Colored[] = {
 "\u001B[36m- ------------------------------------------------------ -\u001B[39m",
 "\u001B[36m - --------------------- \u001B[39m\u001B[33m<\u001B[39m\u001B[32m v1.39 \u001B[39m\u001B[33m>\u001B[39m\u001B[36m -------------------- -\u001B[39m",
 "\u001B[36m - -------------------- \u001B[39m\u001B[33m<\u001B[39m\u001B[32m Authors \u001B[39m\u001B[33m>\u001B[39m\u001B[36m ------------------- -\u001B[39m",
 "\u001B[36m - -------------- \u001B[39m\u001B[35mDavid Velazquez Morales\u001B[39m\u001B[36m ------------- -\u001B[39m",
 "\u001B[36m - --------- \u001B[39m\u001B[35mManuel Alejandro Concepcion Reyes\u001B[39m\u001B[36m -------- -\u001B[39m",
 "\u001B[36m- ------------------------------------------------------ -\u001B[39m",
};

void About_Draw() {
 int a;
 if (Config_UseColors) {
  a = sizeof(About_Colored)/sizeof(About_Colored[0]);
  for(int i = 0; i < a; i++) cout << About_Colored[i] << endl;
 }
 else {
  a = sizeof(About_Normal)/sizeof(About_Normal[0]);
  for(int i = 0; i < a; i++) cout << About_Normal[i] << endl;
 }
}