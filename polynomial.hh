class Node {
public:
	double value; 
	Node* next;
	Node(double v, Node* n);
	Node::Node();

}; 

class Poly {
public:
	Node* getHead();
	Poly();
	void print();
	void append(double v);
	Node node_pointer;
	 Node * base_node_pointer;
	Node *changing_node_pointer;
	int getDegree(Poly p1);

};