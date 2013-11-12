#include "./field.h"

Field::Field() {
  this->_symbol = '.';
  this->_empty = true;
}

void Field::set_symbol(char symbol) {
  this->_symbol = symbol;
  std::cout << "field set to not empty " << std::endl;
  this->_empty = false;
}

char Field::get_symbol() {
  return this->_symbol;
}

bool Field::is_empty() {
  return this->_empty;
}

std::ostream& operator<< (std::ostream& os, Field& field) {
  return os << field.get_symbol();
}
