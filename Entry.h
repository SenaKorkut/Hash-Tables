#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED

#include <string>
using namespace std;

class Entry {

public:
Entry();
Entry(const string name, const int amount);
~Entry ();
string getName() const;
int getAmount() const;

private:
string name;
int amount;
};



#endif // ENTRY_H_INCLUDED
