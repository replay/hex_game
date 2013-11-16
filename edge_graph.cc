#include "./edge_graph.h"


EdgeGraph::EdgeGraph() {}


// returns the key of the last element in _edges (biggest)
int EdgeGraph::_biggest_edge_key() {
  return this->_edges.rbegin()->first;
}

// add edges from src_f to each edge in connect_fields
void EdgeGraph::add_edges(int src_f, std::list<int>& connect_fields) {
  for (auto i: connect_fields)
    this->add_edge(src_f, i);
}


// create a simple edge between two fields
void EdgeGraph::add_edge(int f1, int f2) {
  this->_edges[f1].push_back(f2);
  this->_edges[f2].push_back(f1);
}


// checks if two given fields are connected
bool EdgeGraph::fields_are_connected(std::pair<int, int> src_dst) {

  // the additional 4 is for the virtual nodes on each edge of the board
  std::vector<bool> reachable(this->_biggest_edge_key(), false);

  // list of fields that should be visited
  std::queue<int> checklist;
  int src_check_node;

  // start with src
  checklist.push(src_dst.first);

  // iterate over the fields in checklist while all
  // connected nodes are being appended at the end of it
  while (!checklist.empty()) {

    // get and remove the first element in the checklist queue
    src_check_node = checklist.front();
    checklist.pop();

    for (auto dst_check_node: this->_edges[src_check_node]) {
      if (!reachable[dst_check_node])
      {
        // this node should be checked next
        checklist.push(dst_check_node);

        // we know this node is reachable and we don't need to check it anymore
        reachable[dst_check_node] = true;
      }
    }
  }

  // if dst is reachable we have found a winner
  if (reachable[src_dst.second])
    return true;

  return false;
}
