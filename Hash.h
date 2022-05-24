#ifndef HASH_H
#define HASH_H

#include "SymbolInfo.h"

class Hash{
	int size;
	SymbolInfo *items;
	
	public:
		Hash(int size);
		void insertItem(SymbolInfo *item);
		void deleteItem(SymbolInfo *item);
		int hashFunction(SymbolInfo *item);
};

Hash::Hash(int size){
	this->size=size;
}

#endif
