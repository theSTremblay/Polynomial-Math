#include "functions.hh"

Node Node_Creator(double v) {
	Node New_node(0, 0);
	return (New_node);
}




//int getDegree(Poly p1) {
//	int counter = 0;
//	Node *node1_pointer;
//	node1_pointer = (p1.getHead());
//	while (node1_pointer->next != 0) {
//		counter++;
//		node1_pointer = node1_pointer->next;
//	}
//	counter++; // If there are two nodes it will give you a value of 2
//	
//	return counter;
//
//}


Poly addPolynomials(Poly p1, Poly p2) { /* Change code below */
	Poly p;
	int true_max = 0;
	int polynomial_max1 = 0;
	int polynomial_max2 = 0;
	double added_value = 0;
	
	Node *node1_pointer;
	//node1_pointer = p1.getHead();
	polynomial_max1 = p1.getDegree(p1);
	polynomial_max2 = p2.getDegree(p2);
	
	Node *node2_pointer;
	//node2_pointer = p2.getHead();

	Node *Main_node_pointer;
	//Main_node_pointer = p.getHead();


	if (polynomial_max1 > polynomial_max2) {
		true_max = polynomial_max1;
	}
	else if(polynomial_max1 < polynomial_max2){
		true_max = polynomial_max2;
	}
	else {
		true_max = polynomial_max2;
	}

	while (true_max != 1) {
		added_value = 0;
		if (true_max <= polynomial_max1) {
			added_value += p1.node_pointer.next->value;
			if (p1.node_pointer.next != 0) {
				p1.node_pointer = *(p1.node_pointer.next);
			}
		}
		if (true_max <= polynomial_max2) {
			added_value += p2.node_pointer.next->value;
			if (p2.node_pointer.next != 0) {
				p2.node_pointer = *(p2.node_pointer.next);
			}
		}
		p.changing_node_pointer->value = added_value;
		if (true_max > 2) {
			p.changing_node_pointer->next = (new Node(0, 0));
			p.changing_node_pointer = (p.changing_node_pointer->next);
		}
		else {
			p.changing_node_pointer->next = 0;
		}
		true_max--;
	}



	return p;
}

Poly subtractPolynomials(Poly p1, Poly p2) {
	Poly p;
	int true_max = 0;
	int polynomial_max1 = 0;
	int polynomial_max2 = 0;
	double added_value = 0;

	Node *node1_pointer;
	//node1_pointer = p1.getHead();
	polynomial_max1 = p1.getDegree(p1);
	polynomial_max2 = p2.getDegree(p2);

	Node *node2_pointer;
	//node2_pointer = p2.getHead();

	Node *Main_node_pointer;
	//Main_node_pointer = p.getHead();


	if (polynomial_max1 > polynomial_max2) {
		true_max = polynomial_max1;
	}
	else if (polynomial_max1 < polynomial_max2) {
		true_max = polynomial_max2;
	}
	else {
		true_max = polynomial_max2;
	}

	while (true_max != 1) {
		added_value = 0;
		if (true_max <= polynomial_max1) {
			added_value += p1.node_pointer.next->value;
			if (p1.node_pointer.next != 0) {
				p1.node_pointer = *(p1.node_pointer.next);
			}
		}
		if (true_max <= polynomial_max2) {
			added_value -= p2.node_pointer.next->value;
			if (p2.node_pointer.next != 0) {
				p2.node_pointer = *(p2.node_pointer.next);
			}
		}
		p.changing_node_pointer->value = added_value;
		if (true_max > 2) {
			p.changing_node_pointer->next = (new Node(0, 0));
			p.changing_node_pointer = (p.changing_node_pointer->next);
		}
		else {
			p.changing_node_pointer->next = 0;
		}
		true_max--;
	}



	return p;
} 

Poly multiplyPolynomials(Poly p1, Poly p2) {
	Poly p;
	int true_max = 0;
	int true_max2 = 0;
	int variable_max = 0;
	int polynomial_max1 = 0;
	int polynomial_max2 = 0;
	double added_value = 0;

	Node *node1_pointer;
	//node1_pointer = p1.getHead();
	polynomial_max1 = p1.getDegree(p1);
	polynomial_max2 = p2.getDegree(p2);

	Node *node2_pointer;
	//node2_pointer = p2.getHead();

	Node *Main_node_pointer;
	//Main_node_pointer = p.getHead();



	// In this case just act like the true_max is a flag that stipulates which for loop gets what polynomials max degree
	if (polynomial_max1 > polynomial_max2) {
		true_max = 1;
	}
	else if (polynomial_max1 < polynomial_max2) {
		true_max = 0;
	}
	else {
		true_max = 1;
	}

	for (int i = 0; i < (polynomial_max1 + polynomial_max2); i++) {
		p.changing_node_pointer->next = (new Node(0, 0));
		p.changing_node_pointer = p.changing_node_pointer->next;

	}
	p.changing_node_pointer = &(p.node_pointer);

	p1.changing_node_pointer = &(p1.node_pointer);

	//multiplication happens on the highest degree
	for (int i = 1; i < polynomial_max1; i++) {
		added_value = 0;
		true_max = (polynomial_max1 - (i-1));
		p2.changing_node_pointer = &(p2.node_pointer);
		p.changing_node_pointer = &(p.node_pointer);
		for (int k = (polynomial_max1 - i); k < (polynomial_max1 -1); k++) {
			p.changing_node_pointer = p.changing_node_pointer->next;
		}
		/*p.changing_node_pointer = p.changing_node_pointer->next;*/
		if (p1.changing_node_pointer->next != 0) {
			added_value += p1.changing_node_pointer->next->value;
		}

		for (int j = 1; j < polynomial_max2; j++) {
			if (p2.changing_node_pointer->next != 0 ) {
				true_max2 = (polynomial_max2 - (j-1));
				variable_max = true_max - true_max2;
				if (variable_max < 0) {
					variable_max = ((-1) * (variable_max));
				}
				added_value *= p2.changing_node_pointer->next->value;



				p.changing_node_pointer->value = added_value + p.changing_node_pointer->value;
				if (i != (polynomial_max1 - 1) || j != (polynomial_max2 - 1) ){
					p.changing_node_pointer = p.changing_node_pointer->next;
				}
				else {
					p.changing_node_pointer->next = 0;
				}
			}
			if (p1.changing_node_pointer->next != 0) {
				p1.changing_node_pointer = p1.changing_node_pointer->next;
			}

		}

	}

	/*while (true_max != 0) {
		added_value = 0;
		if (true_max <= polynomial_max1) {
			added_value += p1.changing_node_pointer->value;
			if (p1.changing_node_pointer->next != 0) {
				p1.changing_node_pointer = (p1.changing_node_pointer->next);
			}
		}
		if (true_max <= polynomial_max2) {
			if (added_value != 0) {
				added_value *= p2.node_pointer.value;
			}
			else {
				added_value += p2.node_pointer.value;
			}
			if (p2.node_pointer.next != 0) {
				p2.node_pointer = *(p2.node_pointer.next);
			}
		}
		p.node_pointer.value = added_value;
		if (true_max > 1) {
			p.node_pointer.next = &(Node_Creator(added_value));
			p.node_pointer = *(p.node_pointer.next);
		}
		else {
			p.node_pointer.next = 0;
		}
	}

*/

	return p;
}