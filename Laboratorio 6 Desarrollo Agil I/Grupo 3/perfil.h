#pragma once

#include <string>
#include <iostream>

class Perfil {
private:
  int ID_;
  std::string nick_name_;
  std::string password_;
  std::string email_;
  int phone_;
  std::string address_;
  float wallet_balance_;

public:
  //getters
  int get_id();
  std::string get_nick_name();
  std::string get_password();
  std::string get_email();
  int get_phone();
  std::string get_address();
  float get_wallet_balance();

  // setters
  void set_ID(int id);
  void set_nick_name(std::string n);
  void set_password(std::string n);
  void set_email(std::string n);
  void set_phone(int i);
  void set_address(std::string n);
  void set_wallet_balance(float i);
  
  
  Perfil();
	Perfil(std::string nick_name, std::string password, std::string email, int phone, std::string adress, float wallet_balance);
  void EditPerfil();
  bool check_passwd(std::string passwd);
};
