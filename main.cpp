#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "ChainHashTable.h"
#include "OpenHashTable.h"


void analyzePerformance(OpenHashTable*& opH, ChainHashTable*& chH) {

	double ohAverage[3];
	double chAverage[3];
	string randomPick[100];
	int n = 0;
	int random;
	int table_size = 0;
	int collCount = 0;
	int compCount = 0;
	int compCount2 = 0;
	std::ifstream file("items.txt");
	std::string line;

	chrono::time_point< chrono::system_clock > startTime;
	chrono::duration< double, milli > elapsedTime;

	startTime = chrono::system_clock::now();

	while (std::getline(file, line)) {

		random = rand()%2;
		int amount;
		std::istringstream(line.substr(0, line.find("\t")))  >>amount ;
		string name = line.substr( line.find("\t")+1);
		Entry entry(name, amount);
		opH->insert(entry, collCount);
		if(random == 1 && n < 100) {
				randomPick[n] = name;
				n++;
			}
		table_size++;
	}
	elapsedTime = chrono::system_clock::now() - startTime;
	ohAverage[0] = elapsedTime.count()/table_size;

	startTime = chrono::system_clock::now();

	std::ifstream file2("items.txt");
	std::string line2;

	while (std::getline(file2, line2) ) {
			int amount;
			std::istringstream(line2.substr(0, line2.find("\t")))  >>amount ;
			string name = line2.substr( line.find("\t")+1);
			Entry* entry = new Entry(name, amount);
			chH->insert(entry);

	}
	elapsedTime = chrono::system_clock::now() - startTime;
	chAverage[0] = elapsedTime.count()/table_size;
	chH->printAll();
	cout<<"gel"<<endl;
	if ( n < 100) {
		for (int i = n-1; i < 100; i++) {
			randomPick[i] = "name to not exist in hash";
		}
	}

opH->printAll();
	startTime = chrono::system_clock::now();
	for(int i = 0; i < 100; i++) {
		opH->findItem(randomPick[i], compCount);

	}
	elapsedTime = chrono::system_clock::now() - startTime;
	ohAverage[1] = elapsedTime.count()/100;
	startTime = chrono::system_clock::now();
	for(int i = 0; i < 100; i++) {
		chH->findItem(randomPick[i], compCount2);

	}

	elapsedTime = chrono::system_clock::now() - startTime;
	chAverage[1] = elapsedTime.count()/100;

	startTime = chrono::system_clock::now();
	for(int i = 0; i < 100; i++) {

		opH->deleteItem(randomPick[i]);

	}
	elapsedTime = chrono::system_clock::now() - startTime;
	ohAverage[2] = elapsedTime.count()/100;


	startTime = chrono::system_clock::now();
	for(int i = 0; i < 100; i++) {

		chH->deleteItem(randomPick[i]);
	}

	elapsedTime = chrono::system_clock::now() - startTime;
	chAverage[2] = elapsedTime.count()/100;

	//Print values

	cout << "-----------------------------------------------------" << endl;
	cout <<	"Part a - Analysis of Open Addressing Hash Table" << endl;
	cout << "Parameter 				Time Elapsed" << endl;
	cout << "Average Insertion Time \t\t" << ohAverage[0] << "  ms" <<endl;
	cout << "Average Retrieval Time \t\t" << ohAverage[1] << "  ms" <<endl;
	cout << "Average Deletion Time  \t\t" << ohAverage[2] << "  ms" <<endl;
	cout << "Number of comparisons in Retrieval = " << compCount << endl;
	cout << "Number of collisions in Insertion = " << collCount << endl;

	cout << "-----------------------------------------------------" << endl;
	cout <<	"Part b - Analysis of Separate Chain Hash Table" << endl;
	cout << "Parameter 				Time Elapsed" << endl;
	cout << "Average Insertion Time \t\t" << chAverage[0] << "  ms" <<endl;
	cout << "Average Retrieval Time \t\t" << ohAverage[1] << "  ms" <<endl;
	cout << "Average Deletion Time  \t\t" << chAverage[2] << "  ms" <<endl;
	cout << "Number of comparisons in Retrieval = " << compCount2 << endl;

	file.close();

}

int main() {

	OpenHashTable* opH = new OpenHashTable();
	ChainHashTable* chH = new ChainHashTable();
	int foo = 0;
	int table_size = 0;


	//insert items to separate chain hash table
	std::ifstream file("items.txt");
	std::string line;

	while (std::getline(file, line)) {

		int amount;
		std::istringstream(line.substr(0, line.find("\t")))  >>amount ;
		string name = line.substr( line.find("\t")+1);
		Entry entry(name, amount);
		opH->insert(entry, foo);
		table_size++;
	}

    //Insert items to separate chain hash table
	std::ifstream file2("items.txt");
	std::string line2;

	while (std::getline(file2, line2) ) {
			int amount;
			std::istringstream(line2.substr(0, line2.find("\t")))  >>amount ;
			string name = line2.substr( line.find("\t")+1);
			Entry* entry = new Entry(name, amount);
			chH->insert(entry);

	}



	cout << "Hash table for open addressing" << endl;
	opH->printAll();
	cout << "Hash table for separate chaining" << endl;
	chH->printAll();

	cout << "---------" << endl;
	cout << "Find 3 favorite fruits from open addressig hash table:"<< endl;
	opH->findItem("black berries", foo);
	opH->findItem("grapes globe", foo);
	opH->findItem("mango", foo);

	cout << "---------" << endl;
	cout << "Find 3 favorite fruits from separate chaining hash table:"<< endl;
	opH->findItem("black berries", foo);
	opH->findItem("grapes globe", foo);
	opH->findItem("mango", foo);
	cout << "---------" << endl;

	opH->findItem("spinach",foo);
	opH->findItem("beans red",foo);
	opH->findItem("banana burro",foo);

	chH->findItem("spinach",foo);
	chH->findItem("beans red",foo);
	chH->findItem("banana burro",foo);

	cout << "Delete 3 least favorite vegetables from open addressig hash table:"<< endl;
	opH->deleteItem("spinach");
	opH->deleteItem("beans red");
	opH->deleteItem("banana burro");

	cout << "Delete 3 least favorite vegetables from separate chaining hash table:"<< endl;
	chH->deleteItem("spinach");
	chH->deleteItem("beans red");
	chH->deleteItem("banana burro");

	cout << "After deletion :" << endl;
	cout << "Hash table for open addressing" << endl;
	opH->printAll();
	cout << "Hash table for seperate chaining" << endl;
	chH->printAll();

	delete chH;
	delete opH;


}
