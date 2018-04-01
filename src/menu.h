#ifndef _MENU_
#define _MENU_

#include "data_struct.h"

void login(User &loginUser);
void showRoleList(User loginUser);
void viewInfo(User loginUser);
void changePassword(User &loginUser);
void logout(User &loginUser);

#endif