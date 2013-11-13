
# Mauro Stettler
#
# create filelist to be used as parameter for vi (a.k.a my IDE)
#
# example:
# file_list cc; vi ${FILES}
# file_list h; vi ${FILES}

function file_list() {
  FILES=""
  for i in main hex_game edge_graph hex_board field player human_player ascii_art types
  do
    FILES="${FILES} ${i}.${1}"
  done
  export FILES
};
