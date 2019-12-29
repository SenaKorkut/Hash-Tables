#ifndef OPENHASHTABLE_H_INCLUDED
#define OPENHASHTABLE_H_INCLUDED
#include "Entry.h"
#include <string>

using std::string;

class OpenHashTable{
public:
	OpenHashTable();
	~OpenHashTable();
	void insert(Entry& entry,int& compCount);
	void findItem(string name, int& compCount);
	void printAll();
	void deleteItem (string name);

private:
	static const int TABLE_SIZE = 167;
	Entry entries[TABLE_SIZE];
	int status[TABLE_SIZE] = {0};
	int hashFunction(string name);

};

#endif // OPENHASHTABLE_H_INCLUDED
