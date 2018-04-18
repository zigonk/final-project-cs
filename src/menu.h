#ifndef _MENU_
#define _MENU_

#include "student_roles.h"
#include "lecturer_roles.h"
#include "academic_roles.h"

void login(User &loginUser);
void showRoleList(User &loginUser);
void viewInfo(User loginUser);
void changePassword(User &loginUser);
void logout(User &loginUser);

#endif