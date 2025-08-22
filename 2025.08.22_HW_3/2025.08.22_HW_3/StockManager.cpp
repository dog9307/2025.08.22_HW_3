#include "StockManager.h"

void StockManager::initializeStock(string potionName)
{
	potionStock.emplace(potionName, 3);
}

bool StockManager::dispensePotion(string potionName)
{
	if (potionStock[potionName] > 0)
	{
		--potionStock[potionName];
		return true;
	}
	else
	{
		return false;
	}
}

bool StockManager::returnPotion(string potionName)
{
	if (potionStock[potionName] < MAX_STOCK)
	{
		++potionStock[potionName];
		return true;
	}
	else
	{
		return false;
	}
}

int StockManager::getStock(string potionName)
{
	StockMapIterator iter = potionStock.find(potionName);

	if (iter != potionStock.end())
	{
		return iter->second;
	}

	return -1;
}
