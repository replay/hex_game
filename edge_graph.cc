#include "./edge_graph.h"


EdgeGraph::EdgeGraph() {}


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
  std::vector<bool> reachable(this->_edges.size(), false);

  // list of fields that should be visited
  std::list<int> checklist;

  // start with src
  checklist.push_back(src_dst.first);

  // iterate over the fields in checklist while all
  // connected nodes are being appended at the end of it
  for (auto i: checklist)
    for (auto j: this->_edges[i])
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
