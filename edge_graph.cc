#include "./edge_graph.h"

EdgeGraph::EdgeGraph(const int board_size)
  : _board_size(board_size){}

void EdgeGraph::add_edges(int player, int src_f,
  std::list<int>& connect_fields) {
  
  for (auto i: connect_fields) {
    this->add_edge(player, src_f, i);
  }
}

void EdgeGraph::add_edge(int player, int f1, int f2) {

  std::cout << "player: " << player << " adding edge: " << f1 << ":" << f2 << std::endl;
  this->_edges[player][f1].push_back(f2);
  this->_edges[player][f2].push_back(f1);
}

bool EdgeGraph::fields_are_connected(std::pair<int, int>) {
  return false;
}
