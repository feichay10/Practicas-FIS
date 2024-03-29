#include <iostream>
//#include "conio.h"
#include "funciones.hpp"

bool RepMenu = false;

int main() {
  do{
    RepMenu = false;
    menu();
  } while (RepMenu);
  return 0;
}

