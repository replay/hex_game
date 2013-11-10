#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>

class Field {

  public:
    enum colors { EMPTY, WHITE, BLACK };
    Field();
    colors get_color();
    void set_color(Field::colors);

  private:
    Field::colors _color;
};

std::ostream& operator<< (std::ostream&, Field&);

#endif  // FIELD_H_
