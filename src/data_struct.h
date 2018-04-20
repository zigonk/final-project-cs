#ifndef _DATA_STRUCTURE_
#define _DATA_STRUCTURE_

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <ctime>
#include <sstream>

using namespace std;

#define CLASS_PATH "../database/data_class.csv"
#define PRESENCE_PATH "../database/data_presence.csv"
#define SCORE_PATH "../database/data_score.csv"
#define COURSE_PATH "../database/data_course.csv"
#define USER_PATH "../database/data_user.csv"
#define COURSE_SCHEDULE_PATH "../database/data_course_schedule.csv"
const string week[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

enum UserType
{
	ACADEMIC_STAFF,
	LECTURER,
	STUDENT,
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
	int dayOfWeek; 	// [0, 1, ..., 6] = [Sun, Mon, Tue, ..., Sat];
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
