#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <locale.h>
#include "graph.h"
using namespace std;


// ���� � ����������������� ����
Graph g,gr;

map<int, bool> used;
// ������������� ������ � ������ ���
vector<int> order, component;
// ������� ������ � �������
void dfs1(int v) {
	used[v] = true;
	std::map<int, std::set<int>> mem = (g.get_graph());
	std::set<int> gv = mem[v];
	
	for (int i = 0; i < gv.size(); i++) {
		
		int x = *std::next(gv.begin(), i);
		if (!used[x])
			dfs1(x);
	}
	order.push_back(v);//�����������
}
// ������� ������ � ������� �� ������������������ ����� � ����� ���
void dfs2(int v) {
	used[v] = true;
	component.push_back(v);

	std::map<int, std::set<int>> mem = (gr.get_graph());
	std::set<int> grv = mem[v];


	for (int i = 0; i < grv.size(); i++) {
		int x = *std::next(grv.begin(), i);
		if (!used[x])
			dfs2(x);
	}
}