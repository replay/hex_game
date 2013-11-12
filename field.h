#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>

class Field {

  public:
    Field();
    void set_symbol(char);
    char get_symbol();
    bool is_empty();

  private:
    bool _empty;
    char _symbol;
};

std::ostream& operator<< (std::ostream&, Field&);

#endif  // FIELD_H_
