#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>

class Field {

  public:
    Field();
    void use_field(int, char);
    char* get_symref();
    int get_owner();
    bool is_empty();

  private:
    int _owner = -1;
    char _symbol = '.';
};

std::ostream& operator<< (std::ostream&, Field&);

#endif  // FIELD_H_
