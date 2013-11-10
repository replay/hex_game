#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>

class Field {
  public:
    enum choices { EMPTY, WHITE, BLACK };
    Field();
    choices get_status();

  private:
    Field::choices status;
};

std::ostream& operator<< (std::ostream&, Field&);

#endif  // FIELD_H_
