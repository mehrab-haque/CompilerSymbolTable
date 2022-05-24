#ifndef HASH_H
#define HASH_H

#include "SymbolInfo.h"
#include <cstdlib>

class Hash{
	int size;
	SymbolInfo **items;
	
	public:
		Hash(int size);
		bool insertItem(SymbolInfo *item);
		bool deleteItem(SymbolInfo *item);
		bool exists(SymbolInfo *item);
		unsigned long hashFunction(SymbolInfo *item);
		void print();
};

Hash::Hash(int size){
	this->size=size;
	this->items=(SymbolInfo**)malloc(sizeof(SymbolInfo*)*size);
	for(int i=0;i<size;i++)
		this->items[i]=NULL;
}


unsigned long Hash::hashFunction(SymbolInfo *item){
	string s=item->getName();
    unsigned long hash = 0;
    for(int i=0;i<s.size();i++)
    	hash = s[i] + (hash << 6) + (hash << 16) - hash;       
    return hash%this->size;
}



bool Hash::exists(SymbolInfo *item){
	int index=this->hashFunction(item);
	if(this->items[index]==NULL)return false;
	SymbolInfo *currSymbol=this->items[index];
	bool isFound=false;
	while(currSymbol!=NULL){
		if(currSymbol->getName().compare(item->getName())==0){
			isFound=true;
			break;
		}
		currSymbol=currSymbol->getNextSymbol();
	}
	return isFound;
}

bool Hash::deleteItem(SymbolInfo *item){
	if(!exists(item))return false;
	int index=this->hashFunction(item);
	SymbolInfo *prevSymbol=items[index];
	SymbolInfo *currSymbol=items[index];
	
	while(currSymbol->getName().compare(item->getName())!=0){
		prevSymbol=currSymbol;
		currSymbol=currSymbol->getNextSymbol();
	}
	
	if(prevSymbol==currSymbol)
		items[index]=currSymbol->getNextSymbol();
	else
		prevSymbol->setNextSymbol(currSymbol->getNextSymbol());
	
	//delete currSymbol;

	return true;
}

bool Hash::insertItem(SymbolInfo *item){
	if(exists(item))return false;
	int index=this->hashFunction(item);
	if(this->items[index]==NULL)
		items[index]=item;
	else{
		SymbolInfo *currSymbol=items[index];
		while(currSymbol->getNextSymbol()!=NULL)
			currSymbol=currSymbol->getNextSymbol();
		currSymbol->setNextSymbol(item);
	}	
	return true;
}

void Hash::print(){
	cout<<"########HASH TABLE START########"<<endl;
	for(int i=0;i<this->size;i++){
		cout<<i<<" : ";
		SymbolInfo *currSymbol=this->items[i];
		while(currSymbol!=NULL){
			cout<<currSymbol->getName();
			currSymbol=currSymbol->getNextSymbol();
			if(currSymbol!=NULL)
				cout<<" -> ";
		}
		cout<<endl;
	}
	cout<<"########HASH TABLE END########"<<endl<<endl;
}

#endif
