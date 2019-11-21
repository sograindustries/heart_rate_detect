#!/bin/bash

g++ -I./src -o test src/estimate_hr.cc src/main.cc src/test_data.cc src/kernels.cc
