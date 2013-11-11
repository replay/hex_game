#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <vector>
#include <map>

#include "./field.h"

class EdgeGraph {
  private:
    const int _board_size;
    std::vector<Field>& _fields;
    std::map<Field::colors, std::vector< std::pair< int, int > > > _edges;
  public:
    EdgeGraph(const int, std::vector<Field>&);
    void _find_edges(int, Field::colors);
    void _add_edges(int, int, Field::colors);
    void _surrounding_hexagon(int, std::vector< std::pair<int, bool> >&);
};

#endif  // EDGE_GRAPH_H_
