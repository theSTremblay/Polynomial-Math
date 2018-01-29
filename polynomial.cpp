#include "polynomial.hh"
#include <stdio.h>

Node::Node() {

}

Node::Node(double v, Node* n) { /*Your code goes here */ 
	value = v;
	next = n;
}

//Write in cooridnation with the poly constructor

Node* Poly::getHead() { /*Change code below*/
	//node_pointer = *(base_node_pointer);

	return &(node_pointer);
} 
Poly::Poly() {
	/*Your code goes here*/

	/*Node starter_Node(0, 0);*/

	node_pointer.value = 0;
	node_pointer.next = 0;

	base_node_pointer = &(node_pointer);

	changing_node_pointer = &( node_pointer);
}

void Poly::append(double v) { /*Your code goes here */
	Poly p_copy;

	p_copy.node_pointer = node_pointer;
	changing_node_pointer = &(node_pointer);


	while (changing_node_pointer->next != 0) {
		changing_node_pointer = (changing_node_pointer->next);
	}

	changing_node_pointer->next = (new Node(v, 0));

	node_pointer = *(base_node_pointer);

}

void Poly::print() {
	Node* temp = getHead(); while (temp != 0) {
		printf("%.2f", temp->value); temp = temp->next;
	}
}

int Poly::getDegree(Poly p1) {
	int counter = 0;
	Node *node1_pointer;
	node1_pointer = (p1.getHead());
	while (node1_pointer->next != 0) {
		counter++;
		node1_pointer = (node1_pointer->next);
	}
	counter++; // If there are two nodes it will give you a value of 2

	return counter;

}