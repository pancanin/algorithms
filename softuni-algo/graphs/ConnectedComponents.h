/*
 * ConnectedComponents.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ubuntu
 */

#ifndef SOFTUNI_ALGO_GRAPHS_CONNECTEDCOMPONENTS_H_
#define SOFTUNI_ALGO_GRAPHS_CONNECTEDCOMPONENTS_H_

#include <unordered_map>
#include <vector>

#include "Node.h"

class ConnectedComponents {
public:
	ConnectedComponents() = default;

	void init(int nodesCount);
	void add(int id, std::vector<int> connectedNodeIds);
	void print();
	void deinit();
	void visitNeighbours(int id);
	std::vector<int>& getVisitedOnCurrentWalk();
	std::vector<std::vector<int>> findConnectedComponents();
private:
	std::unordered_map<int, Node*> index;
	bool* visited;
	std::vector<int> visitedOnCurrentWalk;
	std::vector<std::vector<int>> allConnectedComponents;
};

#endif /* SOFTUNI_ALGO_GRAPHS_CONNECTEDCOMPONENTS_H_ */
