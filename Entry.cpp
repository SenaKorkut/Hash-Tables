#include "Entry.h"
#include <string>
using namespace std;

Entry::Entry() {
	this->name = "";
	this->amount = 0;
}

Entry::Entry(const string name, const int amount) {
	this->name = name;
	this->amount = amount;
}

Entry::~Entry () {

}

string Entry::getName() const {

	return name;
}


int Entry::getAmount() const {

	return amount;
}
