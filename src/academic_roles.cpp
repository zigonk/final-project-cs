#include "academic_roles.h"

void importStudentOfClass() {

}

//support function 14
//function 14
void importCourses() {
	char PATH[100];
	cout << "Please input path of file courses.csv:";
	cin.getline(PATH, 100);

	vCourse newCL;
	readCourseList(PATH, newCL);
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	for (auto &i:newCL.CourseList) {
		CL.CourseList.push_back(i);
	}
	writeCourseList(PATH, CL);
}

void addANewStudent() {
	string s;
	vUser UL;
	readUserList(USER_PATH, UL);
	User tmp;
	tmp.uType = STUDENT;
	cout << "Enter student ID: ";
	cin >> s;
	tmp.username = s;
	cout << "Enter full name: ";
	getline(cin, s);
	tmp.fullname = s;
	cout << "Enter email: ";
	cin >> s;
	tmp.email = s;
	cout << "Mobile phone: ";
	cin >> s;
	tmp.mobilePhone = s;
	cout << "Enter password: ";
	getline(cin, s);
	tmp.password = s;
	cout << "Enter class code: ";
	cin >> s;
	tmp.classCode = s;
	UL.UserList.push_back(tmp);
}

void editAnExistingStudent() {
	vUser UL;
	readUserList(USER_PATH, UL);
	string id;
	cout << "Enter student ID you want to edit: ";
	cin >> id;
	User *pUser = nullptr;
	bool exist = false;
	for (auto &i : UL.UserList) {
		if (i.username == id) {
			exist = true;
			pUser = &i;
			break;
		}
	}
	if (!exist) {
		cout << "There is no such student ID ";
		return;
	}
	string s;
	cin >> s;
	cout << "Enter new student ID: ";
	pUser->username = s;
	cout << "Enter new student name: ";
	getline(cin, s);
	pUser->fullname = s;
	cout << "Enter new student email address: ";
	cin >> s;
	pUser->email = s;
	cout << "Enter mobile phone: ";
	cin >> s;
	pUser->mobilePhone = s;
	cout << "Enter new Class code: ";
	cin >> s;
	pUser->classCode = s;
	writeUserList(USER_PATH, UL);
}

void removeAStudent() {
	vUser UL;
	readUserList(USER_PATH, UL);

	string id;
	cout << "Enter student ID you want to remove: ";
	cin >> id;
	int index = -1;
	for (int i = 0; i < UL.UserList.size(); i++) {
		if (UL.UserList[i].username == id) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "There is no such student ID !";
		return;
	}
	UL.UserList.erase(UL.UserList.begin() + index);
	writeUserList(USER_PATH, UL);
}

void changeStudentFromClassAToClassB() {
	vUser UL;
	readUserList(USER_PATH, UL);

	string studentID, newClass;

	cout << "Enter student you want to change (student id):";
	cin >> studentID;

	cout << "Enter name of class you want to change to: ";
	cin >> newClass;

	for (auto &i : UL.UserList) {
		if (i.username == studentID) i.classCode = newClass;
	}
	writeUserList(USER_PATH, UL);
}

void addANewEmptyClass() {
	vClass CL;
	readClassList(CLASS_PATH, CL);
	cout << "Enter class code of the new class: ";
	string newClass;
	cin >> newClass;
	Class tmp;
	tmp.classCode = newClass;
	CL.ClassList.push_back(tmp);
	writeClassList(CLASS_PATH, CL);
}

void viewListOfClass() {
	vClass CL;
	readClassList(CLASS_PATH, CL);
	for (auto &i : CL.ClassList)
		cout << i.classCode << endl;
}

void viewListOfStudentInAClass() {
	vUser UL;
	readUserList(USER_PATH, UL);
	vClass CL;
	readClassList(CLASS_PATH, CL);
	cout << "Enter the class you want to see student: ";
	string class_;
	cin >> class_;
	bool f = false;
	for (auto &i : CL.ClassList) {
		if (i.classCode == class_) {
			f = true;
		}
	}
	if (!f) {
		cout << "There is no class with that name";
		return;
	}
	cout << "Here is the student ID of student go for that class: ";
	for (auto &i : UL.UserList) {
		if (i.classCode == class_)
			cout << i.username << " ";
	}
}

void addANewCourse() {
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	Course tmp;
	string s;
	cout << "Enter course code: ";
	cin >> s;
	tmp.courseCode = s;
	cout << "Enter year: ";
	cin >> s;
	tmp.year = s;
	cout << "Enter course name";
	getline(cin, s);
	tmp.courseName = s;
	cout << "Enter the lecture user name: ";
	cin >> s;
	tmp.lecturerUserName = s;
	cout << "Enter class code: ";
	cin >> s;
	tmp.classCode = s;
	int sem;
	cout << "Enter the semester have this course: ";
	cin >> sem;
	tmp.semester = sem;
	CL.CourseList.push_back(tmp);
	writeCourseList(COURSE_PATH, CL);
}

void editAnCourse() {
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	int index = -1;
	cout << "Enter course code of the course you want to edit: ";
	string cc;
	cin >> cc;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc) {
			index = i;
			break;
		}
	if (index == -1)
		cout << "There is no course with that course code !";
	else {
		string s;
		cout << "Enter course code: ";
		cin >> s;
		CL.CourseList[index].courseCode = s;
		cout << "Enter year: ";
		cin >> s;
		CL.CourseList[index].year = s;
		cout << "Enter course name";
		getline(cin, s);
		CL.CourseList[index].courseName = s;
		cout << "Enter the lecture user name: ";
		cin >> s;
		CL.CourseList[index].lecturerUserName = s;
		cout << "Enter class code: ";
		cin >> s;
		CL.CourseList[index].classCode = s;
		int sem;
		cout << "Enter the semester have this course: ";
		cin >> sem;
		CL.CourseList[index].semester = sem;
	}
	writeCourseList(COURSE_PATH, CL);
}

void removeAnCourse() {
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	int index = -1;
	cout << "Enter course code of the course you want to remove: ";
	string cc;
	cin >> cc;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc) {
			index = i;
			break;
		}
	if (index == -1)
		cout << "There is no course with that course code !";
	else {
		CL.CourseList.erase(CL.CourseList.begin() + index);
	}
	writeCourseList(COURSE_PATH, CL);
}


void viewListOfACourse() {
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	for (auto &i : CL.CourseList) {
		cout << "Course code: " << i.courseCode << endl;
		cout << "Year: " << i.year << endl;
		cout << "Course name: " << i.courseName << endl;
		cout << "Lecturer: " << i.lecturerUserName << endl;
		cout << "Class code: " << i.classCode << endl;
		cout << "Semester: " << i.semester << endl;
		cout << endl;
	}
}

void addACourseSchedule() {
	vCourseSchedule CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	CourseSchedule tmp;
	string s;
	cout << "Enter course code: ";
	cin >> s;
	tmp.courseCode = s;
	cout << "Enter the day it start at: ";
	cin >> s;
	tmp.startAt = s;
	cout << "Enter the day it end at";
	getline(cin, s);
	tmp.endAt = s;
	cout << "Enter the time it starts: ";
	cin >> s;
	tmp.from = s;
	cout << "Enter the time it ends: ";
	cin >> s;
	tmp.to = s;
	int day;
	cout << "Enter the day of week have this course: ";
	cin >> day;
	tmp.dayOfWeek = day;
	CSL.CourseScheduleList.push_back(tmp);
}

//void editACourseSchedule(vCourseSchedule &CourseScheduleList) {
//	int index = -1;
//	cout << "Enter course code of the course you want to edit: ";
//	string cc;
//	cin >> cc;
//	for (int i = 0; i < CourseScheduleList.size(); i++)
//		if (CourseScheduleList[i].courseCode == cc) {
//			index = i;
//			break;
//		}
//	if (index == -1)
//		cout << "There is no course with that course code !";
//	else {
//		string s;
//		cout << "Enter course code: ";
//		cin >> s;
//		CourseScheduleList[index].courseCode = s;
//		cout << "Enter the day it start at: ";
//		cin >> s;
//		CourseScheduleList[index].startAt = s;
//		cout << "Enter the day it end at";
//		getline(cin, s);
//		CourseScheduleList[index].endAt = s;
//		cout << "Enter the time it starts: ";
//		cin >> s;
//		CourseScheduleList[index].from = s;
//		cout << "Enter the time it ends: ";
//		cin >> s;
//		CourseScheduleList[index].to = s;
//		int day;
//		cout << "Enter the day of week have this course: ";
//		cin >> day;
//		CourseScheduleList[index].dayOfWeek = day;
//	}
//}


void removeACourseSchedule() {
	vCourseSchedule CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	int index = -1;
	cout << "Enter course code of the course schedule you want to remove: ";
	string cc;
	cin >> cc;
	for (int i = 0; i < CSL.CourseScheduleList.size(); i++)
		if (CSL.CourseScheduleList[i].courseCode == cc) {
			index = i;
			break;
		}
	if (index == -1)
		cout << "There is no course with that course code !";
	else {
		CSL.CourseScheduleList.erase(CSL.CourseScheduleList.begin() + index);
	}
}

void viewListOfCourseSchedule() {
	vCourseSchedule CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	for (auto &i : CSL.CourseScheduleList) {
		cout << "Course code: " << i.courseCode << endl;
		cout << "Start at: " << i.startAt << endl;
		cout << "End at: " << i.endAt << endl;
		cout << "From: " << i.from << endl;
		cout << "To: " << i.to << endl;
		cout << "Day of week: " << i.dayOfWeek << endl;
		cout << endl;
	}
}

void searchAndViewAttendaceList() {
	vCourse CL;
	vPresense PL;
	readCourseList(COURSE_PATH, CL);
	readPresenseList(PRESENCE_PATH, PL);
	cout << "Enter course code of the course you want to view the attendance list: ";
	string cc;
	cin >> cc;
	int index = -1;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc) {
			index = i;
			break;
		}
	if (index == -1) {
		cout << "There is no course with that course code !";
		return;
	}
	for (auto &i : PL.PresenseList) {
		if (i.courseCode == cc) {
			cout << "Year " << i.year << endl;
			cout << "Student ID: " << i.studentID << endl;
			cout << "Semester: " << i.semester << endl;
			cout << "Week: " << i.week << endl;
		}
	}
}

void searchAndViewScoreboard() {
	vScore SL;
	vCourse CL;
	readScoreList(SCORE_PATH, SL);
	readCourseList(COURSE_PATH, CL);
	cout << "Enter course code of the course you want to view the attendance list: ";
	string cc;
	cin >> cc;
	int index = -1;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc) {
			index = i;
			break;
		}
	if (index == -1) {
		cout << "There is no course with that course code !";
		return;
	} else {
		for (auto &i : SL.ScoreList) {
			if (i.courseCode == cc) {
				cout << "Student ID: " << i.studentID << '\n';
				cout << "Midterm score: " << i.midtermScore << '\n';
				cout << "Final score: " << i.finalScore << '\n';
				cout << "Lab score: " << i.labScore << '\n';
				cout << "Bonus score: " << i.bonusScore << '\n';
				cout << "Total score: " << i.totalScore << '\n' << '\n';
			}
		}
	}
}
