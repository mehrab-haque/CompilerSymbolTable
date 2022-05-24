#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include "SymbolInfo.h"

class ScopeTable{
	int BUCKET_SIZE;
	SymbolInfo *symbols;
	
	public:
		ScopeTable(int size);
		
};

ScopeTable::ScopeTable(int size){
	this->BUCKET_SIZE=size;
}

#endif
