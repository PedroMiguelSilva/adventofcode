#!/bin/bash
g++ sol2.cpp -o p2
rs=( 1 3 5 7 1 )
ds=( 1 1 1 1 2 )
C=1
for i in "${!rs[@]}"; do
  V=$(./p2 ${rs[$i]} ${ds[$i]} < in)
  C=$((C*V))
done
echo $C
