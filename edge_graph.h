#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <vector>
#include <map>

#include "./field.h"

class EdgeGraph {
  private:
    const int _board_size;
    std::vector<Field>& _fields;
    std::map<Field::colors, std::map< int, std::vector< int > > > _edges;
    void _add_edges(int, int, Field::colors);
    void _surrounding_hexagon(int, std::vector< std::pair<int, bool> >&);
  public:
    EdgeGraph(const int, std::vector<Field>&);
    void update_edges(int, Field::colors);
    bool find_path(int, int, Field::colors);
};

#endif  // EDGE_GRAPH_H_