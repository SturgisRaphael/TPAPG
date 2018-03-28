#!/bin/bash

for file in ../Test/BildeKrarup/[B-C]/*[0-9]
do
echo $file
./TPAPG $file
#cat $file.bub | head -n 1  | sed -E 's/\ /\n/g' | tail -n 1
done

for file in ../Test/BildeKrarup/*/*/*[0-9]
do
echo $file
./TPAPG $file
#cat $file.bub | head -n 1  | sed -E 's/\ /\n/g' | tail -n 1
done
