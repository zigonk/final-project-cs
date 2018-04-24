#include "menu.h"

void login(User &loginUser)
{
	system("clear");
	vUser UL;
	readUserList(USER_PATH, UL);
	while (loginUser.username.empty())
	{
		string username, password;
		cout << "Input your username:" << endl;
		cin >> username;
		cout << "Input your password:" << endl;
		cin >> password;
		for (auto &i : UL.UserList)
		{
			if (i.username == username && i.password == password)
			{
				loginUser = i;
				cout << "Login successfully"
						 << "\n\n";
				break;
			}
		}
	}
}

void showRoleList(User &loginUser)
{
	while (true)
	{
		system("clear");
		cout << endl;
		switch (loginUser.uType)
		{
		case ACADEMIC_STAFF:
		{
			cout << "1. Import students of a class from a csv file " << endl;
			cout << "2. Add a new student to a class " << endl;
			cout << "3. Edit an existing student " << endl;
			cout << "4. Remove a student" << endl;
			cout << "5. Change students from class A to class B" << endl;
			cout << "6. Add a new empty class" << endl;
			cout << "7. View list of classes" << endl;
			cout << "8. View list of students in a class" << endl;
			cout << "9. Import courses from a csv file" << endl;
			cout << "10. Add a new course" << endl;
			cout << "11. Edit an existing course" << endl;
			cout << "12. Remove a course" << endl;
			cout << "13. View list of courses" << endl;
			cout << "14. Import courses’ schedules from a csv file" << endl;
			cout << "15. Add a course’s schedule" << endl;
			cout << "16. Edit a course’s schedule (remember to check collided cases)" << endl;
			cout << "17. Remove a course’s schedule" << endl;
			cout << "18. View list of schedules." << endl;
			cout << "19. Search and view attendance list of a course" << endl;
			cout << "20. Export attendance list to a csv file" << endl;
			cout << "21. Search and view scoreboard of a course" << endl;
			cout << "22. Export a scoreboard to a csv file" << endl;
			cout << "23. Return" << endl;
			break;
		}
		case LECTURER:
		{
			cout << "1. Import scoreboard of a course (midterm, final, lab, bonus)" << endl;
			cout << "2. Edit grade of a student" << endl;
			cout << "3. View a scoreboard" << endl;
			cout << "4. Return" << endl;
			break;
		}
		case STUDENT:
		{
			cout << "1. Check-in." << endl;
			cout << "2. View check-in result" << endl;
			cout << "3. View his/her scores of a course" << endl;
			cout << "4. View schedules" << endl;
			cout << "5. Return" << endl;
			break;
		}
		}
		//check ACADEMIC_STAFF
		if (loginUser.uType == ACADEMIC_STAFF)
		{
			int choice = 0;
			do
			{
				cout << "What do you want to do: ";
				cin >> choice;
				if (choice < 1 || choice > 23)
				{
					cout << "You don't have permission." << endl;
					char c;
					do
					{
						cout << "Do you want to try again (y/n): ";
						cin >> c;
					} while (tolower(c) != 'y' && tolower(c) != 'n');
					if (tolower(c) == 'n')
						return;
				}
			} while (choice < 1 || choice > 23);
			switch (choice)
			{
			case 1:
			{
				system("clear");
				importStudentOfClass();
				break;
			}
			case 2:
			{
				system("clear");
				addANewStudent();
				break;
			}
			case 3:
			{
				system("clear");
				editAnExistingStudent();
				break;
			}
			case 4:
			{
				system("clear");
				removeAStudent();
				break;
			}
			case 5:
			{
				system("clear");
				changeStudentFromClassAToClassB();
				break;
			}
			case 6:
			{
				system("clear");
				addANewEmptyClass();
				break;
			}
			case 7:
			{
				system("clear");
				viewListOfClass();
				break;
			}
			case 8:
			{
				system("clear");
				viewListOfStudentInAClass();
				break;
			}
			case 9:
			{
				system("clear");
				importCourses();
				break;
			}
			case 10:
			{
				system("clear");
				addANewCourse();
				break;
			}
			case 11:
			{
				system("clear");
				editAnCourse();
				break;
			}
			case 12:
			{
				system("clear");
				removeACourse();
				break;
			}
			case 13:
			{
				system("clear");
				viewListOfACourse();
				break;
			}
			case 14:
			{
				system("clear");
				importCourseSchedule();
				break;
			}
			case 15:
			{
				system("clear");
				addACourseSchedule();
				break;
			}
			case 16:
			{
				system("clear");
				editACourseSchedule();
				break;
			}
			case 17:
			{
				system("clear");
				removeACourseSchedule();
				break;
			}
			case 18:
			{
				system("clear");
				viewListOfCourseSchedule();
				break;
			}
			case 19:
			{
				system("clear");
				searchAndViewAttendaceList();
				break;
			}
			case 20:
			{
				system("clear");
				exportAttendenceList();
				break;
			}
			case 21:
			{
				system("clear");
				searchAndViewScoreboard();
				break;
			}
			case 22:
			{
				system("clear");
				exportScoreBoard();
				break;
			}
			default:
				return;
			}
		}
		else if (loginUser.uType == LECTURER)
		{
			int choice = 0;
			do
			{
				cout << "What do you want to do:";
				cin >> choice;
				if (choice < 1 || choice > 4)
				{
					cout << "You don't have permission." << endl;
					char c;
					do
					{
						cout << "Do you want to try again (y/n):";
						cin >> c;
					} while (tolower(c) != 'y' && tolower(c) != 'n');
					if (tolower(c) == 'n')
						return;
				}
			} while (choice < 1 || choice > 4);
			switch (choice)
			{
			case 1:
			{
				system("clear");
				importScoreBoard(loginUser);
				break;
			}
			case 2:
			{
				system("clear");
				editGradeOfStudent(loginUser);
				break;
			}
			case 3:
			{
				system("clear");
				viewScoreBoard(loginUser);
				break;
			}
			default:
				return;
			}
		}
		else if (loginUser.uType == STUDENT)
		{
			int choice = 0;
			do
			{
				cout << "What do you want to do:";
				cin >> choice;
				if (choice < 1 || choice > 5)
				{
					cout << "You don't have permission." << endl;
					char c;
					do
					{
						cout << "Do you want to try again (y/n):";
						cin >> c;
					} while (tolower(c) != 'y' && tolower(c) != 'n');
					if (tolower(c) == 'n')
						return;
				}
			} while (choice < 1 || choice > 5);
			switch (choice)
			{
			case 1:
			{
				system("clear");
				checkIn(loginUser);
				break;
			}
			case 2:
			{
				system("clear");
				viewCheckInResult(loginUser);
				break;
			}
			case 3:
			{
				system("clear");
				viewScoreOfACourse(loginUser);
				break;
			}
			case 4:
			{
				system("clear");
				viewSchedule(loginUser);
				break;
			}
			default:
			{
				return;
			}
			}
		}
		cout << endl;
		cout << "Press anykey to continue.";
		cin.ignore();
		cin.get();
	}
}

void viewInfo(User loginUser)
{
	system("clear");
	cout << "Info of your user" << endl;
	cout << "Username: " << loginUser.username << endl;
	cout << "Fullname: " << loginUser.fullname << endl;
	cout << "Email: " << loginUser.email << endl;
	cout << "Mobile phone: " << loginUser.mobilePhone << endl;
	cout << "Type: ";
	switch (loginUser.uType)
	{
	case ACADEMIC_STAFF:
	{
		cout << "Academic Staff" << endl;
		break;
	}
	case STUDENT:
	{
		cout << "Student" << endl;
		break;
	}
	case LECTURER:
	{
		cout << "Lecturer" << endl;
		break;
	}
	}
	cout << "Password: " << loginUser.password << endl;
	cout << "Class: " << loginUser.classCode << "\n\n";
	cout << "Press anykey to continue.";
	cin.ignore();
	cin.get();
}

void changePassword(User &loginUser)
{
	system("clear");
	string oldPassword, newPassword;
	cout << "Please input your old password:";
	cin >> oldPassword;
	cout << "Please input your new password:";
	cin >> newPassword;
	while (oldPassword != loginUser.password)
	{
		cout << "Your password is wrong." << endl;
		char choice;
		cout << "Do you want to try again (y/n):";
		cin >> choice;
		if (tolower(choice) == 'n')
		{
			return;
		}
		cout << "Please input your old password:";
		cin >> oldPassword;
		cout << "Please input your new password:";
		cin >> newPassword;
	}
	loginUser.password = newPassword;
	vUser UL;
	readUserList(USER_PATH, UL);
	for (auto &i : UL.UserList)
	{
		if (i.username == loginUser.username)
		{
			i.password = loginUser.password;
			break;
		}
	}
	writeUserList(USER_PATH, UL);
}

void logout(User &loginUser)
{
	loginUser.username = "";
}
