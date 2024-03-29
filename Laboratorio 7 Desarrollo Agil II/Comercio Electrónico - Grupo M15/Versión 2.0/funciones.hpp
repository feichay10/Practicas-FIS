#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>      // std::setw
#include <math.h>       // std::roundf
#include "product.hpp"
#include "perfil.hpp"
#include "client.hpp"
//#include "client.hpp"

#pragma once

#define ENTER 10        //'\u000D'  // 13
#define BACKSPACE  127  //'\u0008'  // 8
#define INTENTOS 3

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::remove;
using std::roundf;
//using CONIO::getch;

// Prototipos de funciones
void pressAnyKey();       // Pulsar tecla para continuar
void pressAnyKeyClear();  // Pulsar tecla para continuar y limpiar pantalla
void readPassword(int&, string&);  // FUNCIÓN: Leer contraseña con asteríscos '*'
void menu();
void pagar(vector<product> &carrito);
void publicarProducto(vector<vector<product>> &);
void buscarProducto(vector<product>&, vector<vector<product>>&);
void catalogo(vector<vector<product>>, vector<product>&);
void CreaCatalogo(vector<vector<product>> &);
void opciones();
void categoria();
void mostrarCategoria(const int&);
bool verCarrito(vector<product>&);
void listaDeseos(vector<product>&, product);
void editarPerfil(Perfil&);
void historialCompra(vector<product>);
void estadisticas();
void agregarSaldo();
void ProductoEncontrado(vector<product> &, product);
bool cerrarSesion(vector<product>&, vector<product>&);
void introducirOpcion();
void readPassword(int&, string&);  // Ocultar entrada de password
char readch();
