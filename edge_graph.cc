#include "./edge_graph.h"

EdgeGraph::EdgeGraph(const int board_size, std::vector<Field>& fields)
  : _board_size(board_size),
    _fields(fields) {}

void EdgeGraph::update_edges(int field, int player,
  std::vector<int>& adjacent_fields) {
  
  for (auto i: adjacent_fields)
    if (_fields[i].get_owner() == player) {
      _edges[player][field].push_back( i );
      _edges[player][i].push_back( field );
    }
}

void EdgeGraph::add_edge(int player, int f1, int f2) {
  this->_edges[player][f1].push_back(f2);
  this->_edges[player][f2].push_back(f1);
}
