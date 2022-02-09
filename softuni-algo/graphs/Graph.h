/*
 * Graph.h
 *
 *  Created on: Feb 9, 2022
 *      Author: ubuntu
 */

#ifndef SOFTUNI_ALGO_GRAPHS_GRAPH_H_
#define SOFTUNI_ALGO_GRAPHS_GRAPH_H_

#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <list>

#include "Node.h"

class Graph {
public:
	void addOneWay(int id, std::unordered_set<int32_t> connectedNodeIds);
	void print();

	/* Algorithms */
	std::list<Node*> sortTop();

	std::list<Node*> walkDFS(int32_t startNodeId);
	std::vector<Node*> getIndependentNodes();
private:
	std::unordered_map<int32_t, Node*> index;

	void walkDFS(int32_t current, std::list<Node*>& path, std::unordered_set<int32_t>& visited);
};

#endif /* SOFTUNI_ALGO_GRAPHS_GRAPH_H_ */
