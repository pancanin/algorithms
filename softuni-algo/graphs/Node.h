/*
 * Node.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ubuntu
 */

#ifndef SOFTUNI_ALGO_GRAPHS_NODE_H_
#define SOFTUNI_ALGO_GRAPHS_NODE_H_

#include <vector>

struct Node {
	Node(int id): id(id) {}

	int id;
	std::vector<Node*> connectedNodes;
};


#endif /* SOFTUNI_ALGO_GRAPHS_NODE_H_ */
