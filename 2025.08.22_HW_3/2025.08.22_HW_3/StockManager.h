#pragma once

#include <map>
#include <string>

using namespace std;

typedef map<string, int> StockMap;
typedef map<string, int>::iterator StockMapIterator;

class StockManager
{
private:
	const int MAX_STOCK = 3;
	StockMap potionStock;

public:
	void initializeStock(string potionName);
	bool dispensePotion(string potionName);
	bool returnPotion(string potionName);
	int getStock(string potionName);

};
