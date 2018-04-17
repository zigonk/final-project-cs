#ifndef _ACADEMIC_ROLES_
#define _ACADEMIC_ROLES_

#include "data_struct.h"

#include "academic_roles.h"

void addANewStudent(vUser &UserList);
void editAnExistingStudent(vUser &UserList);
void removeAStudent(vUser &UserList);

void changeStudentsFromClassAToClassB(vUser &UserList);
void addANewEmptyClass(vClass &ClassList);
void viewListOfClass(vClass &ClassList);
void viewListOfStudentInAClass(vUser &UserList, vClass &ClassList);
void addANewCourse(vCourse &CourseList);
void editAnCourse(vCourse &CourseList);
void removeAnCourse(vCourse &CourseList);

void viewListOFACourse(vCourse &CourseList);

void addACourseSchedule(vCourseSchedule &CourseScheduleList);
void editACourseSchedule(vCourseSchedule& CourseScheduleList);


void removeACourseSchedule(vCourseSchedule &CourseScheduleList);

void viewListOfCourseSchedule(vCourseSchedule &CourseScheduleList);

void searchAndViewAttendaceList(vCourse &CourseList);
#endif
