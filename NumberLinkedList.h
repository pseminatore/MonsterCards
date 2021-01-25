#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include "MonsterCard.h"
class NumberList
{

	private:
	// Declare a structure for the list
		struct ListNode
		{
			MonsterCard card; // The value in this node
			struct ListNode *next; // To point to the next node
			int position;
		};

		ListNode *head; // List head pointer


	public:
	// Constructor
		NumberList();

 	// Destructor
		~NumberList();

	// Linked list

		void appendNode(MonsterCard);
		void deleteNode(int);
		void displayList() const;

};
#endif // NUMBERLIST_H
