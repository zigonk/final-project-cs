#ifndef _DATA_STRUCT_
#define _DATA_STRUCT_

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

enum UserType
{
	STUDENT,
	ACADEMIC_STAFF,
	LECTURER,
};
struct User
{
	string username,
			fullname,
			email,
			mobilePhone,
			password,
			classCode;
	UserType uType;
};

struct CourseSchedule
{
	string courseCode,
			startAt, // hh:mm
			endAt,			// hh:mm
			from,				// dd/mm
			to;					// dd/mm
	int dayOfWeek; 	// [0, 1, ..., 6] = [Mon, Tue, ..., Sunday];
};

struct Course
{
	string courseCode,
			year,
			courseName,
			lecturerUserName,
			classCode;
	int semester;
};

struct Persense
{
	string courseCode,
			year,
			studentID;
	int semester,
			week;
};

struct Score
{
	string courseCode,
			year,
			studentID;
	int semester,
			midtermScore,
			labScore,
			finalScore,
			bonusScore,
			totalScore;
};

struct Class
{
	string classCode;
};

struct vUser {
	vector <User> UserList;
};

struct vClass {
	vector <Class> ClassList;
};

struct vCourseSchedule {
	vector<CourseSchedule> CourseScheduleList;
};

struct vCourse {
	vector<Course> CourseList;
};

struct vPersense {
	vector<Persense> PersenseList;
};

struct vScore {
	vector<Score> ScoreList;
};

#endif
