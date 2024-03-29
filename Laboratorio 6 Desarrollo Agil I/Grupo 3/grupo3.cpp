#pragma once

#include <string>
#include <cstdlib>
#include <time.h>

class Perfil {
private:
  int ID_;
  std::string nick_name_;
  std::string password_;
  std::string email_;
  int phone_;
  std::string adress_;
  float wallet_balance_;

public:
  Perfil();
	Perfil(std::string nick_name, std::string password, std::string email, int phone, std::string adress, float wallet_balance);
  void EditPerfil();
};
