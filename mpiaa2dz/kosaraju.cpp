#pragma once
#include "kosaraju.h"
#include "timer.h"

// ���� � ����������������� ����
Graph g, gr;

map<int, bool> used;
// ������������� ������ � ������ ���
vector<int> order, component;

// ������� ������ ���
vector<vector<int>> find_scc(Graph graph) {
	vector<vector<int>> ans;

	// и���

	used.clear();
	g.clear();
	gr.clear();
	order.clear();
	component.clear();

	g = graph;
	gr = graph.get_transponated();

	for (const auto& p : g.vertices)
		used[p.first] = false;

	for (const auto& p : gr.vertices)
		used[p.first] = false;

	for (const auto& p : g.vertices)
		if (!used[p.first])
			dfs1(p.first);

	for (const auto& p : g.vertices)
		used[p.first] = false;

	for (const auto& p : gr.vertices)
		used[p.first] = false;

	
	std::reverse(order.begin(), order.end());

	for (int v : order) {
		if (!used[v]) {
			dfs2(v);
			if (component.size() > 1 || g.has_arc(v, v) )
				ans.push_back(component);
			component.clear();
		}
	}

	return ans;
}

// ������� ������ � �������
void dfs1(int v) {
	used[v] = true;

	std::vector<int> gv = g.vertices.at(v);

	for (int x : gv)
		if (!used[x])
			dfs1(x);
	order.push_back(v);
}

// ������� ������ � ������� �� ������������������ ����� � ����� ���
void dfs2(int v) {
	used[v] = true;
	component.push_back(v);

	std::vector<int> grv = gr.vertices[v];

	int grvs = grv.size();

	for (int x : grv)
		if (!used[x])
			dfs2(x);
}