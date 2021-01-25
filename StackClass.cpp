#include "StackClass.h"


 DynCardStack::DynCardStack(){
	
 	top = nullptr;

 }

 DynCardStack::~DynCardStack()
 {

	StackNode *nodePtr = nullptr, *nextNode = nullptr;
	// Position nodePtr at the top of the stack.
 	nodePtr = top;

	// Traverse the list deleting each node.
	 while (nodePtr != nullptr)
	 {
	 	nextNode = nodePtr->next;
	 	delete nodePtr;
	 	nodePtr = nextNode;
	 }
 }

 // Member function push pushes the argument onto 
 // the stack. 
 void DynCardStack::push(MonsterCard cardIn)
 {
	 StackNode *newNode = nullptr; // Pointer to a new node

	 // Allocate a new node and store num there.
	 newNode = new StackNode;
	 newNode->card = cardIn;

	 // If there are no nodes in the list
	 // make newNode the first node.
	 if (isEmpty())
	 {
		 top = newNode;
		 newNode->next = nullptr;
	 }
	 else // Otherwise, insert NewNode before top.
	 {
		 newNode->next = top;
		 top = newNode;
	 }
 }

 // Member function pop pops the value at the top 
 // of the stack off, and copies it into the variable 
 // passed as an argument. 
MonsterCard DynCardStack::pop(MonsterCard cardOut)
{

	StackNode *temp = nullptr; // Temporary pointer
	// First make sure the stack isn't empty.
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else // pop value off top of stack
	{
		cardOut = top->card;
		temp = top->next; delete top;
		top = temp;
	}
	return cardOut;
}

// Member function isEmpty returns true if the stack 
// is empty, or false otherwise. 
bool DynCardStack::isEmpty()
{
	bool status;
	if (!top)
		status = true;
	else
		status = false;
	return status;
}

