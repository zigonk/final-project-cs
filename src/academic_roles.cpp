#include "academic_roles.h"

void importStudentOfClass()
{
	char PATH[100];
	vUser UL;
	readUserList(USER_PATH, UL);
	vUser newUL;
	cout << "Please input path of your file you want to import:";
	cin.ignore();
	cin.getline(PATH,100);
	readUserList(PATH, newUL);
	vClass CL;
	readClassList(CLASS_PATH, CL);
	Class newClass;
	newClass.classCode = newUL.UserList[0].classCode;
	CL.ClassList.push_back(newClass);
	for (auto &i : newUL.UserList)
		UL.UserList.push_back(i);
	writeUserList(USER_PATH, UL);
}

void importCourses()
{
	char PATH[100];
	cout << "Please input path of file you want to import:";
	cin.ignore();
	cin.getline(PATH, 100);

	vCourse newCL;
	readCourseList(PATH, newCL);
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	for (auto &i : newCL.CourseList)
	{
		CL.CourseList.push_back(i);
	}
	writeCourseList(COURSE_PATH, CL);
}

void importCourseSchedule() 
{
	char PATH[100];
	cout << "Please input path of file you want to import:";
	cin.ignore();
	cin.getline(PATH, 100);

	vCourseSchedule newCL;
	readCourseScheduleList(PATH, newCL);
	vCourseSchedule  CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	for (auto &i : newCL.CourseScheduleList)
	{
		CSL.CourseScheduleList.push_back(i);
	}
	writeCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
}

void addANewStudent()
{
	string s;
	char c;
	vUser UL;
	readUserList(USER_PATH, UL);
	User tmp;
	tmp.uType = STUDENT;
	cout << "Enter student ID: ";
	cin >> s;
	tmp.username = s;
	cout << "Enter full name: ";
	cin.ignore();
	getline(cin, s);
	tmp.fullname = s;
	cout << "Enter email: ";
	cin >> s;
	tmp.email = s;
	cout << "Mobile phone: ";
	cin >> s;
	tmp.mobilePhone = s;
	cout << "Enter password: ";
	cin >> s;
	tmp.password = s;
	cout << "Enter class code: ";
	cin >> s;
	tmp.classCode = s;
	UL.UserList.push_back(tmp);
	writeUserList(USER_PATH, UL);
}

void editAnExistingStudent()
{
	vUser UL;
	readUserList(USER_PATH, UL);
	string id;
	cout << "Enter student ID you want to edit: ";
	cin >> id;
	User *pUser = nullptr;
	bool exist = false;
	for (auto &i : UL.UserList)
	{
		if (i.username == id)
		{
			exist = true;
			string s;
			char c;
			cout << "Last info of this student:\n";
			cout << "Username: " << i.username << endl;
			cout << "Fullname: " << i.fullname << endl;
			cout << "Email: " << i.email << endl;
			cout << "Mobile phone: " << i.mobilePhone << endl;
			cout << "Class: " << i.classCode << "\n\n";

			cout << "Enter new student ID: ";
			cin >> s;
			i.username = s;
			cout << "Enter new student name: ";
			cin.ignore();
			getline(cin, s);
			i.fullname = s;
			cout << "Enter new student email address: ";
			cin >> s;
			i.email = s;
			cout << "Enter mobile phone: ";
			cin >> s;
			i.mobilePhone = s;
			cout << "Enter new class code: ";
			cin >> s;
			i.classCode = s;
			break;
		}
	}
	if (!exist)
	{
		cout << "There is no such student ID ";
		return;
	}
	writeUserList(USER_PATH, UL);
}

void removeAStudent()
{
	vUser UL;
	readUserList(USER_PATH, UL);

	string id;
	cout << "Enter student ID you want to remove: ";
	cin >> id;
	int index = -1;
	for (int i = 0; i < UL.UserList.size(); i++)
	{
		if (UL.UserList[i].username == id)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		cout << "There is no such student ID !";
		return;
	}
	UL.UserList.erase(UL.UserList.begin() + index);
	writeUserList(USER_PATH, UL);
}

void changeStudentFromClassAToClassB()
{
	vUser UL;
	readUserList(USER_PATH, UL);

	string studentID, newClass;

	cout << "Enter student you want to change (student id):";
	cin >> studentID;

	cout << "Enter name of class you want to change to: ";
	cin >> newClass;

	for (auto &i : UL.UserList)
	{
		if (i.username == studentID)
			i.classCode = newClass;
	}
	writeUserList(USER_PATH, UL);
}

void addANewEmptyClass()
{
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

void viewListOfClass()
{
	vClass CL;
	readClassList(CLASS_PATH, CL);
	for (auto &i : CL.ClassList)
		cout << i.classCode << endl;
}

void viewListOfStudentInAClass()
{
	vUser UL;
	readUserList(USER_PATH, UL);
	vClass CL;
	readClassList(CLASS_PATH, CL);
	cout << "Enter the class you want to see student: ";
	string class_;
	cin >> class_;
	bool f = false;
	for (auto &i : CL.ClassList)
	{
		if (i.classCode == class_)
		{
			f = true;
		}
	}
	if (!f)
	{
		cout << "There is no class with that name";
		return;
	}
	cout << "Here is the student ID of student go for that class: ";
	for (auto &i : UL.UserList)
	{
		if (i.classCode == class_ && i.uType == STUDENT)
			cout << i.username << endl;
	}
}

void addANewCourse()
{
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
	cout << "Enter course name: ";
	cin.ignore();
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

void editAnCourse()
{
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	int index = -1;
	cout << "Enter course code of the course you want to edit: ";
	string cc;
	cin >> cc;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc)
		{
			index = i;
			break;
		}
	if (index == -1)
		cout << "There is no course with that course code !";
	else
	{
		string s;
		cout << "Enter course code: ";
		cin >> s;
		CL.CourseList[index].courseCode = s;
		cout << "Enter year: ";
		cin >> s;
		CL.CourseList[index].year = s;
		cout << "Enter course name: ";
		cin.ignore();
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

void removeACourse()
{
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	int index = -1;
	cout << "Enter course code of the course you want to remove: ";
	string cc;
	cin >> cc;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc)
		{
			index = i;
			break;
		}
	if (index == -1)
		cout << "There is no course with that course code !";
	else
	{
		CL.CourseList.erase(CL.CourseList.begin() + index);
	}
	writeCourseList(COURSE_PATH, CL);
}

void viewListOfACourse()
{
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	for (auto &i : CL.CourseList)
	{
		cout << "Course code: " << i.courseCode << endl;
		cout << "Year: " << i.year << endl;
		cout << "Course name: " << i.courseName << endl;
		cout << "Lecturer: " << i.lecturerUserName << endl;
		cout << "Class code: " << i.classCode << endl;
		cout << "Semester: " << i.semester << endl;
		cout << endl;
	}
}

void addACourseSchedule()
{
	vCourseSchedule CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	CourseSchedule tmp;
	string s;
	cout << "Enter course code: ";
	cin >> s;
	tmp.courseCode = s;
	cout << "Enter the day it start at (mm/dd): ";
	cin >> s;
	tmp.from = s;
	cout << "Enter the day it end at (mm/dd):";
	cin >> s;
	tmp.to = s;
	cout << "Enter the time it starts (hh:mm): ";
	cin >> s;
	tmp.startAt = s;
	cout << "Enter the time it ends (hh:mm) ";
	cin >> s;
	tmp.endAt = s;
	int day;
	cout << "Enter the day of week have this course [0-6]==[Sun-Sat]: ";
	cin >> day;
	tmp.dayOfWeek = day;
	CSL.CourseScheduleList.push_back(tmp);
}

bool checkCollide(CourseSchedule CS, CourseSchedule CS1)
{
	vCourse CL;
	readCourseList(COURSE_PATH, CL);
	Course course1, course2;
	for (int i = 0; i < CL.CourseList.size(); ++i)
	{
		if (CL.CourseList[i].courseCode == CS.courseCode)
		{
			course1 = CL.CourseList[i];
		}
		if (CL.CourseList[i].courseCode == CS1.courseCode)
		{
			course2 = CL.CourseList[i];
		}
	}
	if (course1.classCode != course2.classCode || course1.year != course2.year)
		return false;
	if (CS.startAt <= CS1.endAt && CS.endAt >= CS1.startAt)
	{
		if (CS.dayOfWeek != CS1.dayOfWeek)
			return false;
		return (CS.from <= CS1.to && CS.to >= CS1.from);
	}
	else
		return false;
}

void editACourseSchedule()
{
	vCourse CL;
	vCourseSchedule CSL;
	string courseCode, classCode = "-1";
	readCourseList(COURSE_PATH, CL);
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	cout << "Input course code you want to edit schedule:";
	cin >> courseCode;
	for (auto &i : CL.CourseList)
	{
		if (i.courseCode == courseCode)
		{
			classCode = i.classCode;
		}
	}
	if (classCode == "-1")
	{
		cout << "There is no course with that course code !" << endl;
		return;
	}
	for (int i = 0; i < CSL.CourseScheduleList.size(); ++i)
	{
		CourseSchedule CS = CSL.CourseScheduleList[i];
		if (CS.courseCode == courseCode)
		{
			cout << "Course code: " << CS.courseCode << '\n';
			cout << "Start at: " << CS.startAt << '\n';
			cout << "End at: " << CS.endAt << '\n';
			cout << "From: " << CS.from << '\n';
			cout << "To: " << CS.to << '\n';
			cout << "Day of week: " << week[CS.dayOfWeek] << "\n\n";
			char choice;
			cout << "Do you want edit this schedule (y/n):";
			cin >> choice;
			while (choice == 'y')
			{
				cout << "Start at (hh:mm): ";
				cin >> CS.startAt;
				cout << "End at (hh:mm): ";
				cin >> CS.endAt;
				cout << "From (mm/dd): ";
				cin >> CS.from;
				cout << "To (mm/dd): ";
				cin >> CS.to;
				cout << "Day of week [0-6]->[Sun->Sat]: ";
				cin >> CS.dayOfWeek;
				bool xet = true;
				for (int j = 0; j < CSL.CourseScheduleList.size(); ++j)
				{
					if (i == j)
						continue;
					if (checkCollide(CS, CSL.CourseScheduleList[j]))
					{
						cout << "Your new course schedule collide with other course schedule" << endl;
						xet = false;
						break;
					}
				}
				if (xet)
				{
					CSL.CourseScheduleList[i] = CS;
					break;
				}
				else
				{
					cout << "Do you want to edit again (y/n):";
					cin >> choice;
				}
			}
		}
	}
	writeCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
}

void removeACourseSchedule()
{
	vCourseSchedule CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	int index = -1;
	cout << "Enter course code of the course schedule you want to remove: ";
	string cc;
	cin >> cc;
	for (int i = 0; i < CSL.CourseScheduleList.size(); i++)
		if (CSL.CourseScheduleList[i].courseCode == cc)
		{
			index = i;
			break;
		}
	if (index == -1)
		cout << "There is no course with that course code !" << endl;
	else
	{
		CSL.CourseScheduleList.erase(CSL.CourseScheduleList.begin() + index);
	}
}

void viewListOfCourseSchedule()
{
	vCourseSchedule CSL;
	readCourseScheduleList(COURSE_SCHEDULE_PATH, CSL);
	for (auto &i : CSL.CourseScheduleList)
	{
		cout << "Course code: " << i.courseCode << endl;
		cout << "Start at: " << i.startAt << endl;
		cout << "End at: " << i.endAt << endl;
		cout << "From: " << i.from << endl;
		cout << "To: " << i.to << endl;
		cout << "Day of week: " << week[i.dayOfWeek] << endl;
		cout << endl;
	}
}

void searchAndViewAttendaceList()
{
	vCourse CL;
	vPresense PL;
	readCourseList(COURSE_PATH, CL);
	readPresenseList(PRESENCE_PATH, PL);
	cout << "Enter course code of the course you want to view the attendance list: ";
	string cc;
	cin >> cc;
	int index = -1;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc)
		{
			index = i;
			break;
		}
	if (index == -1)
	{
		cout << "There is no course with that course code !" << endl;
		return;
	}
	for (auto &i : PL.PresenseList)
	{
		if (i.courseCode == cc)
		{
			cout << "Year " << i.year << endl;
			cout << "Student ID: " << i.studentID << endl;
			cout << "Semester: " << i.semester << endl;
			cout << "Week: " << i.week << endl;
		}
	}
}

void searchAndViewScoreboard()
{
	vScore SL;
	vCourse CL;
	readScoreList(SCORE_PATH, SL);
	readCourseList(COURSE_PATH, CL);
	cout << "Enter course code of the course you want to view the scoreboard: ";
	string cc;
	cin >> cc;
	int index = -1;
	for (int i = 0; i < CL.CourseList.size(); i++)
		if (CL.CourseList[i].courseCode == cc)
		{
			index = i;
			break;
		}
	if (index == -1)
	{
		cout << "There is no course with that course code !";
		return;
	}
	else
	{
		for (auto &i : SL.ScoreList)
		{
			if (i.courseCode == cc)
			{
				cout << "Student ID: " << i.studentID << '\n';
				cout << "Midterm score: " << i.midtermScore << '\n';
				cout << "Final score: " << i.finalScore << '\n';
				cout << "Lab score: " << i.labScore << '\n';
				cout << "Bonus score: " << i.bonusScore << '\n';
				cout << "Total score: " << i.totalScore << '\n'
						 << '\n';
			}
		}
	}
}

void exportAttendenceList()
{
	vPresense PL;
	readPresenseList(PRESENCE_PATH, PL);
	cout << "Please input the path of the file you want to export:";
	char PATH[100];
	cin.ignore();
	cin.getline(PATH, 100);
	writePresenseList(PATH, PL);
}

void exportScoreBoard()
{
	vScore SL;
	readScoreList(SCORE_PATH, SL);
	cout << "Please input the path of the file you want to export:";
	char PATH[100];
	cin.ignore();
	cin.getline(PATH, 100);
	writeScoreList(PATH, SL);
}
