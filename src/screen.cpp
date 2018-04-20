#include "screen.h"

void firstScreen(User &loginUser) {
  login(loginUser);
}

void showMenu(User &loginUser) {
  cout << "1. Show menu" << endl;
  cout << "2. View info" << endl;
  cout << "3. Change password" << endl;
  cout << "4. Logout" << endl;
  cout << "What do you want to do:" << endl;
  int number;
  cin >> number;
  switch (number) {
    case 1:
    {
      showRoleList(loginUser);
      break;
    }
    case 2:
    {
      viewInfo(loginUser);
      break;
    }
    case 3:
    {
      changePassword(loginUser);
      break;
    }
    case 4:
    {
      logout(loginUser);
      break;
    }
  }
}
