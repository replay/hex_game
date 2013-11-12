#include "./field.h"

Field::Field() {
}

void Field::use_field(int player, char symbol) {
  this->_symbol = symbol;
  this->_owner = player;
}

char Field::get_symbol() {
  return this->_symbol;
}

int Field::get_owner() {
  return this->_owner;
}

bool Field::is_empty() {
  if (this->_owner == 0)
    return true;
  return false;
}

std::ostream& operator<< (std::ostream& os, Field& field) {
  return os << field.get_symbol();
}
