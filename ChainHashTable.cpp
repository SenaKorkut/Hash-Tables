#include"ChainHashTable.h"
#include <string>

#include <iostream>

using namespace std;

ChainHashTable::ChainHashTable() {

	//entries = new EntryNode[TABLE_SIZE];

}

ChainHashTable::~ChainHashTable() {
	for ( int i = 0; i < TABLE_SIZE ;i++) {
		if (entries[i] != NULL ) {
			while( entries[i] != NULL) {
				EntryNode* toDelete = entries[i];
				entries[i] = entries[i]->next;
				delete toDelete;
			}
		}
	}

}

void ChainHashTable::insert(Entry* entry) {

	int index = hashFunction(entry->getName());
	EntryNode* en = new EntryNode;
	en->e = entry;
	en->next = NULL;
	if (entries[index] == NULL ){
		entries[index] = en;
	}
	else{
		en->next=entries[index];
		entries[index] = en;
	} // end if

}


void ChainHashTable::findItem(string name, int& compCount) {

		int index = hashFunction(name);
		EntryNode* cur = entries[index];
		while ( cur != nullptr) {
			compCount++;
			if ( (cur->e)->getName() == name) {
				cout << "Name: " << name << "\tAvailable Quantity: " << (cur->e)->getAmount() <<endl;
				return;
			}
			cur = cur->next;
		}
		cout << "Entry not found." << endl;

}

void ChainHashTable::deleteItem (string name) {

		int index = hashFunction(name);

		if (entries[index] != NULL){
			// Special case - first node has target
			if (name == (entries[index]->e)->getName()){
			EntryNode* toDelete = entries[index];
			entries[index] = entries[index]->next;
			delete toDelete;
			toDelete = NULL ; // For safety
			return;
			}
			else {
				EntryNode* prevPtr = entries[index];
				EntryNode* curPtr = prevPtr->next;
				while ((curPtr != NULL)){
					if (name == curPtr->e->getName())	{
						prevPtr->next = curPtr->next;
						delete curPtr;
						curPtr = NULL ; // For safety
						return;
					}
					else {
						prevPtr = curPtr;
						curPtr = curPtr->next;
					} // end if
				} // end while
			} // end if
		} // end if
}



void ChainHashTable:: printAll() {
	EntryNode* cur;
	for (int i = 0; i < TABLE_SIZE; i++) {
			cur = entries[i];
		if ( cur != NULL) {
				while ( cur != NULL) {
					cout << i << ": "<< cur->e->getName() << " = " << cur->e->getAmount() << " , ";
					cur = cur->next;
				}
		cout << endl;
		}

	}

}



int ChainHashTable::hashFunction (string name) {

	int sum = 0;
	for (unsigned int i = 0; i < name.size(); i++) {
		sum += name[i];
	}

	return sum % TABLE_SIZE;
}
