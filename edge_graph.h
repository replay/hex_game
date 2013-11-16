#ifndef EDGE_GRAPH_H_
#define EDGE_GRAPH_H_

#include <list>
#include <queue>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>


// represents the graph of edges across the hex board
class EdgeGraph {
  private:
    std::vector<bool> _reachable;

    // a vector of edges for each node
    std::map< int, std::vector< int > > _edges;

    // returns the key of the last element in _edges (biggest)
    inline int _biggest_edge_key();

  public:
    EdgeGraph();

    void add_edges(int, std::list<int>&);
    void add_edge(int, int);

    bool fields_are_connected(std::pair<int, int>);

};

#endif  // EDGE_GRAPH_H_
