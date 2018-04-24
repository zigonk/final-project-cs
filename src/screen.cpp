#include "screen.h"

void firstScreen(User &loginUser) {
  login(loginUser);
}

void showMenu(User &loginUser) {
  system("clear");
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
      system("clear");
      showRoleList(loginUser);
      break;
    }
    case 2:
    {
      system("clear");
      viewInfo(loginUser);
      break;
    }
    case 3:
    {
      system("clear");
      changePassword(loginUser);
      break;
    }
    case 4:
    {
      system("clear");
      logout(loginUser);
      break;
    }
  }
}
