#include <numeric>
#include <iostream>
#include"OpenHashTable.h"
#include <string>

using std::string;

OpenHashTable::OpenHashTable() {

	//entries = new Entry[TABLE_SIZE];

}

OpenHashTable::~OpenHashTable() {

}

void OpenHashTable::insert(Entry& entry, int& collCount) {

	int index = hashFunction(entry.getName());
	int i; //init value
	for (i = 0; i < TABLE_SIZE ;i++) {

		int quadraticProbe = (index + i*i) % TABLE_SIZE;
		if ( status[quadraticProbe] != 1 ) {
			entries[quadraticProbe] = entry;
			status[quadraticProbe] = 1; //means occupied
			return;
		}
		else {
			collCount++;
		}
	//i++;
	//cout << index << "		" << entry->getName()<< endl;
	} //while ( status[i] != 0);
}


void OpenHashTable::findItem(string name, int& compCount) {
	int index = hashFunction(name);
	int i = 0; //init value
	while ( i < TABLE_SIZE ) {

		int quadraticProbe = (index + i*i) % TABLE_SIZE;
		compCount++;
		if ( status[quadraticProbe] == 1 && entries[quadraticProbe].getName() == name) {
			cout << "Name: " << name << "\tAvailable Quantity: " << entries[quadraticProbe].getAmount() << endl;
			return;
		}
		i++;
		}
	cout << "Entry not found.	" << endl;
}

void OpenHashTable::deleteItem (string name) {

	int index = hashFunction(name);
	int i = 0; //init value
	while ( i < TABLE_SIZE ) {

		int quadraticProbe = (index + i*i) % TABLE_SIZE;

		if ( entries[quadraticProbe].getName() == name) {

			status[quadraticProbe] = -1; //means deleted

			return;
		}
	i++;
	}


}

void OpenHashTable:: printAll() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if(status[i] == 1) {
			cout << i << ": " << entries[i].getName() << " = " << entries[i].getAmount() << "," << endl;
		}
	}

}

int OpenHashTable::hashFunction (string name) {

	return accumulate(name.begin(), name.end(), 0) % TABLE_SIZE;
}
