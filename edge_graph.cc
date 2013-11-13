#include "./edge_graph.h"

EdgeGraph::EdgeGraph(const int board_size)
  : _board_size(board_size){}

void EdgeGraph::add_edges(int player, int src_f,
  std::vector<int>& connect_fields) {
  
  for (auto i: connect_fields) {
    this->add_edge(player, src_f, i);
  }
}

void EdgeGraph::add_edge(int player, int f1, int f2) {
  this->_edges[player][f1].push_back(f2);
  this->_edges[player][f2].push_back(f1);
}
