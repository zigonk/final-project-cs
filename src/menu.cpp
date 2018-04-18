#include "menu.h"

void login(User &loginUser) {
	vUser UL;
	readUserList(USER_PATH, UL);
	while (loginUser.username.empty()) {
		string username, password;
		cout << "Input your username:" << endl;
		getline(cin, username);
		cout << "Input your password:" << endl;
		getline(cin, password);
		for (auto &i : UL.UserList) {
			if (i.username == username && i.password == password) {
				loginUser = i;
				cout << "Login successfully"
				     << "\n\n";
				break;
			}
		}
	}
}

void showRoleList(User &loginUser) {
	switch (loginUser.uType) {
		case ACADEMIC_STAFF: {
			cout << "6. Import students of a class from a csv file " << endl;
			cout << "7. Add a new student to a class " << endl;
			cout << "8. Edit an existing student " << endl;
			cout << "9. Remove a student" << endl;
			cout << "10. Change students from class A to class B" << endl;
			cout << "11. Add a new empty class" << endl;
			cout << "12. View list of classes" << endl;
			cout << "13. View list of students in a class" << endl;
			cout << "14. Import courses from a csv file" << endl;
			cout << "15. Add a new course" << endl;
			cout << "16. Edit an existing course" << endl;
			cout << "17. Remove a course" << endl;
			cout << "18. View list of courses" << endl;
			cout << "19. Import courses’ schedules from a csv file" << endl;
			cout << "20. Add a course’s schedule" << endl;
			cout << "21. Edit a course’s schedule (remember to check collided cases)" << endl;
			cout << "22. Remove a course’s schedule" << endl;
			cout << "23. View list of schedules." << endl;
			cout << "24. Search and view attendance list of a course" << endl;
			cout << "25. Export attendance list to a csv file" << endl;
			cout << "26. Search and view scoreboard of a course" << endl;
			cout << "27. Export a scoreboard to a csv file" << endl;
			break;
		}
		case LECTURER: {
			cout << "28. Import scoreboard of a course (midterm, final, lab, bonus)" << endl;
			cout << "29. Edit grade of a student" << endl;
			cout << "30. View a scoreboard" << endl;
			break;
		}
		case STUDENT: {
			cout << "31. Check-in." << endl;
			cout << "32. View check-in result" << endl;
			cout << "33. View his/her scores of a course" << endl;
			cout << "34. View schedules" << endl;
			break;
		}
	}
	//check ACADEMIC_STAFF
	if (loginUser.uType == ACADEMIC_STAFF) {
		int choice = 0;
		do {
			cout << "What do you want to do:";
			cin >> choice;
			if (choice < 6 || choice > 27) {
				cout << "You don't have permission." << endl;
				char c;
				do {
					cout << "Do you want to try again (y/n):";
					cin >> c;
				} while (tolower(c) != 'y' && tolower(c) != 'n');
				if (tolower(c) == 'n') return;

			}
		} while (choice < 6 || choice > 27);
		switch (choice) {
			case 6: {
				//importStudentOfClass();
			}
			default:
				break;
		}
	} else if (loginUser.uType == LECTURER) {
		int choice = 0;
		cout << "What do you want to do: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				importScoreBoard(loginUser);
				break;
			}
			case 2: {
				editGradeOfStudent(loginUser);
				break;
			}
			case 3: {
				viewScoreBoard(loginUser);
				break;
			}
			default: break;
		}
	} else if (loginUser.uType == STUDENT) {
		int choice = 0;
		cout << "What do you want to do:";
		cin >> choice;
		switch (choice) {
			case 31: {
				checkIn(loginUser);
				break;
			}
			case 32: {
				viewCheckInResult(loginUser);
				break;
			}
			case 33: {
				viewScoreOfACourse(loginUser);
				break;
			}
			case 34: {
				viewSchedule(loginUser);
				break;
			}
			default: {
				break;
			}
		}
	}
}

void viewInfo(User loginUser) {
	cout << "Info of your user" << endl;
	cout << "Username: " << loginUser.username << endl;
	cout << "Fullname: " << loginUser.fullname << endl;
	cout << "Email: " << loginUser.email << endl;
	cout << "Mobile phone: " << loginUser.mobilePhone << endl;
	cout << "Type: ";
	switch (loginUser.uType) {
		case ACADEMIC_STAFF: {
			cout << "Academic Staff" << endl;
			break;
		}
		case STUDENT: {
			cout << "Student" << endl;
			break;
		}
		case LECTURER: {
			cout << "Lecturer" << endl;
			break;
		}
	}
	cout << "Password: " << loginUser.password << endl;
	cout << "Class: " << loginUser.classCode << "\n\n";
}

void changePassword(User &loginUser) {
	string oldPassword, newPassword;
	cout << "Please input your old password:";
	cin >> oldPassword;
	cout << "Please input your new password:";
	cin >> newPassword;
	while (oldPassword != loginUser.password) {
		cout << "Your password is wrong." << endl;
		char choice;
		cout << "Do you want to try again (y/n):";
		cin >> choice;
		if (tolower(choice) == 'n') {
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
	for (auto &i : UL.UserList) {
		if (i.username == loginUser.username) {
			i.password = loginUser.password;
			break;
		}
	}
	writeUserList(USER_PATH, UL);
}
