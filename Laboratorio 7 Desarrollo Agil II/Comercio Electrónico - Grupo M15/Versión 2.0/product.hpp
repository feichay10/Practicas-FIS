#pragma once

#include <iostream>
#include <string> 
#include <vector>

class product {

public:
  product();
  product(std::string, float, float, float, float, int, int);
  ~product();

  //getters
  int get_ID();
  int get_seller_ID();
  float get_price();
  float get_weight();
  float get_height();
  float get_width();
  int get_stock();
  int get_tags();
  std::string get_name();
  std::string get_description();
  std::string get_creation_date();

  // setters
  void set_ID(int id);
  void set_seller_ID(int id);
  void set_price(float i);
  void set_weight(float i);
  void set_height(float i);
  void set_width(float i);
  void set_stock(int i);
  void set_tags(int t);
  void set_name(std::string n);
  void set_description(std::string desc);
  void set_creation_date(std::string date);
  

  //funciones auxiliares/adicionales
  void show_details();

private:
  int tags, product_ID, seller_ID, stock = 0;
  float price, weight, height, width;
  std::string name, description, creation_date;

};