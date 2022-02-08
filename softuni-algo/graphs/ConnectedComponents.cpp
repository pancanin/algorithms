/*
 * ConnectedComponents.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: ubuntu
 */
#include <iostream>

#include "ConnectedComponents.h"

void ConnectedComponents::init(int nodesCount) {
	index.reserve(nodesCount);
	visited = new bool[nodesCount];
}

void ConnectedComponents::add(int id, std::vector<int> connectedNodeIds) {
	Node* newNode = new Node(id);

	index[id] = newNode;

	for (int nodeId : connectedNodeIds) {
		if (index.find(nodeId) == index.end()) {
			Node* newNode = new Node(nodeId);
			index[nodeId] = newNode;
		}

		index[id]->connectedNodes.push_back(index[nodeId]);
	}
}

void ConnectedComponents::print() {
	for (auto const& [id, node] : index) {
		std::cout << "The node with id " << id << " has " << (visited[id] ? "" : "not") << " been visited and has the following neighbours: " << std::endl;

		for (Node* n : node->connectedNodes) {
			std::cout << "\t - " << n->id << std::endl;
		}
	}
}

void ConnectedComponents::visitNeighbours(int id) {
	if (visited[id]) {
		return;
	}

	visited[id] = true;
	visitedOnCurrentWalk.push_back(id);

	for (Node* n : index[id]->connectedNodes) {
		visitNeighbours(n->id);
	}
}

std::vector<std::vector<int>> ConnectedComponents::findConnectedComponents() {
	for (auto const& [id, node] : index) {
		if (!visited[id]) {
			visitNeighbours(id);
			allConnectedComponents.push_back(visitedOnCurrentWalk);
			visitedOnCurrentWalk.clear();
		}
	}

	return allConnectedComponents;
}

std::vector<int>& ConnectedComponents::getVisitedOnCurrentWalk() {
	return visitedOnCurrentWalk;
}

void ConnectedComponents::deinit() {
	delete[] visited;
}
