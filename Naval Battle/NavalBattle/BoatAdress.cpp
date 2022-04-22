#include "BoatAdress.h"
/*
Node::Node(int v) {
	this->v = v;
	this->next = next;
}

int Node::getValue() {
	return v;
}

Node* Node::getNext() {
	return next;
}

void Node::setNetx(Node* next) {
	this->next = next;
}


BoatAdress::BoatAdress() {
	head = NULL;
	tail = NULL;
}

BoatAdress::BoatAdress(int v) {
	head = new Node(v);
	tail = head;
}

 BoatAdress::~BoatAdress() {
	delete head;
}

 bool BoatAdress::empt() {
	 return (head == NULL);
 }

 void BoatAdress::input_beginning(int v) {
	 Node* new_node = new Node(v);

	 new_node->setNetx(head);
	 head = new_node;
 }

 void BoatAdress::input_ending(int v) {
	 Node* new_node = new Node(v);

	 if (empt()) {
		 head = new_node;
		 tail = new_node;
	 }
	 else {
		 tail->setNetx(new_node);
		 tail = new_node;
	 }
 }

 int BoatAdress::len() {
	 if (empt()) {
		 return 0;
	 }

	 Node* h = head;
	 int lenn = 0;
	 do {
		 h = h->getNext();
		 lenn++;
	 } while (h);
 }

 bool BoatAdress::is_there(int v) {
	 Node* h = head;
	 while (h) {
		 if (h->getValue() == v) {
			 return true;
		 }

		 h = h->getNext();
	 }
	 return false;
 }

 void BoatAdress::del() {
	 if (!empt()) {
		 if (head->getNext() == NULL) {
			 head = NULL;
		 }
		 else if (head->getNext()->getNext() == NULL) {
			 head->setNetx(NULL);
		 }
		 else {
			 Node* prev_prev = head;
			 Node* prev = head->getNext();
			 Node* chain = head->getNext()->getNext();

			 while (chain) {
				 Node* aux = prev;
				 prev = chain;
				 prev_prev = aux;
				 chain = chain->getNext();
			 }
			 delete prev_prev->getNext();
			 prev_prev->setNetx(NULL);
			 tail = prev_prev;
		 }
	 }
 }

 */