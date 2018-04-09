#ifndef _DATA_IO_
#define _DATA_IO_

#include "data_struct.h"

void readUserList(const string PATH, vUser &UserList);
void readClassList(const string PATH, vClass &ClassList);
void readCourseList(const string PATH, vCourse &CourseList);
void readCourseScheduleList(const string PATH, vCourseSchedule &CourseScheduleList);
void readPersenseList(const string PATH, vPersense &PersenseList);
void readScoreList(const string PATH, vScore &ScoreList);

void writeUserList(char PATH[], vUser &User);
void writeClassList(char PATH[], vUser &UserList);
void writeCourseList(char PATH[], vCourse &CourseList);
void writePersenseList(char PATH[], vPersense &PersenseList);
void writeCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList);
void writeScoreList(char PATH[], vScore &ScoreList);

#endif

void readUserList(const string PATH, vUser &UserList);
void readClassList(const string PATH, vClass &ClassList);
void readCourseList(const string PATH, vCourse &CourseList);
void readCourseScheduleList(const string PATH, vCourseSchedule &CourseScheduleList);
void searchAndViewAttendaceList(vCourse &CourseList, vPersense &PersenseList);
void readScoreList(const string PATH, vScore &ScoreList);