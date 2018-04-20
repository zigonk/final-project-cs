#ifndef _ACADEMIC_ROLES_
#define _ACADEMIC_ROLES_

#include "data_io.h"

void importStudentOfClass();  

void importCourses();
void removeACourse();

void addANewStudent();
void editAnExistingStudent();
void removeAStudent();

void changeStudentFromClassAToClassB();
void addANewEmptyClass();
void viewListOfClass();
void viewListOfStudentInAClass();
void addANewCourse();
void editAnCourse();
void removeAnCourse();

void viewListOfACourse();

void addACourseSchedule();
void editACourseSchedule();


void removeACourseSchedule();

void viewListOfCourseSchedule();
void exportAttendenceList();

void searchAndViewAttendaceList();
void searchAndViewScoreboard();
void exportScoreBoard();
#endif
