#pragma once

#include <vector>
#include "graph.h"
using namespace std;


// ������� ������ ��� - Strongly Connected Component
vector<vector<int>> find_scc(Graph graph);

// ������� ������ � �������
void dfs1(int v);

// ������� ������ � ������� �� ������������������ ����� � ����� ���
void dfs2(int v);