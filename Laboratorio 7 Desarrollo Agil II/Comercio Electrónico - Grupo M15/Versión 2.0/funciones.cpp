#include "funciones.hpp"
#include "conio.h"      // getch

struct Descuento {
  string codigo;
  int discount;
  bool type;  // 1 - Porcentaje; 0 - Descuento Directo
};

// CLIENTE DE PRUEBA
Perfil cliente("Cheuk","Password","alu0101364544@ull.edu.es",674994131,"Desconocido",0.00);
Client clientes(cliente);
vector<product> carrito, historial, Deseos;
vector<string> categorias = {"Hogar", "Electronica", "Ropa", "Juguetes", "Vehiculos"};
extern bool RepMenu;

// Vector de descuentos
vector<Descuento> descuentos = {{"NAICOBO", 10, 0}, {"BORO", 30, 1}, {"FISULL", 100, 1}, {"FOLELE", 35, 0}, {"ESIT", 25, 1}};


void menu() {
  int opcion;
  bool flag = false;
  //vector<product> carrito, historial, Deseos;
  //Perfil cliente("Cheuk","Password","alu0101364544@ull.edu.es",674994131,"Desconocido",0.00);
  product prueba;
  vector<vector<product>> Catalogo;             //1.hogar, 2.electronica, 3.ropa, 4.juguetes, 5.Vehiculos
  CreaCatalogo(Catalogo);
  
  do {
      cout << "####### Grupo 15! ######" << endl << endl << endl
          << "--------------------Plataforma--------------------" << endl
          << "1. Iniciar sesión" << endl
          << "2. Registrarse" << endl
          << "0. Salir" << endl
          << "Introduzca una opción: ";

      cin >> opcion;

      switch (opcion) {
      case 1:
        flag = clientes.Login();
        break;
      case 2:
        clientes.Register();
        break;
      case 0:
        return;
        break;
      default:
        cout << "Opción no soportada" << endl;
      }
    } while (opcion < 0 || opcion > 2 || !flag);
    cout << endl;
  flag = false;
  do {
    if(!RepMenu){
      cout << "####### Grupo 15! ######" << endl << endl << endl
          << "--------------------Plataforma--------------------" << endl
          << "1. Publicar nuevo producto" << endl
          << "2. Buscar producto" << endl
          << "3. Ver carrito" << endl
          << "4. Ver lista de deseos" << endl
          << "5. Ver/Editar perfil" << endl
          << "6. Ver historial de compra" << endl
          << "7. Ver estadísticas" << endl
          << "8. Añadir saldo" << endl
          << "9. Cerrar sesión" << endl
          << "Introduzca una opción: ";

      cin >> opcion;

      switch (opcion) {
      case 1:
        cout << "Publicando el nuevo producto..." << endl;
        publicarProducto(Catalogo);
        break;
      case 2:
        cout << "Buscando el producto..." << endl;
        buscarProducto(carrito, Catalogo);
        break;
      case 3:
        cout << "Carrito" << endl;
        if (verCarrito(carrito)) {
          //pago(historial)
          //~carrito()
        } else {
          //menu para modificar carrito
        }
        break;
      case 4:
        cout << "Lista de deseos" << endl;
        listaDeseos(Deseos, prueba);
        break;
      case 5:
        cout << "Perfil" << endl;
        editarPerfil(cliente);
        //correcto
        break;
      case 6:
        cout << "Historial de compra" << endl;
        historialCompra(historial);
        break;
      case 7:
        cout << "Estadísticas" << endl;
        estadisticas();
        break;
      case 8:
        cout << "Añadiendo saldo..." << endl;
        agregarSaldo();
        break;
      case 9:
        cout << endl << "_____Cerrando sesion_____" << endl;
        flag = cerrarSesion(carrito, historial);
        if(!flag) {
          RepMenu = true;
        }
        //correcto
        break;
      default:
        cout << "Opción no soportada" << endl;
      }
    }
  } while (opcion != 9);
  cout << endl;
}

void publicarProducto(vector<vector<product>> &catalogo) {

   //id = size del vector
  product producto;
  string name, date;                                  // problema con descripcion, al añadir algun espacio el proximo bucle se convierte en infinito
  float precio, Peso, altura, ancho;
  int opcion, stock, category;

  cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
  cout << "Introduzca los datos del producto:" << endl
       << "    - Nombre: ";
  cin >> name;
  producto.set_name(name);
  cout << "    - Precio: ";
  cin >> precio;
  producto.set_price(precio);
  cout << "    - Peso(KG): ";
  cin >> Peso;
  producto.set_weight(Peso);
  cout << "    - Altura: ";
  cin >> altura;
  producto.set_height(altura);
  cout << "    - Ancho: ";
  cin >> ancho;
  producto.set_width(ancho);
  system("clear");
  for (unsigned i = 0; i < categorias.size(); i++) {
    cout << i+ 1 << ". " << categorias.at(i) << endl;
  }
  do{
    cout << "    - Categoria (1 - " << categorias.size() << "): ";
    cin >> category;
  } while(category <= 0 || (unsigned)category > categorias.size());
  
  producto.set_tags(category - 1);
  cout << "    - Stock: ";
  cin >> stock;
  producto.set_stock(stock);
  producto.set_seller_ID(cliente.get_id());
  //PRUEBA!!!
  /*cout << "    - Descripcion: ";
  scanf("%s", Descripcion);
  producto.set_description(Descripcion);*/

  do {
    system("clear");
    producto.show_details();
    cout << "Categoria: " << categorias.at(category - 1) << endl;
    cout << endl << "¿Esta de acuerdo con estos parametros, desea cambiarlos o desea cancelar?" << endl;
    cout << "1. Los datos están correctos" << endl;
    cout << "2. Cambiar parametros" << endl;
    cout << "3. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;
  } while (opcion < 1 || opcion > 3);

  if (opcion == 1) {
    cout << "Añadiendo al catálogo" << endl;
    catalogo.at(category - 1).push_back(producto);
    cliente.num_product_add1();
    getchar();
  } else if (opcion == 2) {
    publicarProducto(catalogo);
  } else {
    cout << "Acción cancelada" << endl;
    getchar(); 
  }  

}

//Terminado Entrega1
void catalogo(vector<vector<product>> catalogo, vector<product> &carrito) {
  int opcion, anadir, size, producto;
  
  do{
    system("clear");
    cout << "Seleccione la categoria a la que desea acceder:" << endl;
    for (unsigned i = 0; i < categorias.size(); i++) {
      cout << i+1 << ". " << categorias.at(i) << endl;
    }
    cout << "opcion: ";
    cin >> opcion;
    system("clear");

    cout << "Categoria: " << categorias.at(opcion - 1) << endl << endl;
      size = catalogo.at(opcion - 1).size();
      for (int i = 0; i < size; i++) {
        cout << i+1 << ". " << catalogo.at(opcion - 1).at(i).get_name() << ": " << catalogo.at(opcion - 1).at(i).get_price() << " €" << endl;
      }
      do {
      cout << "¿Desea añadir al carrito algo que haya visualizado?" << endl;
      cout << "1. añadir algun producto" << endl;
      cout << "2. Volver al menu principal" << endl;
      cin >> anadir;
      } while (anadir < 1 || anadir > 2);
      if(anadir == 1) {
        do{
          cout << "Introduzca el ID del producto: ";
          cin >> producto;
        } while (producto <= 0 || producto > size);
        if(catalogo.at(opcion - 1).at(producto-1).get_stock() > 0){
          carrito.push_back(catalogo.at(opcion - 1).at(producto-1));
        } else {
          cout << "No quedan productos en Stock" << endl;
        }
      } else {
        pressAnyKeyClear();
      }
  } while (opcion <= 0 || (unsigned)opcion > categorias.size());
}

void CreaCatalogo(vector<vector<product>> &catalogo) {
  std::vector<product> Casa;
  std::vector<product> Electronica;
  std::vector<product> ropa;
  std::vector<product> Juguetes;
  std::vector<product> Vehiculos;
  
  catalogo.push_back(Casa);
  catalogo.push_back(Electronica);
  catalogo.push_back(ropa);
  catalogo.push_back(Juguetes);
  catalogo.push_back(Vehiculos);
}

// Terminado Entrega1
void categoria() {
 /* int categoria;
  do {
    cout << "Selecciona una categoria: " << endl
         << "1. Informática y Electronica" << endl
         << "2. Moda y accesorios" << endl
         << "3. Inmobiliaria" << endl
         << "4. Deporte y ocio" << endl
         << "5. Electrodomésticos" << endl
         << "6. VOLVER A" << endl;
    cin >> categoria;
    switch (categoria) {
      case 1:
        mostrarCategoria(categoria);
        break;
      case 2:
        mostrarCategoria(categoria);
        break;
      case 3:
        mostrarCategoria(categoria);
        break;
      case 4:
        mostrarCategoria(categoria);
        break;
      case 5:
        mostrarCategoria(categoria);
        break;
      case 6:
        cout << "Saliendo de Ver Categorías" << endl;
        break;
      default:
        cout << endl;
    }
  } while (categoria != 6);*/
}

/*
void opciones() {

}
*/

//Terminado Entrega1
void mostrarCategoria(const int& cat) {
  cout << "Nº categoría seleccionada: " << cat << endl;
}

//Terminado Entrega1
void buscarProducto(vector<product> &carrito, vector<vector<product>> &catalog) {

  string articulo;
  product producto;
  int size, opcion;
  do{
    cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
    cout << "¿Desea buscar por nombre o visualizar catalogo?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Catalogo" << endl;
    cout << "opcion: ";
    cin >> opcion;
    system("clear");
  } while (opcion < 1 || opcion > 2);
  
  if (opcion == 1) {
    cout << "Busque un artículo: " << endl;
    cin >> articulo;
    for (int i = 0; i < 5; i++) {
      size = catalog.at(i).size();
      for (int j = 0; j < size; j++) {
        if (articulo == catalog.at(i).at(j).get_name()) {
          producto = catalog.at(i).at(j);
          ProductoEncontrado(carrito, producto);
          return;
        }
      }
    }
    cout << "Articulo no encontrado" << endl;
  } else {
    catalogo(catalog, carrito);
  }
}

void ProductoEncontrado(vector<product> &carrito, product producto){
  int opt;
  do{
    cout << "¿Dese añadir el articulo al carrito?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "- " << producto.get_name() << ": " << producto.get_price() << " €" << endl;
    cout << "opcion: ";
    cin >> opt;
    system("clear");
  } while (opt < 1 || opt > 2);
  if (opt == 1) {
    if (producto.get_stock() > 0) {
      carrito.push_back(producto);
      cout << "Producto añadido" << endl;
    } else {
      cout << "No quedan productos en Stock" << endl;
      pressAnyKeyClear();
    } 
  } else{
    cout << "Producto no añadido" << endl;
  }
}

// Oculta la entrada del password
// void readPassword(char frase[]) {
//   int i = 0;
//   cout.flush();

//   do {
//     frase[i] = (unsigned char)getchar();

//     if (frase[i]!=8) {  // no es retroceso
//       cout << '*';  // muestra por pantalla
//       i++;
//     } else if (i > 0) {   // es retroceso y hay caracteres
//       cout << (char)8 << (char)32 << (char)8;
//       i--;  //el caracter a borrar e el backspace
//     }
//     cout.flush();
//   } while (frase[i-1] != 13);  // si presiona ENTER

//     frase[i-1] = (char)NULL;
//     cout << endl;
// }

// FUNCIÓN: Leer contraseña con asteríscos '*'
void readPassword(int &caracter, string &password) {
  while (caracter != ENTER) {
    // cout << "Caracter leído: " << caracter << endl;
    if (caracter != BACKSPACE) {
      password.push_back((char)caracter);
      cout << "*";
    } else {
      if (password.length() > 0) {
        cout << "\b \b";
        password = password.substr(0, password.length() - 1);
      }
    }
    caracter = getch();
  }
}


void pagar(vector<product> &carrito) {
  int opcion, phone, IDdesc = 0;
  int caracter;  // Variable para leer password caracter a caracter
  float subtotal = 0.00, total = 0.00;
  long tarjeta;
  string codigo, titular, fecha_cad, cvc, usuario, password, pin;
  bool anadir_descuento{false};
  
  // Comprobar STOCK de los productos del carrito
  for (unsigned i = 0; i < carrito.size(); i++) {
    if (carrito[i].get_stock() <= 0) {
      cout << endl << "\t(!) El producto " << carrito[i].get_name() << " ha sido eliminado por falta de stock!" << endl << endl;
      carrito.erase(carrito.begin() + i);
    }
  }

  system("clear");

  // Comprobamos si el carrito está vacío
  if (carrito.size() == 0) {
    cout << endl << "\t(!) Su carrito está vacío." << endl << endl;
    pressAnyKeyClear();
    return;
  }

  // vector<Descuento> descuentos = {{"NAICOBO", 10, 0}, {"BORO", 30, 1}, {"FISULL", 100, 1}, {"FOLELE", 35, 0}, {"ESIT", 25, 1}};

  do {
    cout << "¿Quiere añadir un cupón? (1 -Si/0 -No): ";
    cin >> anadir_descuento;
    if (anadir_descuento) {
      cout << endl
           << "\t¡AVISO! Solo se permite un cupón por compra, si añade un segundo cupón se eliminará el primero." << endl << endl
           << "Introduzca el código del descuento: ";
      cin >> codigo;
      for (unsigned i = 0; i < descuentos.size(); i++) {
        if (codigo == descuentos[i].codigo) { // comprobar que el codigo de descuento existe
          IDdesc = i;
          if (descuentos[i].type) {
            cout << endl << "\t- Se ha aplicado el -" << descuentos[i].discount << "% al total de su compra!" << endl << endl;
          } else {
            cout << endl << "\t- Se ha aplicado -" << descuentos[i].discount << "€ al total de su compra!" << endl << endl;
          }
        }
      }
    } else {
      cout << endl << "\t- ¡ERROR! Código inválido. No se ha aplicado ningún descuento al total de su compra!" << endl << endl;
    }
  } while (anadir_descuento);

  do {
    system("clear");
    // cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
    cout << "Método de pago:" << endl;
    cout << "¿Tarjeta(1), PayPal(2), Bizum(3)?: ";
    cin >> opcion ;
  } while (opcion < 1 || opcion > 3);

  system("clear");

  switch (opcion) {
    case 1:
      cout << "*** PAGAR PAYPAL ***" << endl
           << "Nº Tarjeta: ";
      cin >> tarjeta;
      cout << "Titular de la tarjeta: ";
      cin >> titular;
      cout << "Fecha caducidad: ";
      cin >> fecha_cad;
      getch();
      cout << "Introduzca el codigo CVC: ";
      //cin >> ccv;
      caracter = getch();
      readPassword(caracter, cvc);
      break;

    case 2:
      cout << "*** PAGAR PAYPAL ***" << endl
           << "Introduzca el usuario: ";
      cin >> usuario;
      getch();
      cout << "Introduzca la contraseña: ";
      // cin >> password;
      caracter = getch();
      readPassword(caracter, password);
      //cout << endl << "Password: " << password << endl;
      break;

    case 3:
      cout << "*** PAGAR CON BIZUM ***" << endl
           << "Introduzca su número de telefono: ";
      cin >> phone;
      getch();
      cout << "Introduzca el PIN: ";
      //cin >> pin;
      caracter = getch();
      readPassword(caracter, pin);
      break;

    default:
      cout << "¡ERROR! Opción NO disponible!" << endl;
  }

  system("clear");

  cout << "***** ¡OPERACIÓN REALIZADA CON ÉXITO! *****" << endl << endl
       << "Resumen de su compra:" << endl << endl
       << left << setw(25) << "Producto"
       << left << setw(8)  << "Ud."
       << right << setw(10) << "Precio" << endl;

  for (unsigned i = 0; i < carrito.size(); i++) {
    cout << left << setw(25) << carrito.at(i).get_name() << left << setw(8) << 1 << right << setw(8) << carrito.at(i).get_price() << " €" << endl;
    //carrito.at(i).get_seller_ID();
    carrito[i].set_stock(carrito[i].get_stock() - 1);
    cliente.num_sell_add1();
    subtotal += carrito.at(i).get_price();
  }

  cout << "___________________________________________" << endl
       << "  Método de pago: " << opcion << endl
       //<< "Detalles: " <<  << endl
       << "  SubTotal: " << subtotal << " €" << endl;
  if (IDdesc != 0) {
    if (descuentos[IDdesc].type) {
      cout << "  Descuentos: -" << descuentos[IDdesc].discount << " %" << endl;
      total = roundf(subtotal - (descuentos[IDdesc].discount * subtotal / 100));
    } else {
      cout << "  Descuentos: -" << descuentos[IDdesc].discount << " €" << endl;
      total = roundf(subtotal - descuentos[IDdesc].discount);
    }
  } else {
    cout << "  Descuentos: 0.00 €" << endl;
  }
  if (total < 0.00)
    total = 0.00;
  cout << "  Total: " << total << " €" << endl;
  pressAnyKeyClear();
}


// int impar2(int odd,int r)
// {
//     if(r=odd/10){
//             r=r*2;
//             }if(r>9){
//                 r=r-9;
//             }
//     return(r);
// }
// int sumoddever(int r,int ever,int val,int s)
// {   if(s=ever/10){
//             s=s+s;
//             }
//     val=r+s;
//     return (val);
// }
// int validar(int val)
// {
//      if(val%10==0)
//         return 1;
//      return 0;
// }

bool verCarrito(vector<product> &carrito) {
  int opcion;
  int size = carrito.size();

  system("clear");

  cout << "Su carrito contiene los siguientes elementos:" << endl;
  for (int i = 0; i < size; i++) {
    cout << "\t- " << carrito.at(i).get_name() << endl;
  }

  // system("pause");
  // system("read");
  // Pulsar tecla para continuar
  pressAnyKey();

  do {
    // cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
    cout << endl << "¿Desea pagar(1) o volver al menu(2)?: ";
    cin >> opcion ;
  } while (opcion < 1 || opcion > 2);

  if (opcion == 1) {
    pagar(carrito);
    //std::cout << "Pago hecho" << std::endl;
    return true;
  } else {
    cout << "Volviendo al Menú Principal..." << endl;
    pressAnyKeyClear();
    return false;
  }
}

void listaDeseos(vector<product> &Deseo, product producto) {
  int size = Deseo.size();
  for (int i = 0; i < size; i++) {
    if (Deseo.at(i).get_ID() == producto.get_ID()) {
      cout << "El producto ya estaba en la lista" << endl;
      //cout << "Presione Enter para continuar..." << endl;
      //getchar();
      pressAnyKeyClear();
      break;
    }
  }
  Deseo.push_back(producto);
  cout << "Producto añadido con éxito a la lista de deseos" << endl;
  // cout << "Presione Enter para continuar..." << endl;
  // getchar();
  pressAnyKeyClear();
}

void editarPerfil(Perfil &cliente) {
  bool editar{false};
  cout << "**** Datos del perfil ****" << endl
       << endl
       << "Nombre: " << cliente.get_nick_name() << endl
       << "Correo electronico: " << cliente.get_email() << endl
       << "Telefono: " << cliente.get_phone() << endl
       << "Direccion: " << cliente.get_address() << endl
       << "Saldo: " << cliente.get_wallet_balance() << endl
       << "Nº de productos: " << cliente.get_num_product() << endl
       << "N º de ventas: " << cliente.get_num_sell() << endl
       << endl
       << "¿Desea editar el perfil? (0 - No, 1 - Sí) ";
  cin >> editar;

  if (editar) {
    std::string name, passwd, address;
    int phone, num_product, num_sell;
    float wallet;
    cout << "Nombre: ";
    cin >> name; 
    cliente.set_nick_name(name);
    cout << "Contraseña: ";
    cin >> passwd;
    cliente.set_password(passwd);
    cout << "Telefono: ";
    cin >> phone;
    cliente.set_phone(phone);
    cout << "Dirección: ";
    cin >> address;
    cliente.set_address(address);
    cout << "Saldo: ";
    cin >> wallet;
    cliente.set_wallet_balance(wallet);
    cout << "Nº de productos: ";
    cin >> num_product;
    cliente.set_num_product(num_product);
    cout << "Nº de ventas: ";
    cin >> num_sell;
    cliente.set_num_sell(num_sell);
    cout << endl;
  }
}

void historialCompra(vector<product> historial) {
  int suma = 0;
  int size = historial.size();
  cout << endl << "Su historial de compra es: " << endl;

  if (historial.empty()) {
    cout << "Aun no se ha adquirido ningun producto." << endl;
  } else {
    for (int i = 0; i < size; i++) {
      cout << "  - " << historial.at(i).get_name() << "   " << historial.at(i).get_price() << " €" << endl;
      suma = suma + historial.at(i).get_price();
    }

    cout << "Usted ha adquirido un total de " << size << " productos" << endl;
    cout << "Dinero total gastado: " << suma << "€" << endl;
    cout << "Presione Enter para continuar...." << endl;
    getchar();
  }
}

void estadisticas() {
    //Numero de productos vendidos, a la venta, saldo, dinero que ha ganado, ...
    cout << "*** Estadisticas ***" <<  endl
         << "\t- Nº Productos en Venta: " << cliente.get_num_product() << endl
         << "\t- Nº Ventas: " << cliente.get_num_sell() << endl << endl;
}

//Terminado Entrega1
void agregarSaldo() {
  cout << "Opción no disponible, vuelve a intentarlos mas tarde" << endl;
}

//Terminado Entrega1
bool cerrarSesion(vector<product> &carrito, vector<product> &historial) {
  if(!clientes.Logout()) {
    return false;
  } 
  return true;
}

void introducirOpcion() {
  cout << "Opción no disponible, vuelve a intentarlos mas tarde" << endl;
}

// FUNCIÓN: Pulsar tecla para continuar
void pressAnyKey() {
  cout << endl << "Presiona cualquier tecla para continuar...";
  getch();
  getch();
}

// FUNCIÓN: Pulsar tecla para continuar y limpia la pantalla
void pressAnyKeyClear() {
  cout << endl << "Presiona cualquier tecla para continuar...";
  getch();
  getch();
  system("clear");
}

// Función auz¡xiliar de getch() para client.cpp
char readch() {
  return getch();
}
