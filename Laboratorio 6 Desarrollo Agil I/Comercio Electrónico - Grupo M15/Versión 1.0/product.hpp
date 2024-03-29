#include <iostream>
#include <string> 
#include <vector>

class product {

public:
  product();
  ~product();

  //getters
  int get_ID();
  float get_price();
  float get_weight();
  float get_height();
  float get_width();
  std::string get_tags();
  std::string get_name();
  std::string get_description();
  std::string get_creation_date();

  //setters
  void set_ID(int id);
  void set_price(float i);
  void set_weight(float i);
  void set_height(float i);
  void set_width(float i);
  void set_tags(std::string t);
  void set_name(std::string n);
  void set_description(std::string desc);
  void set_creation_date(std::string date);

  //funciones auxiliares/adicionales
  void show_details();

private:
  int product_ID;
  float price, weight, height, width;
  std::string tags, name, description, creation_date;

};