#ifndef CHAINHASHTABLE_H_INCLUDED
#define CHAINHASHTABLE_H_INCLUDED

#include <numeric>
#include "Entry.h"
#include <string>
#include <numeric>

using std::string;

class ChainHashTable{
public:
	ChainHashTable();
	~ChainHashTable();
	void insert(Entry* entry);
	void findItem(string name, int& compCount);
	void printAll();
	void deleteItem (string name);

private:
	struct EntryNode {
	Entry* e;
	EntryNode* next;
	};
	static const int TABLE_SIZE = 73;
	EntryNode* entries [TABLE_SIZE] = {NULL};
	int hashFunction(string name);

};
#endif // CHAINHASHTABLE_H_INCLUDED
