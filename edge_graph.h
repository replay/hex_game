#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <list>
#include <map>
#include <utility>

#include "./types.h"

class EdgeGraph {
  private:
    const int _board_size;
    edge_list_t _edges;

  public:
    EdgeGraph(const int);
    void add_edge(int, int, int);
    void add_edges(int, int, std::list<int>&);
    bool fields_are_connected(std::pair<int, int>);

};

#endif  // EDGE_GRAPH_H_
