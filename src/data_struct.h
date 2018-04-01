#ifndef _DATA_STRUCT_
#define _DATA_STRUCT_

#include <iostream>
#include<string>
#include<vector>

using namespace std;

enum TypeUser
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
	TypeUser Type;
};

struct Course
{
  string courseCode,
      year,
      courseName,
      lecturerUserName,
      startAt,
      endAt,
      from,
      to,
      dateOfWeek;
  int semester;
};

struct Persense {
  string courseCode,
      year,
      studentID;
  int semester,
      week;
};

struct Score {
  string courseCode,
      year,
      studentID;
  int semester,
      midtermScore,
      labScore,
      finalScore;
};

typedef vector<User> vUser;
typedef vector<Course> vCourse;
typedef vector<Persense> vPersense;
typedef vector<Score> vScore;

#endif