/*
 * Graph.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: ubuntu
 */

#include <iostream>

#include "Graph.h"

void Graph::addOneWay(int id, std::unordered_set<int32_t> connectedNodeIds) {
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

void Graph::print() {
	for (auto const& [id, node] : index) {
		std::cout << "The node with id " << id << " has the following neighbors: " << std::endl;

		for (Node* n : node->connectedNodes) {
			std::cout << "\t - " << n->id << std::endl;
		}
	}
}

std::list<Node*> Graph::sortTop() {
	std::list<Node*> l;

	return l;
}

std::list<Node*> Graph::walkDFS(int32_t startNodeId) {
	std::list<Node*> l;
	std::cout << "Creating a visited array with size " << index.size() + 1 << std::endl;
	std::unordered_set<int32_t> visited;

	walkDFS(startNodeId, l, visited);

	return l;
}

void Graph::walkDFS(int32_t current, std::list<Node*>& path, std::unordered_set<int32_t>& visited) {
	if (index[current] == nullptr || visited.find(current) != visited.end()) {
		return;
	}


	visited.insert(current);

	for (Node* n : index[current]->connectedNodes) {
		walkDFS(n->id, path, visited);
	}

	path.push_back(index[current]);
}
