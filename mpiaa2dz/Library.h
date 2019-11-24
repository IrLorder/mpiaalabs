#pragma once
#include <string>
#include <vector>
#include <conio.h>
#include <locale.h>
#include "graph.h"
using namespace std;


// ������� ������ ��� - Strongly Connected Component
vector<vector<int>> find_SCC(Graph graph);

// ������� ������ � �������
void dfs1(int v);

// ������� ������ � ������� �� ������������������ ����� � ����� ���
void dfs2(int v);

// ������� ��� ������ ���������� � ����
void result_to_file(vector<vector<int>> ans, const char* chars);