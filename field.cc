#include "./field.h"

Field::Field() {
  status = choices::EMPTY;
}

Field::choices Field::get_status() {
  return status;
}

std::ostream& operator<< (std::ostream& os, Field& field) {
  switch (field.get_status()) {
    case Field::choices::EMPTY:
      return os << ".";
    case Field::choices::WHITE:
      return os << "X";
    case Field::choices::BLACK:
      return os << "O";
  }
  return os;
}
