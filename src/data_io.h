#ifndef _DATA_IO_
#define _DATA_IO_

#include "data_struct.h"

void readUserList(const string PATH, vUser &UserList);
void readClassList(const string PATH, vClass &ClassList);
void readCourseList(const string PATH, vCourse &CourseList);
void readCourseScheduleList(const string PATH, vCourseSchedule &CourseScheduleList);
void searchAndViewAttendaceList(vCourse &CourseList, vPersense &PersenseList);
void readScoreList(const string PATH, vScore &ScoreList);

void writeClassList(const string PATH, vUser &UserList);
void writeCourseList(const string PATH, vCourse &CourseList);
void writePersenseList(const string PATH, vPersense &PersenseList);
void writeCourseScheduleList(const string PATH, vCourseSchedule &CourseScheduleList);
void writeScoreList(const string PATH, vScore &ScoreList);

#endif
