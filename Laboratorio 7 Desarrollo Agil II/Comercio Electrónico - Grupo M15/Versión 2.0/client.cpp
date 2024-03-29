#include "client.hpp"
//#include "conio.h"

Client::Client() {}

Client::Client(Perfil perfil) {
  perfiles_.push_back(perfil);
}

Client::~Client() {}

bool Client::Login() {
  std::string username, password;
  int character;
  std::cout << "Introduce tu nombre de usuario:\n";
  std::cin >> username;
  std::cout << "Introduce tu contraseña:\n";
  //std::cin >> password;
  readch();
  character = readch();
  readPassword(character, password);
  for (unsigned i = 0; i < perfiles_.size(); i++) {
    if (perfiles_[i].get_nick_name() == username) {
      if (perfiles_[i].get_password() == password) {
        std::cout << endl << "Se ha iniciado sesión con éxito.\n";
        return true;
      } else {
        std::cout << endl << "Contraseña incorrecta.\n";
        return false;
      }
    }
  }
  std::cout << endl << "El usuario no ha sido encontrado.\n";
  return false;
}

bool Client::Logout(){
  int opcion;
  do {
    std::cout << endl << "1. Desea salir del programa" << endl;
    std::cout << "2. Desea cambiar de usuario" << endl;
    std::cout << "Opcion: ";
    std::cin >> opcion;
  } while (opcion < 1 || opcion > 2);
  if (opcion == 1) {
    return true;
  } else {
    return false;
  }
}

void Client::Register(){
  Perfil nuevo_usuario;
  std::string username, password;
  int character;
  std::cout << "Introduce tu nombre de usuario:\n";
  std::cin >> username;
  std::cout << "Introduce tu contraseña:\n";
  readch();
  character = readch();
  readPassword(character, password);
  nuevo_usuario.set_nick_name(username);
  nuevo_usuario.set_password(password);
  perfiles_.push_back(nuevo_usuario);
}

void Client::AddBalance(Perfil perfil){
  float balance;
  std::cout << "Indica la cantidad a añadir:\n";
  std::cin >> balance;
  std::vector<product> carrito = {{"Transferencia a su favor", balance, 0, 0, 0, 1, 1}};
  pagar(carrito);
}

// Iniciar sesión y registrarse y después mostrar menú