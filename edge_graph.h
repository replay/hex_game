#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <vector>
#include <map>

#include "./field.h"

class EdgeGraph {
  private:
    const int _board_size;
    std::vector<Field>& _fields;
    std::map<int, std::map< int, std::vector< int > > > _edges;

  public:
    EdgeGraph(const int, std::vector<Field>&);
    void update_edges(int, int, std::vector<int>&);
    void add_edge(int, int, int);
};

#endif  // EDGE_GRAPH_H_
