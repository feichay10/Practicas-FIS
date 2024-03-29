#include "product.hpp"

product::product() {

}

product::product(std::string n, float p, float we, float h, float wi, int t, int s) {
  name = n;
  price = p;
  weight = we;
  height = h;
  width = wi;
  tags = t;
  stock = s;
}

product::~product() {
  product_ID = 0;
  price = 0;
  weight = 0;
  height = 0;
  width = 0;
  tags = 1;
  name = "";
  
}

int product::get_ID() {
  return product_ID;
}

int product::get_seller_ID() {
  return seller_ID;
}

float
product::get_price() {
  return price;
}

float
product::get_weight() {
  return weight;
}

float
product::get_height() {
  return height;
}

float
product::get_width() {
  return width;
}

int 
product::get_stock() {
    return stock;
}

int
product::get_tags() {
  return tags;
}

std::string
product::get_name() {
  return name;
}

void
product::set_ID(int id) {
  product_ID = id;
}

void
product::set_seller_ID(int id) {
  seller_ID = id;
}

void
product::set_price(float i) {
  price = i;
}

void 
product::set_weight(float i) {
  weight = i;
}

void 
product::set_height(float i) {
  height = i;
}

void 
product::set_width(float i) {
  width = i;
}

void
product::set_stock(int i) {
    stock = i;
}

void product::set_tags(int t) {
  tags = t;
}

void product::set_name(std::string n) {
  name = n;
}

void
product::set_description(std::string desc) {
  description = desc;
}

void 
product::set_creation_date(std::string date) {
  creation_date = date;
}

void
product::show_details() {
  std::cout << "Detalles del producto: " << std::endl;
  std::cout << "Nombre: " << get_name() << std::endl;
  std::cout << "Precio: " << get_price() << std::endl;
  std::cout << "Peso: " << get_weight() << std::endl;
  std::cout << "Stock: " << get_stock() << std::endl;
  std::cout << "Dimensiones: " << std::endl;
  std::cout << "  Altura: " << get_height() << std::endl;
  std::cout << "  Anchura: " << get_width() << std::endl;
}