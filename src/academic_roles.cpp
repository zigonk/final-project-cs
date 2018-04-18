
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

void addANewStudent(vUser &UserList)
{
    string s;
    User tmp;
    tmp.uType = STUDENT;
    cout<<"Enter student ID: ";
    cin>>s;
    tmp.username = s;
    cout<<"Enter full name: "; getline(cin,s);
    tmp.fullname = s;
    cout<<"Enter email: "; cin>>s;
    tmp.email = s;
    cout<<"Mobile phone: "; cin>>s;
    tmp.mobilePhone = s;
    cout<<"Enter password: ";
    getline(cin,s);
    tmp.password = s;
    cout<<"Enter class code: "; cin>>s;
    tmp.classCode = s;
    UserList.push_back(tmp);
}

void editAnExistingStudent(vUser &UserList)
{
    string id;
    cout<<"Enter student ID you want to edit: ";
    cin>>id;
    User tmp;
    bool exist = false;
    for(int i =0; i<UserList.size(); i++)
    {
        if(UserList[i].username ==id)
        {
            exist = true;
            User tmp = UserList[i];
            break;
        }
    }
    if(!exist)
    {
        cout<<"There is no such student ID ";
        return;
    }
    string s; cin>>s;
    cout<<"Enter new student ID: ";
    tmp.username = s;
    cout<<"Enter new student name: ";
    getline(cin,s);
    tmp.fullname = s;
    cout<<"Enter new student email address: ";
    cin>>s;
    tmp.email = s;
    cout<<"Enter mobile phone: ";
    cin>>s;
    tmp.mobilePhone = s;
    tmp.uType = STUDENT;
    cout<<"Enter new Class code: ";
    cin>>s;
    tmp.classCode = s;
}

void removeAStudent(vUser &UserList)
{
    string id;
    cout<<"Enter student ID you want to remove: ";
    cin>>id;
    int index = -1;
    for(int i =0; i<UserList.size(); i++)
    {
        if(UserList[i].username==id)
        {
            index=  i;
            break;
        }
    }
    if(index ==-1)
    {
        cout<<"There is no such student ID !";
        return;
    }
    for(int i = index; i<UserList.size(); i++)
    {
        UserList[i] = UserList[i+1];
    }
    UserList.pop_back();
}

void changeStudentsFromClassAToClassB(vUser &UserList)
{
    cout<<"Enter name of class you wnat to change to: ";
    string newClass; cin>>newClass;
    for(int i =0; i<UserList.size(); ++i)
    {
        UserList[i].classCode = newClass;
    }
}

void addANewEmptyClass(vClass &ClassList)
{
    cout<<"Enter class code of the new class: ";
    string newClass;
    cin>>newClass;
    Class tmp;
    tmp.classCode = newClass;
    ClassList.push_back(tmp);
}


void viewListOfClass(vClass &ClassList)
{
    for(int i =0; i<ClassList.size(); ++i)
        cout<<ClassList[i].classCode;
}


void viewListOfStudentInAClass(vUser &UserList, vClass &ClassList)
{
    cout<<"Enter the class you want to see student: ";
    string class_;
    cin>> class_;
    bool f = false;
    for(int i =0; i<ClassList.size(); i++)
    {
        if(ClassList[i].classCode ==class_)
        {
            f = true;
        }
    }
    if(!f)
    {
        cout<<"There is no class with that name";
        return;
    }
    cout<<"Here is the student ID of student go for that class: ";
    for(int i=0; i<UserList.size(); i++)
    {
        if(UserList[i].classCode==class_)
            cout<<UserList[i].username<< " ";
    }
}

void addANewCourse(vCourse &CourseList)
{
    Course tmp;
    string s;
    cout<<"Enter course code: ";
    cin>>s; tmp.courseCode = s;
    cout<<"Enter year: ";
    cin>>s; tmp.year = s;
    cout<<"Enter course name";
    getline(cin,s); tmp.courseName = s;
    cout<<"Enter the lecture user name: ";
    cin>>s; tmp.lecturerUserName = s;
    cout<<"Enter class code: ";
    cin>>s; tmp.classCode = s;
    int sem;
    cout<<"Enter the semester have this course: ";
    cin>>sem; tmp.semester = sem;
    CourseList.push_back(tmp);
}

void editAnCourse(vCourse &CourseList)
{
    int index = -1;
    cout<<"Enter course code of the course you want to edit: ";
    string cc; cin>>cc;
    for(int i =0; i<CourseList.size(); i++)
        if(CourseList[i].courseCode == cc)
        {
            index = i;
            break;
        }
    if(index == -1)
        cout<<"There is no course with that course code !";
    else{
        string s;
    cout<<"Enter course code: ";
    cin>>s; CourseList[index].courseCode = s;
    cout<<"Enter year: ";
    cin>>s; CourseList[index].year = s;
    cout<<"Enter course name";
    getline(cin,s); CourseList[index].courseName = s;
    cout<<"Enter the lecture user name: ";
    cin>>s; CourseList[index].lecturerUserName = s;
    cout<<"Enter class code: ";
    cin>>s; CourseList[index].classCode = s;
    int sem;
    cout<<"Enter the semester have this course: ";
    cin>>sem; CourseList[index].semester = sem;
    }
}

void removeAnCourse(vCourse &CourseList)
{
        int index = -1;
    cout<<"Enter course code of the course you want to remove: ";
    string cc; cin>>cc;
    for(int i =0; i<CourseList.size(); i++)
        if(CourseList[i].courseCode == cc)
        {
            index = i;
            break;
        }
    if(index == -1)
        cout<<"There is no course with that course code !";
    else{
        for(int i = index + 1; i<CourseList.size(); i++)
            CourseList[i] = CourseList[i+1];
        CourseList.pop_back();
    }
}


void viewListOFACourse(vCourse &CourseList)
{
    for(int i =0; i<CourseList.size(); ++i)
    {
        cout<<"Course code: "<<CourseList[i].courseCode<<endl;
        cout<<"Year: "<<CourseList[i].year<<endl;
        cout<<"Course name: "<<CourseList[i].courseName<<endl;
        cout<<"Lecture usename "<<CourseList[i].lecturerUserName<<endl;
        cout<<"Class code: "<<CourseList[i].classCode<<endl;
        cout<<"Semester: "<<CourseList[i].semester<<endl;
        cout<<endl;
    }
}

void addACourseSchedule(vCourseSchedule &CourseScheduleList)
{
    CourseSchedule tmp;
    string s;
    cout<<"Enter course code: ";
    cin>>s; tmp.courseCode = s;
    cout<<"Enter the day it start at: ";
    cin>>s; tmp.startAt = s;
    cout<<"Entet the day it end at";
    getline(cin,s); tmp.endAt = s;
    cout<<"Enter the time it starts: ";
    cin>>s; tmp.from = s;
    cout<<"Enter the time it ends: ";
    cin>>s; tmp.to = s;
    int day;
    cout<<"Enter the day of week have this course: ";
    cin>>day; tmp.dayOfWeek = day;
    CourseScheduleList.push_back(tmp);
}

void editACourseSchedule(vCourseSchedule& CourseScheduleList)
{
    int index = -1;
    cout<<"Enter course code of the course you want to edit: ";
    string cc; cin>>cc;
    for(int i =0; i<CourseScheduleList.size(); i++)
        if(CourseScheduleList[i].courseCode == cc)
        {
            index = i;
            break;
        }
    if(index == -1)
        cout<<"There is no course with that course code !";
    else{
        string s;
    cout<<"Enter course code: ";
    cin>>s; CourseScheduleList[index].courseCode = s;
    cout<<"Enter the day it start at: ";
    cin>>s; CourseScheduleList[index].startAt = s;
    cout<<"Enter the day it end at";
    getline(cin,s); CourseScheduleList[index].endAt = s;
    cout<<"Enter the time it starts: ";
    cin>>s; CourseScheduleList[index].from = s;
    cout<<"Enter the time it ends: ";
    cin>>s; CourseScheduleList[index].to = s;
    int day;
    cout<<"Enter the day of week have this course: ";
    cin>>day; CourseScheduleList[index].dayOfWeek = day;
    }
}


void removeACourseSchedule(vCourseSchedule &CourseScheduleList)
{
    int index = -1;
    cout<<"Enter course code of the course schedule you want to remove: ";
    string cc; cin>>cc;
    for(int i =0; i<CourseScheduleList.size(); i++)
        if(CourseScheduleList[i].courseCode == cc)
        {
            index = i;
            break;
        }
    if(index == -1)
        cout<<"There is no course with that course code !";
    else{
        for(int i = index + 1; i<CourseScheduleList.size(); i++)
            CourseScheduleList[i] = CourseScheduleList[i+1];
        CourseScheduleList.pop_back();
    }
}

void viewListOfCourseSchedule(vCourseSchedule &CourseScheduleList)
{
    for(int i =0; i<CourseScheduleList.size(); i++)
    {
        cout<<"Course code: "<<CourseScheduleList[i].courseCode<<endl;
        cout<<"Start at: "<<CourseScheduleList[i].startAt<<endl;
        cout<<"End at: "<<CourseScheduleList[i].endAt<<endl;
        cout<<"From: "<<CourseScheduleList[i].from<<endl;
        cout<<"To: "<<CourseScheduleList[i].to<<endl;
        cout<<"Day of week: "<<CourseScheduleList[i].dayOfWeek<<endl;
        cout<<endl;
    }
}

void searchAndViewAttendaceList(vCourse &CourseList, vPersense &PersenseList)
{
    cout<<"Enter course code of the course you wnat to view the attendance list: ";
    string cc; cin>>cc;
    int index = -1;
    for(int i =0; i<CourseList.size(); i++)
        if(CourseList[i].courseCode ==cc)
        {
            index = i;
            break;
        }
    if(index ==-1){
        cout<<"There is no course with that course code !";
        return ;
    }
    for(int i = 0; i<PersenseList.size(); i++)
    {
        if(PersenseList[i].courseCode ==cc)
        {
            cout<<"Year "<<PersenseList[i].year<<endl;
            cout<<"Student ID: "<<PersenseList[i].studentID<<endl;
            cout<<"Semester: "<<PersenseList[i].semester<<endl;
            cout<<"Week: "<<PersenseList[i].week<<endl;
        }
    }
}

//void searchAndScoreboard(vCourse &Score)
//{
//    cout<<"Enter course code of the course you wnat to view the attendance list: ";
//    string cc; cin>>cc;
//    int index = -1;
//    for(int i =0; i<Score.size(); i++)
//        if(Score[i].courseCode ==c)
//        {
//            index = i;
//            break;
//        }
//    if(index ==-1){
//        cout<<"There is no course with that course code !";
//        return ;
//    }
//    for(int i = 0; i<Score.size(); i++)
//    {
//        cout<<
//        cout<<endl;
//    }
//}
