#include "product.hpp"

product::product() {

}

product::~product() {
  product_ID = 0;
  price = 0;
  weight = 0;
  height = 0;
  width = 0;
  tags = "";
  name = "";
  
}

int product::get_ID() {
  return product_ID;
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

std::string
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

void product::set_tags(std::string t) {
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
  std::cout << "Dimensiones: " << std::endl;
  std::cout << "  Altura: " << get_height() << std::endl;
  std::cout << "  Anchura: " << get_width() << std::endl;
}