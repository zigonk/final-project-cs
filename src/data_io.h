#ifndef _DATA_IO_
#define _DATA_IO_

#include "data_struct.h"

void readUserList(const char *PATH, vUser &User);
void readClassList(const char *PATH, vClass &ClassList);
void readCourseList(const char *PATH, vCourse &CourseList);
void readCourseScheduleList(const char *PATH, vCourseSchedule &CourseScheduleList);
void readPresenseList(const char *PATH, vPresense &PresenseList);
void searchAndViewAttendaceList(vCourse &CourseList, vPresense &PersenseList);
void readScoreList(const char *PATH, vScore &ScoreList);
string modifyString(string &s);
int toNumber(string s);
void writeUserList(const char *PATH, vUser &User);
void writeClassList(const char *PATH, vClass &CLassList);
void writeCourseList(const char *PATH, vCourse &CourseList);
void writePresenseList(const char *PATH, vPresense &PresenseList);
void writeCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList);
void writeScoreList(const char *PATH, vScore &ScoreList);

#endif
