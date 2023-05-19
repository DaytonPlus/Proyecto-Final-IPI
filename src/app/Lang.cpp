string Lang_Data[3][12] = {
 {
  "hworld",
  "welcome",
  "more_info",
  "use_add",
  "help-s",
  "help-e",
  "help-ss",
  "help-es",
  "no-help",
  "inv-param",
  "cmd",
  "no-found",
 },
 {
  "Hello World",
  "Welcome",
  "For more info write",
  "use: For add a students and evaluations to list",
  "Select the student method and continue to a operation of the command called, you can use directly the ID of the student",
  "Select the evaluation method and continue to a operation of the command called, you can use directly the ID of the evaluation",
  "Multiple select of the method student and continue to a operation of the command called",
  "Multiple select of the method evaluation and continue to a operation of the command called",
  "The Commamd|Parameter Not have information of help",
  "Inalid Argument",
  "Command",
  "not found"
 },
 {
  "Hola Munda",
  "Bienvenido",
  "Para mas informacion escribe",
  "uso: Para agregar un estudiante o evaluacion a la lista",
  "Selecciona el metodo de estudiante y continua a una operacion del comando llamado, tu puedes usar directamente el ID del estudiante",
  "Selecciona el metodo de evalucion y continua a una operacion del comando llamado, tu puedes usar directamente el ID de la evaluacion",
  "Seleccion multiple del metodo de estudiante y continua a una operacion del comando llamado",
  "Seleccion multiple del metodo de evaluacion y continua a una operacion del comando llamado",
  "El Comando|Parametro no tiene informacion de ayuda",
  "Argumento Invalido",
  "Comando",
  "no encontrado",
 }
};

int Lang_Activated = (Config_DefaultLang > 0 && Config_DefaultLang < 3) ? Config_DefaultLang: 1;

void Lang_Load() {}

int Lang_Find(string name) {
 for(int i = 0; i < 12; i++) if(name == Lang_Data[0][i]) return i;
 return -1;
}

bool Lang_Exists(string name) {
 return Lang_Find(name) >= 0;
}

string Lang_Get(string name) {
 int a = Lang_Find(name);
 if (a >= 0) return Lang_Data[Lang_Activated][a];
 return "null";
}

void Lang_Set(string lang) {
 int a = (lang == "ES") ? 2: (lang == "EN") ? 1: 0;
 if (a > 0) {
  Lang_Activated = a;
  Lang_Load();
 }
}