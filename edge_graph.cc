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


bool EdgeGraph::fields_are_connected(int player, std::pair<int, int> src_dst) {
  std::vector<bool> reachable(this->_board_size, false);

  this->_compute_reachable(player, src_dst.first, reachable);

  if (reachable[src_dst.second])
    return true;

  return false;
}


// compute all paths starting from src
void EdgeGraph::_compute_reachable(int player, int src, std::vector<bool>& reachable) {
  std::list<int> to_visit;

  // start with src
  to_visit.push_back(src);

  for (auto i: to_visit) {
    for (auto j: this->_edges[player][i]) {
      if (!reachable[j])
      {
        to_visit.push_back(j);
        reachable[j] = true;
      }
    }
  }
}

