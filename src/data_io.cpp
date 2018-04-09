#include "data_io.h"

string modifyString(string &s)
{
  string tmp = "";
  while (s[0] != ',')
  {
    tmp = tmp + s[0];
    s.erase(0, 1);
  }
  s.erase(0, 1); // erase the remaining comma.
  return tmp;
}

int toNumber(string s)
{
  int res = 0;
  for (int i = 0; i < s.length(); ++i)
    res = res * 10 + s[i] - '0';
  return res;
}

void readUserList(const char PATH[], vUser &UserList)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !";
    return;
  }
  string s;
  while (getline(fin, s))
  {
    s = s + ',';
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
    UserList.push_back(tmp);
  }
  fin.close();
}

void readClassList(char PATH[], vClass &ClassList)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !";
    return;
  }
  string s;
  while (getline(fin, s))
  {
    s = s + ',';
    Class tmp;
    tmp.classCode = modifyString(s);
    ClassList.push_back(tmp);
  }
  fin.close();
}

void readPresenseList(char PATH[], vPersense &PersenseList)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !";
    return;
  }
  string s;
  while (getline(fin, s))
  {
    s = s + ',';
    Persense tmp;
    tmp.courseCode = modifyString(s);
    tmp.year = modifyString(s);
    tmp.semester = toNumber(modifyString(s));
    tmp.studentID = modifyString(s);
    tmp.week = toNumber(modifyString(s));
    PersenseList.push_back(tmp);
  }
  fin.close();
}

void readScoreList(char PATH[], vScore &ScoreList)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !";
    return;
  }
  string s;
  while (getline(fin, s))
  {
    s = s + ',';
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
    ScoreList.push_back(tmp);
  }
  fin.close();
}

void readCourseList(char PATH[], vCourse &CourseList)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !";
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
    CourseList.push_back(tmp);
  }
  fin.close();
}

void readCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList)
{
  ifstream fin;
  fin.open(PATH);
  if (!fin.is_open())
  {
    cout << "Error ! Can't read the file !";
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
    CourseScheduleList.push_back(tmpSchedule);
  }
  fin.close();
}

void writeClassList(char PATH[], vClass &ClassList)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < ClassList.size(); ++i)
  {
    cout << ClassList[i].classCode << '/n';
  }
  fout.close();
}

void writePresenseList(char PATH[], vPersense &PersenseList)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < PersenseList.size(); ++i)
  {
    cout << PersenseList[i].courseCode << ',';
    cout << PersenseList[i].year << ',';
    cout << PersenseList[i].semester << ',';
    cout << PersenseList[i].studentID << ',';
    cout << PersenseList[i].week << '\n';
  }
  fout.close();
}

void writeScoreList(char PATH[], vScore &ScoreList)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < ScoreList.size(); ++i)
  {
    cout << ScoreList[i].courseCode << ',';
    cout << ScoreList[i].year << ',';
    cout << ScoreList[i].semester << ',';
    cout << ScoreList[i].studentID << ',';
    cout << ScoreList[i].midtermScore << ',';
    cout << ScoreList[i].labScore << ',';
    cout << ScoreList[i].finalScore << ',';
    cout << ScoreList[i].totalScore << '\n';
  }
  fout.close();
}

void writeCourseList(char PATH[], vCourse &CourseList)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < CourseList.size(); ++i)
  {
    cout << CourseList[i].courseCode << ',';
    cout << CourseList[i].year << ',';
    cout << CourseList[i].semester << ',';
    cout << CourseList[i].courseName << ',';
    cout << CourseList[i].lecturerUserName << ',';
    cout << CourseList[i].classCode << '\n';
  }
  fout.close();
}

void writeCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList)
{
  ofstream fout;
  fout.open(PATH);
  if (!fout.is_open())
  {
    cout << "Erorr ! Can't write to the file !";
    return;
  }
  for (int i = 0; i < CourseScheduleList.size(); ++i)
  {
    cout << CourseScheduleList[i].courseCode << ',';
    cout << CourseScheduleList[i].startAt << ',';
    cout << CourseScheduleList[i].endAt << ',';
    cout << CourseScheduleList[i].from << ',';
    cout << CourseScheduleList[i].to << ',';
    cout << CourseScheduleList[i].dayOfWeek << '\n';
  }
  fout.close();
}
