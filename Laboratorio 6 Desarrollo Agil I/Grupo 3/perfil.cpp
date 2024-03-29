#include "perfil.h"

int 
Perfil::get_id() {
  return ID_;
}

std::string 
Perfil::get_nick_name() {
  return nick_name_;
}

std::string
Perfil::get_password() {
  return password_;
}

std::string
Perfil::get_email() {
  return email_;
}

int 
Perfil::get_phone() {
  return phone_;
}

std::string 
Perfil::get_address() {
  return address_;
}

float
Perfil::get_wallet_balance() {
  return wallet_balance_;
}

void
Perfil::set_ID(int id) {
  ID_ = id;
}

void 
Perfil::set_nick_name (std::string n) {
  nick_name_ = n;
}

void 
Perfil::set_password(std::string n) {
  password_ = n;
}

void 
Perfil::set_email(std::string n) {
  email_ = n;
}

void 
Perfil::set_phone(int i) {
  phone_ = i;
}

void 
Perfil::set_address(std::string n) {
  address_ = n;
}

void 
Perfil::set_wallet_balance(float i) {
  wallet_balance_ = i;
}

Perfil::Perfil(){
  srand (time(NULL));
  ID_ = rand() % 9999;
  nick_name_ = "unknown";
  password_ = "unknown";
  email_ = "unknown";
  phone_ = 000000000;
  address_ = "unknown";
  wallet_balance_ = 0;
}

Perfil::Perfil(std::string nick_name, std::string password, std::string email, int phone, std::string address, float wallet_balance) {
  srand (time(NULL));
  ID_ = rand() % 9999;
  nick_name_ = nick_name;
  password_ = password;
  email_ = email;
  phone_ = phone;
  address_ = address;
  wallet_balance_ = wallet_balance;
}

void Perfil::EditPerfil() {
  int opcion;
  std::cout << "¿Qué desea editar?\n";
  std::cout << "1. Nombre de usuario\n";
  std::cout << "2. Contraseña\n";
  std::cout << "3. Email\n";
  std::cout << "4. Teléfono\n";
  std::cout << "5. Dirección\n";
  std::cout << "6. Saldo\n";
  std::cout << "7. Salir\n";
  do {
    switch (opcion) {
      case 1:
        std::cout << "Introduzca el nuevo nombre de usuario\n";
        std::cin >> nick_name_;
        break;
      case 2:
        std::cout << "Introduzca la nueva contraseña\n";
        std::cin >> password_;
        break;
      case 3:
        std::cout << "Introduzca el nuevo email\n";
        std::cin >> email_;
        break;
      case 4:
        std::cout << "Introduzca el nuevo teléfono\n";
        std::cin >> phone_;
        break;
      case 5:
        std::cout << "Introduzca la nueva dirección\n";
        std::cin >> address_;
        break;
      case 6:
        std::cout << "Introduzca el nuevo saldo\n";
        std::cin >> wallet_balance_;
        break;
      case 7:
        break;
      default:
        std::cout << "Introduzca una opción correcta\n";
    }
  }while(opcion < 1 || opcion > 7);
}

bool check_passwd(std::string passwd) {
  if (passwd == get_password()) {
    return true;
  } else {
    return false;
  }
}