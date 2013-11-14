#!/bin/bash

MODULES="hex_game ascii_art hex_board field player_container player human_player edge_graph main"
OUTPUT_NAME="hex"
COMPILER="g++"
COMPILE_PARAMS="--std=c++11 -O0 -fprofile-arcs -ftest-coverage -c -ggdb"
LINKER_PARAMS="--std=c++11 -O0 -fprofile-arcs -ftest-coverage -ggdb -lgcov"

do_cmd()
{
  echo ${1}
  ${1} || exit
}

compile_cmd()
{
  echo "${COMPILER} ${COMPILE_PARAMS} -o ${1}.o ${1}.cc"
}

link_cmd()
{
  echo "${COMPILER} ${LINKER_PARAMS} -o ${1} ${2}"
}

MODULE_OBJECTS=""
for MODULE in ${MODULES}
do
  MODULE_OBJECTS="${MODULE_OBJECTS} ${MODULE}.o "
done

rm -f "${MODULE_OBJECTS}.o"
rm -f "${OUTPUT_NAME}"

for MODULE in ${MODULES}
do
  CMD=$(compile_cmd ${MODULE})
  do_cmd "${CMD}"
done

CMD="${COMPILER} ${LINKER_PARAMS} -o ${OUTPUT_NAME} ${MODULE_OBJECTS}"
do_cmd "${CMD}"

./${OUTPUT_NAME}
