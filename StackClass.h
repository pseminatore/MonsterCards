// Specification file for the DynIntStack class
#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
#include <iomanip>
#include <iostream>
#include "MonsterCard.h"


class DynCardStack {

	private:
	// Structure for stack nodes
		struct StackNode
		{
		MonsterCard card; // Value in the node
		StackNode *next; // Pointer to the next node
		int index;  //position of the card in the deck
		};
		StackNode *top;
	public:
	// Constructor
		DynCardStack();
	// Destructor
		~DynCardStack();
	// Stack operations
		void push(MonsterCard);
		MonsterCard pop(MonsterCard);
		bool isEmpty();
		void displayDeck();
};
#endif
