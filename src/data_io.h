#ifndef _DATA_IO_
#define _DATA_IO_

#include "data_struct.h"

void readUserList(const char *PATH, vUser &User);
void readClassList(char PATH[], vClass &ClassList);
void readCourseList(const char *PATH, vCourse &CourseList);
void readCourseScheduleList(const char *PATH, vCourseSchedule &CourseScheduleList);
void readPresenseList(const char *PATH, vPresense &PresenseList);
void readScoreList(const char *PATH, vScore &ScoreList);

void writeUserList(const char *PATH, vUser &User);
void writeClassList(char PATH[], vUser &UserList);
void writeCourseList(char PATH[], vCourse &CourseList);
void writePresenseList(const char *PATH, vPresense &PresenseList);
void writeCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList);
void writeScoreList(const char *PATH, vScore &ScoreList);

#endif

void readUserList(const string PATH, vUser &UserList);
void readClassList(const string PATH, vClass &ClassList);
void readCourseList(const string PATH, vCourse &CourseList);
void readCourseScheduleList(const string PATH, vCourseSchedule &CourseScheduleList);
void searchAndViewAttendaceList(vCourse &CourseList, vPersense &PersenseList);
void readScoreList(const string PATH, vScore &ScoreList);