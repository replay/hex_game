#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <list>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>

class EdgeGraph {
  private:
    std::vector<bool> _reachable;

    // a vector of edges for each field
    std::map< int, std::vector< int > > _edges;

  public:
    EdgeGraph();
    void add_edge(int, int);
    void add_edges(int, std::list<int>&);
    bool fields_are_connected(std::pair<int, int>);

};

#endif  // EDGE_GRAPH_H_
