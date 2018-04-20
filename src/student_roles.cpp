#include "student_roles.h"

string getTime(int hh, int mm) {
	stringstream ss;
	string res;

	ss << char(hh / 10 + '0') << char(hh % 10 + '0') << ":" << char(mm / 10 + '0') << char(mm % 10 + '0');
	ss >> res;

	return res;
}

string getDate(int dd, int mm) {
	stringstream ss;
	string res;

	ss << char(mm / 10 + '0') << char(mm % 10 + '0') << "/" << char(dd / 10 + '0') << char(dd % 10 + '0');
	ss >> res;

	return res;
}


int cmpTime(const string &t1, const string &t2) {
	if (t1 > t2)
		return 1;
	if (t1 < t2)
		return -1;
	return 0;
}

int cmpDay(const string &d1, const string &d2) {
	if (d1 > d2)
		return 1;
	if (d1 < d2)
		return -1;
	return 0;
}

void checkIn(User &loginUser) {
	vPresense PL;
	vCourse CL;
	vCourseSchedule CSL;
	readPresenseList(PRESENCE_PATH, PL);
	readCourseList(COURSE_PATH, CL);
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);

	Presense newCheckIn;
	newCheckIn.studentID = loginUser.username;
	time_t t = time(nullptr);
	struct tm *tm_struct = localtime(&t);
	int hour = tm_struct->tm_hour;
	int minute = tm_struct->tm_min;
	string myTime = getTime(hour, minute);

	int wday = tm_struct->tm_wday;
	int day = tm_struct->tm_mday;
	int month = tm_struct->tm_mon;
	string myDay = getDate(day, month);

	for (auto &i : CL.CourseList) {
		if (i.classCode == loginUser.classCode) {
			for (auto &j : CSL.CourseScheduleList) {
				if (j.courseCode != i.courseCode) continue;
				if (wday == j.dayOfWeek) {
					if (cmpTime(myTime, j.startAt) >= 0 &&
					    cmpTime(myTime, j.endAt) <= 0) {
						if (cmpDay(myDay, j.to) <= 0 &&
						    cmpDay(myDay, j.from) >= 0) {
							int week;
							cout << "Please input your week:";
							cin >> week;
							newCheckIn.semester = i.semester;
							newCheckIn.courseCode = i.courseCode;
							newCheckIn.week = week;
							newCheckIn.year = i.year;
							for (auto &k : PL.PresenseList) {
								if (k.year == newCheckIn.year &&
								    k.week == newCheckIn.week &&
								    k.courseCode == newCheckIn.courseCode &&
								    k.semester == newCheckIn.semester &&
								    k.studentID == newCheckIn.studentID) {
									return;
								}
							}
							PL.PresenseList.push_back(newCheckIn);
							writePresenseList(PRESENCE_PATH, PL);
						}
					}
				}
			}
		}
	}
}

void viewCheckInResult(User &loginUser) {
	vPresense PL;
	readPresenseList(PRESENCE_PATH, PL);
	for (auto &i : PL.PresenseList) {
		if (i.studentID == loginUser.username) {
			cout << "Course code: " << i.courseCode << '\n';
			cout << "Year: " << i.year << '\n';
			cout << "Semester: " << i.semester << '\n';
			cout << "Week: " << i.week << '\n' << '\n';
		}
	}
}

void viewScoreOfACourse(User &loginUser) {
	vScore SL;
	readScoreList(SCORE_PATH, SL);
	string courseCode;
	cout << "Please input a course you want to see score:";
	cin >> courseCode;
	for (auto &i : SL.ScoreList) {
		if (i.studentID == loginUser.username && i.courseCode == courseCode) {
			Score myScore = i;
			cout << "Midterm score: " << myScore.midtermScore << '\n';
			cout << "Final score: " << myScore.finalScore << '\n';
			cout << "Lab score: " << myScore.labScore << '\n';
			cout << "Bonus score: " << myScore.bonusScore << '\n';
			cout << "Total score: " << myScore.totalScore << '\n' << '\n';
		}
	}
}

void viewSchedule(User &loginUser) {
	vCourseSchedule CSL;
	vCourse CL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	readCourseList(COURSE_PATH, CL);

	time_t t = time(nullptr);
	struct tm *tm_struct = localtime(&t);
	int day = tm_struct->tm_mday;
	int month = tm_struct->tm_mon;
	string myDay = getDate(day, month);

	for (auto &i : CL.CourseList) {
		if (i.classCode == loginUser.classCode) {
			for (auto &j : CSL.CourseScheduleList) {
				if (cmpDay(myDay, j.from) >= 0 || cmpDay(myDay, j.to) <= 0)
					if (j.courseCode == i.courseCode) {
						cout << "Course code: " << j.courseCode << '\n';
						cout << "From: " << j.from << '\n';
						cout << "To: " << j.to << '\n';
						cout << "Day of week: " << week[j.dayOfWeek] << "\n\n";
					}
			}
		}
	}
}