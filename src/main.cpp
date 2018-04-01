#include "data_struct.h"
#include "menu.h"
#include "screen.h"

User loginUser;
int currentScreen;

int main() {
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