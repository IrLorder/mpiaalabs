#pragma once

#include "catch.hpp"
#include "graph.h"
#include "timer.h"
#include "kosaraju.h"
#include <conio.h>

using namespace std;

Graph gen_random_graph(int nodes, int arcs);

void measure(int nodes, int arcs);

// ������� ��� ������ ���������� � ����
void result_to_file(vector<vector<int>> ans, const char* chars);