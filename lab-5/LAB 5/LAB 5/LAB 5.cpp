// Graphs_Optimization.cpp: ���������� ����� ����� ��� ����������� ����������.
// --- main  
//     ��������� BFS � DFS 
#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int matrix[5][5] = {
		{ 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0 }
	};

	graph::AMatrix graph(5, (int*)matrix);
	std::cout << std::endl;
	std::cout << std::endl << "-- ������� ��������� " << std::endl;
	for (int i = 0; i < graph.n_vertex; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < graph.n_vertex; j++) std::cout << graph.get(i, j) << " ";
	};
	std::cout << std::endl;

	graph::AList list(graph);
	std::cout << std::endl;
	std::cout << std::endl << "-- ������ ������� ������ " << std::endl;
	for (int i = 0; i < list.n_vertex; i++)
	{
		std::cout << std::endl << i << ": ";
		for (int j = 0; j < list.size(i); j++) std::cout << list.get(i, j) << " ";
	}
	std::cout << std::endl;

	BFS b1(list, 0);
	std::cout << std::endl;
	std::cout << std::endl << "-- ����� � ������ " << std::endl;
	int k1;
	while ((k1 = b1.get()) != BFS::NIL) std::cout << k1 << " ";
	std::cout << std::endl;

	DFS b2(list);
	std::cout << std::endl;
	std::cout << std::endl << "-- ����� � ������� " << std::endl;
	for (int i = 0; i < list.n_vertex; i++) std::cout << b2.get(i) << " ";
	std::cout << std::endl;

	std::cout << std::endl << "�������������� ����������" << std::endl;
	for (std::vector <int>::iterator i(b2.topological_sort.begin()); i != b2.topological_sort.end(); ++i) std::cout << *i << ' ';
	std::cout << std::endl;

	system("pause");
	return 0;
}
