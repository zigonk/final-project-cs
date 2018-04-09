#ifndef _DATA_IO_
#define _DATA_IO_

#include "data_struct.h"

void readUserList(char PATH[], vUser &User);
void readClassList(char PATH[], vClass &ClassList);
void readCourseList(char PATH[], vCourse &CourseList);
void readCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList);
void readPersenseList(char PATH[], vPersense &PersenseList);
void readScoreList(char PATH[], vScore &ScoreList);

void writeUserList(char PATH[], vUser &User);
void writeClassList(char PATH[], vUser &UserList);
void writeCourseList(char PATH[], vCourse &CourseList);
void writePersenseList(char PATH[], vPersense &PersenseList);
void writeCourseScheduleList(char PATH[], vCourseSchedule &CourseScheduleList);
void writeScoreList(char PATH[], vScore &ScoreList);

#endif