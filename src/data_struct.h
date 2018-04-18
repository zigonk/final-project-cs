#ifndef _DATA_STRUCT_
#define _DATA_STRUCT_

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <time.h>
#include <sstream>

using namespace std;

#define PRESENCE_PATH "../database/data_presence.csv"
#define SCORE_PATH "../database/data_score.csv"
#define COURSE_PATH "../database/data_course.csv"
#define USER_PATH "../database/data_user.csv"
#define COURSE_SCHEDULE_PATH "../database/data_course_schedule.csv"

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
			startAt,    // hh:mm
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

struct Presense
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

struct vPresense {
	vector<Presense> PresenseList;
};

struct vScore {
	vector<Score> ScoreList;
};

#endif
