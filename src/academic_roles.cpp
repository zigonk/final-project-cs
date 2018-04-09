#include "academic_roles.h"

void importStudentOfClass() {

}
//support function 14
string modifyString(string &s)
{
    string tmp ="";
    while(s[0] != ',')
    {
        tmp = tmp + s[0];
        s.erase(0,1);
    }
    s.erase(0,1); // erase the remaining comma.
    return tmp;
}

//function 14
void importCourses()
{
    ifstream fin;
//	ofstream fout;
//	fout.open("output.txt");
	fin.open("courses.csv");
	if(!fin.is_open())
    {
        cout<<"Error ! Can't read the file !";
        return;
    }
    string s;
    while(getline(fin,s))
    {
        s = s + ',';
        CourseSchedule tmp;
        tmp.courseCode = modifyString(s);
        tmp.year = modifyString(s);
        string x = modifyString(s);
        tmp.semester = x[0]-'0';
        tmp.courseName = modifyString(s);
        tmp.lecturerUserName = modifyString(s);
        tmp.startAt = modifyString(s);
        tmp.endAt = modifyString(s);
        tmp.from = modifyString(s);
        tmp.to = modifyString(s);
        tmp.dateOfWeek = modifyString(s);

        //???


        ;
    }
//    fout.close();
    fin.close();
}
