int Storage_MaxStudents = 2000;
int Storage_MaxEvaluations = 800;
int Storage_LastStudent = 0;
int Storage_LastEvaluation[2000] = {};
int Storage_Evaluations[2000][800] = {};
string Storage_Students[2000] = {};

int Storage_FindStudent(string name) {
 for(int i = 0;i<Storage_LastStudent; i++) if(Storage_Students[i] == name) return i;
 return -1;
}

bool Storage_ExistsStudent(string name) {
 return Storage_FindStudent(name) > -1;
}

bool Storage_ExistsStudentId(int id) {
 return Storage_LastStudent < id;
}

int Storage_AddStudent(string name) {
 if(!Storage_ExistsStudent(name) && Storage_LastStudent < Storage_MaxStudents) {
  int id = Storage_LastStudent;
  Storage_Students[id] = name;
  Storage_LastEvaluation[id] = 0;
  Storage_LastStudent++;
  return id;
 }
 return -1;
}

void Storage_AddStudents(string* names) {
 int sz = sizeof(names)/sizeof(names[0]);
 for (int i = 0; i < sz; i++) Storage_AddStudent(names[i]);
}

int Storage_AddEvaluation(int id, int note) {
 if(Storage_ExistsStudentId(id)) {
  if(Storage_MaxEvaluations > Storage_LastEvaluation[id]) {
   int eid = Storage_LastEvaluation[id];
   Storage_Evaluations[id][eid] = note;
   Storage_LastEvaluation[id]++;
   return eid;
  } return -1;
 }
 return -1;
}

void Storage_AddEvaluations(int id, int* notes) {
 int sz = sizeof(notes)/sizeof(notes[0]);
 for (int i = 0; i < sz; i++) Storage_AddEvaluation(id, notes[i]);
}

void Storage_Save() {}