#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "perfil.hpp"
#include "product.hpp"
//#include "conio.h"
//#include "main.cpp"
#include "funciones.hpp"
//main.cppreadPassword();

class Client {
private:
  std::vector<Perfil> perfiles_;

public:
  Client();
  Client(Perfil perfil);
  ~Client();

  bool Login();
  bool Logout();
  void Register();
  void AddBalance(Perfil perfil);
};
