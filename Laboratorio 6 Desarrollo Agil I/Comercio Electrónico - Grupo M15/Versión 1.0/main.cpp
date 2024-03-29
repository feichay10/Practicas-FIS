#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "product.hpp"
#include "perfil.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Prototipos de funciones
void menu();
void publicarProducto();
void buscarProducto(vector<product>&);
void catalogo();
void opciones();
void categoria();
void mostrarCategoria(const int&);
bool verCarrito(vector<product>&);
void listaDeseos(vector<product>&, product);
void editarPerfil(Perfil&);
void historialCompra(vector<product>);
void estadisticas();
void agregarSaldo();
void cerrarSesion(vector<product>&, vector<product>&);
void introducirOpcion();

// CLIENTE DE PRUEBA
//Perfil cliente("Cheuk","Password","alu0101364544@ull.edu.es",674994131,"Desconocido",0.00);

int main() {
  menu();
  return 0;
}

void menu() {
  int opcion;
  vector<product> carrito, historial, Deseos;
  Perfil cliente("Cheuk","Password","alu0101364544@ull.edu.es",674994131,"Desconocido",0.00);
  product prueba;
  //vector catalogo (para almacenar productos);
  do {
    cout << "####### Grupo 1! ######" << endl << endl << endl
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
      publicarProducto();
      break;
    case 2:
      cout << "Buscando el producto..." << endl;
      buscarProducto(carrito);
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
      cerrarSesion(carrito, historial);
      //correcto
      break;
    default:
      cout << "Opción no soportada" << endl;
    }
  } while (opcion != 9);
  cout << endl;
}

void publicarProducto() {

  //id = size del vector
  product producto;
  string name, category, date;                                  // problema con descripcion, al añadir algun espacio el proximo bucle se convierte en infinito
  float precio, Peso, altura, ancho;
  int opcion;

  cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
  cout << "Introduzca los datos del producto:" << endl
       << "    - Nombre: ";
  cin >> name;
  producto.set_name(name);
  cout << "    - Precio: ";
  cin >> precio;
  producto.set_price(precio);
  cout << "    -Peso(KG): ";
  cin >> Peso;
  producto.set_weight(Peso);
  cout << "    - Altura: ";
  cin >> altura;
  producto.set_height(altura);
  cout << "    - Ancho: ";
  cin >> ancho;
  producto.set_width(ancho);
  cout << "    - Categoria: ";
  cin >> category;
  producto.set_tags(category);
  /*cout << "    - Descripcion: ";
  scanf("%s", Descripcion);
  producto.set_description(Descripcion);*/

  do{
  system("clear");
  producto.show_details();
  cout << endl << "¿Esta de acuerdo con estos parametros, desea cambiarlos o desea cancelar?" << endl;
  cout << "1. Los datos están correctos" << endl;
  cout << "2. Cambiar parametros" << endl;
  cout << "3. Cancelar" << endl;
  cout << "Opcion: ";
  cin >> opcion;
  } while(opcion < 1 || opcion > 3);

  if (opcion == 1) {
    cout << "Añadiendo al catálogo" << endl;
    //añadir a vector de vectores (catalogo)
    getchar();
  } else if (opcion == 2) {
    publicarProducto();
  } else {
    cout << "Accion cancelada" << endl;
    //no añadir al vector de vectores (catalogo)
    getchar(); 
  }
  

}

//Terminado Entrega1
void catalogo() {
  vector<string> catalogo{"Cubo","Queso","fregona","Aguacate"};
  int size = catalogo.size();
  for (int i = 0; i < size; i++) {
    cout << catalogo[i] << endl;
  }
}

// Terminado Entrega1
void categoria() {
  int categoria;
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
  } while (categoria != 6);
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
void buscarProducto(vector<product> &carrito) {
  cout << endl << "Version no disponible de momento" << endl;
  /*int opcion;
  string articulo;
  cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
  cout << "Busque un artículo: " << endl;
  do {
    cout << "Seleccione una opción: " << endl << endl
         << "1. Buscar por nombre" << endl
         << "2. Ver catálogo completo" << endl
         << "3. Ver categoría:" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "Introduzca el nombre del artículo: " << endl;
        cin >> articulo;
        break;
      case 2:
        cout << "Aqui tiene el catalogo completo: " << endl;
        catalogo();
        break;
      case 3:
        cout << "Las categorías que podemos encontrar son: ";
        categoria();
        break;
      default:
        cout << endl;
    }
  } while (opcion != 3);*/
  // Producto producto;
  // producto.articulo = articulo;
  // hash.insert(articulo);
}


bool verCarrito(vector<product> &carrito) {
  int opcion;
  int size = carrito.size();

  cout << "Su carrito contiene los siguientes elementos:" << endl;
  for (int i = 0; i < size; i++) {
    cout << carrito.at(i).get_name() << endl;
  }

  do {
    system("clear");
    cout << "¡ADVERTENCIA! Funcionalidad en fase beta. Puede no funcionar correctamente." << endl << endl;
    cout << "¿ Desea pagar(1) o volver al menu(2)?: ";
    cin >> opcion ;
  } while(opcion < 1 || opcion > 2);

  if(opcion==1){
    std::cout << "Pago hecho" << std::endl;
    return true;
  } else {
    std::cout << "Menu" << std::endl;  
    return false;   
  }
}

void listaDeseos(vector<product> &Deseo, product producto) {
  int size = Deseo.size();
  for (int i = 0; i < size; i++) {
    if (Deseo.at(i).get_ID() == producto.get_ID()) {
      cout << "El producto ya estaba en la lista" << endl;
      cout << "Presione Enter para continuar..." << endl;
      getchar();
      break;
    }
  }
  Deseo.push_back(producto);
  cout << "Producto añadido con exito a la lista de deseos" << endl;
  cout << "Presione Enter para continuar..." << endl;
  getchar();
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
       << endl
       << "¿Desea editar el perfil? (0 - No, 1 - Sí) ";
  cin >> editar;

  if (editar) {
    std::string name, passwd, address;
    int phone;
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
  cout << "Opción no disponible, vuelve a intentarlos mas tarde" << endl;
}

//Terminado Entrega1
void agregarSaldo() {
  cout << "Opción no disponible, vuelve a intentarlos mas tarde" << endl;
}

//Terminado Entrega1
void cerrarSesion(vector<product> &carrito, vector<product> &historial) {
  
}

void introducirOpcion() {
  cout << "Opción no disponible, vuelve a intentarlos mas tarde" << endl;
}