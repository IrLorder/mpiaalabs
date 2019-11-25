#pragma once

#include "Library.h"

TEST_CASE("[SCC] Empty graph", "[find_scc]") {
	Graph g;

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ };

	CHECK(result == wanted);
}

TEST_CASE("[SCC] Singleton graph", "[find_scc]") {
	Graph g;
	g.add_vertex(0);

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ };

	CHECK(result == wanted);
}

TEST_CASE("[SCC] Singleton graph with a loop", "[find_scc]") {
	Graph g;
	g.add_vertex(0);
	g.add_arc(0, 0);

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ {0} };

	CHECK(result == wanted);
}

TEST_CASE("[SCC] SCC in a disconnected graph", "[find_scc]") {
	Graph g;

	g.add_arc(0, 1);
	g.add_arc(1, 2);
	g.add_arc(2, 3);
	g.add_arc(3, 4);
	g.add_arc(4, 5);
	g.add_arc(5, 6);
	g.add_vertex(7);

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ };

	CHECK(result == wanted);
}

TEST_CASE("[SCC] SCC in a graph with loops", "[find_scc]") {
	Graph g;
	g.add_arc(0, 1);
	g.add_arc(1, 2);
	g.add_arc(2, 0);
	g.add_arc(1, 3);
	g.add_arc(3, 4);
	g.add_arc(4, 5);
	g.add_arc(5, 3);
	
	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ { 0, 2, 1 }, { 3, 5, 4 } };

	CHECK(result == wanted);
}

TEST_CASE("[SCC] Graph with negative vertices", "[find_scc]") {
	Graph g;
	g.add_arc(-1, -999);
	g.add_arc(-2, -5);
	g.add_arc(-5, -1);
	g.add_arc(-999, -2);

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ { -999, -1, -5, -2 } };
	
	CHECK(result == wanted);
}

TEST_CASE("[SCC] Graph with many loops", "[find_scc]") {
	Graph g;
	g.add_vertex(-1);
	g.add_arc(0, 1);
	g.add_arc(1, 2);
	g.add_arc(2, 0);
	g.add_arc(3, 1);
	g.add_arc(3, 4);
	g.add_arc(4, 5);
	g.add_arc(5, 3);
	g.add_arc(4, 6);
	g.add_arc(6, 7);
	g.add_arc(7, 8);
	g.add_arc(8, 6);
	g.add_arc(7, 0);

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ { 3, 5, 4 }, { 6, 8, 7 }, { 0, 2, 1 } };

	CHECK(result == wanted);
}

TEST_CASE("[SCC] The large graph", "[find_scc]") {
	Graph g; 
	g.add_arc(1, 2);
	g.add_arc(2, 3);
	g.add_arc(3, 4);
	g.add_arc(4, 5);
	g.add_arc(10, 10);
	g.add_arc(10, 11);
	g.add_arc(11, 11);
	g.add_arc(5, 6);
	g.add_arc(6, 7);
	g.add_arc(7, 8);
	g.add_arc(8, 9);
	g.add_arc(9, 1);
	g.add_arc(12, 13);
	g.add_arc(13, 12);
	g.add_arc(12, 13);
	g.add_arc(13, 12);
	g.add_arc(14, 14);
	g.add_arc(14, 15);
	g.add_arc(15, 15);
	g.add_arc(15, 17);
	g.add_arc(17, 16);
	g.add_arc(16, 15);
	g.add_arc(16, 17);
	g.add_arc(17, 18);
	g.add_arc(18, 19);
	g.add_arc(19, 19);
	g.add_arc(20, 19);
	g.add_arc(20, 21);
	g.add_arc(21, 22);
	g.add_arc(22, 23);
	g.add_arc(23, 19);
	g.add_arc(19, 24);
	g.add_arc(19, 14);
	g.add_arc(24, 25);
	g.add_arc(25, 25);
	g.add_arc(26, 25);
	g.add_arc(25, 26);
	g.add_arc(27, 26);
	g.add_arc(26, 27);
	g.add_arc(27, 28);
	g.add_arc(28, 29);
	g.add_arc(29, 30);
	g.add_arc(30, 1);

	vector<vector<int>> result = find_scc(g);
	vector<vector<int>> wanted{ {14, 19, 18, 17, 15, 16}, {25, 26, 27}, {12, 13}, {10}, {11}, {1, 9, 8, 7, 6, 5, 4, 3, 2} };

	CHECK(result == wanted);
}