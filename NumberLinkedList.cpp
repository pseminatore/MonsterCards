#include "NumberLinkedList.h"
#include "MonsterCard.h"
#include <iostream>

NumberList::NumberList(){
   head=nullptr;
}

NumberList::~NumberList(){

}

void NumberList::appendNode(MonsterCard cardIn) {
	ListNode *newNode; 		// To point to a new node
	ListNode *nodePtr; 		// To move through the list

	// Allocate a new node and store card there.
	newNode = new ListNode;
	newNode->card = cardIn;
	newNode->next = nullptr;

    // If there are no nodes in the list
    // make newNode the first node.
    if (!head){

		head = newNode;
		newNode->position = 0;

	} else{ 	// Otherwise, insert newNode at end.
	
		// Initialize nodePtr to head of list.
		nodePtr = head;
        int nodeNum = 0;

		// Find the last node in the list.
		while (nodePtr != nullptr){
			nodePtr = nodePtr->next;
			nodeNum++;
		}

		// Insert newNode as the last node.
		nodePtr->next = newNode;
		newNode->position = nodeNum;
	}
}


void NumberList::deleteNode(int nodeNum) {

	ListNode *nodePtr; // To traverse the list
	ListNode *previousNode = nullptr; // The previous node

    // If there are no nodes in the list
    //make newNode the first node
	if (!head)
		return;
	// Determine if the first node is the one.
	if (head->position == nodeNum)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
	 	// not equal to num.
		while (nodePtr != nullptr && nodePtr->position != nodeNum)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		//Then, step through and adjust position values for rest of list
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
			nodePtr = previousNode->next;
			while (nodePtr != nullptr){
              nodePtr->position = nodePtr->position - 1;
              nodePtr = nodePtr->next;
			}
		}
	}
}

void NumberList::displayList() const {

    ListNode *nodePtr; // To move through the list
    // Position nodePtr at the head of the list.
    nodePtr = head;
    // While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{

		// Display the value in this node.
		cout << nodePtr->position<<". "<< nodePtr->card.Getname() << endl;
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}



