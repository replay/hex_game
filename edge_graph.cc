#include "./edge_graph.h"

EdgeGraph::EdgeGraph(const int board_size, std::vector<Field>& fields)
  : _board_size(board_size),
    _fields(fields) {}

bool EdgeGraph::find_path(int src, int dst, Field::colors color) {}

void EdgeGraph::update_edges(int field, Field::colors color) {
  std::vector<int> adjacent_fields;
  
  HexBoard::get_adjacent_fields(field, this->_board_size, adjacent_fields);

  for (auto i: adjacent_fields)
    if (_fields[i].get_color() == color)
      this->_add_edges(field, i, color);
}

// add a bidirectional edge to the vertex of the current color
void EdgeGraph::_add_edges(int f1, int f2, Field::colors color) {
  _edges[color][f1].push_back( f2 );
  _edges[color][f2].push_back( f1 );
}
