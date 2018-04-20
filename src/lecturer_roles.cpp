#include "lecturer_roles.h"

void importScoreBoard(User &loginUser) {
	vScore SL, NSL;
	char PATH[100];

	readScoreList(SCORE_PATH, SL);

	cout << "Please input path of your scoreboard file:";
	cin.getline(PATH, 100);

	readScoreList(PATH, NSL);

	for (auto &i : NSL.ScoreList)
		SL.ScoreList.push_back(i);

	writeScoreList(SCORE_PATH, SL);
}

void editGradeOfStudent(User &loginUser)
{
	vScore SL;
	vCourse CL;
	vUser UL;
	string studentID, courseCode;

	readUserList(USER_PATH, UL);
	readCourseList(COURSE_PATH, CL);
	readScoreList(SCORE_PATH, SL);

	cout << "Which student you want to edit grade (student id):";
	cin >> studentID;
	cout << "Which course's score you want to edit (course code):";
	cin >> courseCode;

	for (auto &i : SL.ScoreList) {
		if (i.courseCode == courseCode && i.studentID == studentID) {
			cout << "1. Midterm score: " << i.midtermScore << '\n';
			cout << "2. Final score: " << i.finalScore << '\n';
			cout << "3. Lab score: " << i.labScore << '\n';
			cout << "4. Bonus score: " << i.bonusScore << '\n';
			cout << "5. Total score: " << i.totalScore << '\n';
			cout << "You want edit midterm score to: ";
			cin >> i.midtermScore;
			cout << "You want edit final score to: ";
			cin >> i.finalScore;
			cout << "You want edit lab score to: ";
			cin >> i.labScore;
			cout << "You want edit bonus score to: ";
			cin >> i.bonusScore;
			cout << "You want edit total score to: ";
			cin >> i.totalScore;
			break;
		}
	}
	writeScoreList(SCORE_PATH, SL);
}

void viewScoreBoard(User &loginUser) {
	vScore SL;

	readScoreList(SCORE_PATH, SL);

	string courseCode;
	cout << "Please input a course you want to see score:";
	cin >> courseCode;
	for (auto &i : SL.ScoreList) {
		if (i.courseCode == courseCode) {
			cout << "Student ID: " << i.studentID << '\n';
			cout << "Midterm score: " << i.midtermScore << '\n';
			cout << "Final score: " << i.finalScore << '\n';
			cout << "Lab score: " << i.labScore << '\n';
			cout << "Bonus score: " << i.bonusScore << '\n';
			cout << "Total score: " << i.totalScore << '\n' << '\n';
		}
	}
}
