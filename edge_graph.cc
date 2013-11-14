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
  // the additional 4 is for the virtual nodes on each edge of the board
  std::vector<bool> reachable(this->_board_size * this->_board_size + 4, false);

  // list of fields that should be visited
  std::list<int> checklist;

  // start with src
  checklist.push_back(src_dst.first);

  // iterate over the fields in checklist while all
  // connected nodes are being appended at the end of it
  for (auto i: checklist)
    for (auto j: this->_edges[player][i])
      if (!reachable[j])
      {
        // this node should be checked next
        checklist.push_back(j);

        // we know this node is reachable and we don't need to check it anymore
        reachable[j] = true;
      }

  // if dst is reachable we have found a winner
  if (reachable[src_dst.second])
    return true;

  return false;
}
