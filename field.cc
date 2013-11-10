#include "./field.h"

Field::Field() {
  _color = colors::EMPTY;
}

Field::colors Field::get_color() {
  return _color;
}

void Field::set_color(Field::colors color) {
  _color = color;
}

std::ostream& operator<< (std::ostream& os, Field& field) {
  switch (field.get_color()) {
    case Field::colors::EMPTY:
      return os << ".";
    case Field::colors::WHITE:
      return os << "X";
    case Field::colors::BLACK:
      return os << "O";
  }
  return os;
}
