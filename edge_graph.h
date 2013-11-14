#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <list>
#include <map>
#include <utility>
#include <algorithm>

#include "./types.h"

class EdgeGraph {
  private:
    const int _board_size;
    std::vector<bool> _reachable;

    // a vector of edges for each field
    typedef std::map< int, std::vector< int > > edges_t;
    //std::map< int, std::vector< int > > _edges;
    edges_t _edges;

  public:
    EdgeGraph(const int);
    void add_edge(int, int);
    void add_edges(int, std::list<int>&);
    bool fields_are_connected(std::pair<int, int>);

};

#endif  // EDGE_GRAPH_H_
