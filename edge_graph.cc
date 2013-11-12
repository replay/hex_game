#include "./edge_graph.h"

EdgeGraph::EdgeGraph(const int board_size, std::vector<Field>& fields)
  : _board_size(board_size),
    _fields(fields) {}

void EdgeGraph::update_edges(int field, Player* player) {
  std::vector<int> adjacent_fields;
  
  HexBoard::get_adjacent_fields(field, this->_board_size, adjacent_fields);

  for (auto i: adjacent_fields)
    if (_fields[i].get_symbol() == player->get_symbol()) {
      _edges[player][field].push_back( i );
      _edges[player][i].push_back( field );
    }
}
