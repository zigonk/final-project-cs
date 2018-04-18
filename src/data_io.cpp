#include "data_io.h"

string modifyString(string &s)
{
  string tmp = "";
  while (s.length() != 0 && s[0] != ',')
  {
    if (s[0] == '\r') break;
    tmp = tmp + s[0];
    s.erase(0, 1);
  }
  if (s.length() != 0) s.erase(0, 1); // erase the remaining comma.
  return tmp;
}

int toNumber(string s)
{
  int res = 0;
  for (int i = 0; i < s.length(); ++i)
    res = res * 10 + s[i] - '0';
  return res;
}

void readUserList(const char *PATH, vUser &UL)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !" << endl;
    return;
  }
  string s;
  while (getline(fin, s))
  {
    User tmp;
    tmp.username = modifyString(s);
    tmp.fullname = modifyString(s);
    tmp.email = modifyString(s);
    tmp.mobilePhone = modifyString(s);
    string uType = modifyString(s);
    if (uType == "0")
      tmp.uType = ACADEMIC_STAFF;
    else if (uType == "1")
      tmp.uType = LECTURER;
    else
      tmp.uType = STUDENT;
    tmp.password = modifyString(s);
    tmp.classCode = modifyString(s);
    UL.UserList.push_back(tmp);
  }
  fin.close();
}

void readClassList(char PATH[], vClass &CL)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !" << endl;
    return;
  }
  string s;
  while (getline(fin, s))
  {
    Class tmp;
    tmp.classCode = modifyString(s);
    CL.ClassList.push_back(tmp);
  }
  fin.close();
}

void readPresenseList(const char *PATH, vPresense &PL)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !" << endl;
    return;
  }
  string s;
  while (getline(fin, s))
  {
    Presense tmp;
    tmp.courseCode = modifyString(s);
    tmp.year = modifyString(s);
    tmp.semester = toNumber(modifyString(s));
    tmp.studentID = modifyString(s);
    tmp.week = toNumber(modifyString(s));
    PL.PresenseList.push_back(tmp);
  }
  fin.close();
}

void readScoreList(const char *PATH, vScore &SL)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !" << endl;
    return;
  }
  string s;
  while (getline(fin, s))
  {
    Score tmp;
    tmp.courseCode = modifyString(s);
    tmp.year = modifyString(s);
    tmp.semester = toNumber(modifyString(s));
    tmp.studentID = modifyString(s);
    tmp.midtermScore = toNumber(modifyString(s));
    tmp.labScore = toNumber(modifyString(s));
    tmp.finalScore = toNumber(modifyString(s));
    tmp.bonusScore = toNumber(modifyString(s));
    tmp.totalScore = toNumber(modifyString(s));
    SL.ScoreList.push_back(tmp);
  }
  fin.close();
}

void readCourseList(const char *PATH, vCourse &CL)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !" << endl;
    return;
  }
  string s;
  while (getline(fin, s))
  {
    s = s + ',';
    Course tmp;
    tmp.courseCode = modifyString(s);
    tmp.year = modifyString(s);
    tmp.semester = toNumber(modifyString(s));
    tmp.courseName = modifyString(s);
    tmp.lecturerUserName = modifyString(s);
    tmp.classCode = modifyString(s);
    CL.CourseList.push_back(tmp);
  }
  fin.close();
}

void readCourseScheduleList(const char *PATH, vCourseSchedule &CSL)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !" << endl;
    return;
  }
  string s;
  while (getline(fin, s))
  {
    s = s + ',';
    CourseSchedule tmpSchedule;
    tmpSchedule.courseCode = modifyString(s);
    tmpSchedule.startAt = modifyString(s);
    tmpSchedule.endAt = modifyString(s);
    tmpSchedule.from = modifyString(s);
    tmpSchedule.to = modifyString(s);
    tmpSchedule.dayOfWeek = toNumber(modifyString(s));
    CSL.CourseScheduleList.push_back(tmpSchedule);
  }
  fin.close();
}

void writeUserList(const char *PATH, vUser &UL)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !" << endl;
    return;
  }
  for (int i = 0; i < UL.UserList.size(); ++i)
  {
    fout << UL.UserList[i].username << ',';
    fout << UL.UserList[i].fullname << ',';
    fout << UL.UserList[i].email << ',';
    fout << UL.UserList[i].mobilePhone << ',';
    fout << UL.UserList[i].uType << ',';
    fout << UL.UserList[i].password << ',';
    fout << UL.UserList[i].classCode << '\n';
  }
  fout.close();
}

void writeClassList(char PATH[], vClass &CL)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < CL.ClassList.size(); ++i)
  {
    fout << CL.ClassList[i].classCode << '\n';
  }
  fout.close();
}

void writePresenseList(const char *PATH, vPresense &PL)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < PL.PresenseList.size(); ++i)
  {
    fout << PL.PresenseList[i].courseCode << ',';
    fout << PL.PresenseList[i].year << ',';
    fout << PL.PresenseList[i].semester << ',';
    fout << PL.PresenseList[i].studentID << ',';
    fout << PL.PresenseList[i].week << '\n';
  }
  fout.close();
}

void writeScoreList(const char *PATH, vScore &SL)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < SL.ScoreList.size(); ++i)
  {
    fout << SL.ScoreList[i].courseCode << ',';
    fout << SL.ScoreList[i].year << ',';
    fout << SL.ScoreList[i].semester << ',';
    fout << SL.ScoreList[i].studentID << ',';
    fout << SL.ScoreList[i].midtermScore << ',';
    fout << SL.ScoreList[i].labScore << ',';
    fout << SL.ScoreList[i].finalScore << ',';
    fout << SL.ScoreList[i].bonusScore << ',';
    fout << SL.ScoreList[i].totalScore << '\n';
  }
  fout.close();
}

void writeCourseList(char PATH[], vCourse &CL)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < CL.CourseList.size(); ++i)
  {
    fout << CL.CourseList[i].courseCode << ',';
    fout << CL.CourseList[i].year << ',';
    fout << CL.CourseList[i].semester << ',';
    fout << CL.CourseList[i].courseName << ',';
    fout << CL.CourseList[i].lecturerUserName << ',';
    fout << CL.CourseList[i].classCode << '\n';
  }
  fout.close();
}

void writeCourseScheduleList(char PATH[], vCourseSchedule &CSL)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < CSL.CourseScheduleList.size(); ++i)
  {
    fout << CSL.CourseScheduleList[i].courseCode << ',';
    fout << CSL.CourseScheduleList[i].startAt << ',';
    fout << CSL.CourseScheduleList[i].endAt << ',';
    fout << CSL.CourseScheduleList[i].from << ',';
    fout << CSL.CourseScheduleList[i].to << ',';
    fout << CSL.CourseScheduleList[i].dayOfWeek << '\n';
  }
  fout.close();
}
