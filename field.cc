#include "./field.h"

Field::Field() {
}

void Field::use_field(int player, char symbol) {
  this->_symbol = symbol;
  this->_owner = player;
}

char* Field::get_symref() {
  return &this->_symbol;
}

int Field::get_owner() {
  return this->_owner;
}

bool Field::is_empty() {
  if (this->_owner == -1)
    return true;
  return false;
}
