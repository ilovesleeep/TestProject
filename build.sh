#!/bin/sh

cd src
make
rm *.o
mv test ../../