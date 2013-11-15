#include "./field.h"


Field::Field() {}


// a player uses this field
void Field::use_field(int player, char symbol) {
  this->_symbol = symbol;
  this->_owner = player;
}


// get reference to this field's symbol
char* Field::get_symref() {
  return &this->_symbol;
}


// get this field's current owner
int Field::get_owner() {
  return this->_owner;
}


// check if this field is already owned by somebody
bool Field::is_empty() {
  if (this->_owner == -1)
    return true;
  return false;
}
