#include "data_struct.h"
#include "menu.h"
#include "academic_roles.h"
#include "screen.h"


int main() {
  User loginUser;
  int currentScreen = 0;
  while (true) {
    switch (currentScreen) {
      case 0: 
      {
        firstScreen(loginUser);
        currentScreen = 1;
        break;
      }
      case 1: 
      {
        showMenu(loginUser);
        if (loginUser.username == "") currentScreen = 0;
        break;
      }
    }
  }
}