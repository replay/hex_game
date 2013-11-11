#include "./edge_graph.h"

EdgeGraph::EdgeGraph(const int board_size, std::vector<Field>& fields)
  : _board_size(board_size),
    _fields(fields) {}

void EdgeGraph::_find_edges(int field, Field::colors color) {
  std::vector< std::pair<int, bool> > checklist;
  std::vector< int > neighbour_fields;
  
  this->_surrounding_hexagon(field, checklist);

  for (auto i: checklist)
    if (i.second)
      if (_fields[i.first].get_color() == color)
        this->_add_edges(field, i.first, color);
}

void EdgeGraph::_surrounding_hexagon(
  int field, std::vector< std::pair<int, bool> >& checklist) {
  // adding all possible neighbours to checklist
  checklist.push_back(std::pair<int, bool>(field - _board_size, true));
  checklist.push_back(std::pair<int, bool>(field - _board_size + 1, true));
  checklist.push_back(std::pair<int, bool>(field + 1, true));
  checklist.push_back(std::pair<int, bool>(field + _board_size, true));
  checklist.push_back(std::pair<int, bool>(field + _board_size - 1, true));
  checklist.push_back(std::pair<int, bool>(field - 1, true));

  // field is on the left edge
  if (field % _board_size == 0) {
    checklist[4].second = false;
    checklist[5].second = false;
  }
  // field is on the right edge
  if ((field + 1) % _board_size == 0) {
    checklist[1].second = false;
    checklist[2].second = false;
  }
  // field is on the top edge
  if (field <= _board_size) {
    checklist[0].second = false;
    checklist[1].second = false;
  }
  // field is on the bottom edge
  if (field >= _board_size * (_board_size - 1)) {
    checklist[3].second = false;
    checklist[4].second = false;
  }
}

// add a bidirectional edge to the vertex of the current color
void EdgeGraph::_add_edges(int f1, int f2, Field::colors color) {
  _edges[color].push_back( std::pair<int, int>(f1, f2));
  _edges[color].push_back( std::pair<int, int>(f2, f1));
}
