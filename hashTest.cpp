#include <iostream>
#include<string>
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "Hash.h"

using namespace std;

int main(){
	
	SymbolInfo *symbol1=new SymbolInfo("aye","int");
	SymbolInfo *symbol2=new SymbolInfo("hello world","int");
	SymbolInfo *symbol3=new SymbolInfo("whats upp","int");
	SymbolInfo *symbol4=new SymbolInfo("sunny weather","int");
	SymbolInfo *symbol5=new SymbolInfo("Hey you","int");
	SymbolInfo *symbol6=new SymbolInfo("Cute","int");
	SymbolInfo *symbol7=new SymbolInfo("How are you","int");
	SymbolInfo *symbol8=new SymbolInfo("I am fine, thank you","int");
	SymbolInfo *symbol9=new SymbolInfo("How can I help you","int");
	SymbolInfo *symbol10=new SymbolInfo("We have won the game","int");
	SymbolInfo *symbol11=new SymbolInfo("Terrific day","int");
	SymbolInfo *symbol12=new SymbolInfo("Starry night","int");
	
	//declaring hash of bucket size 5
	Hash *hash=new Hash(5);
	
	//inserting 12 Symbols
	hash->insertItem(symbol1);
	hash->insertItem(symbol2);
	hash->insertItem(symbol3);
	hash->insertItem(symbol4);
	hash->insertItem(symbol5);
	hash->insertItem(symbol6);
	hash->insertItem(symbol7);
	hash->insertItem(symbol8);
	hash->insertItem(symbol9);
	hash->insertItem(symbol10);
	hash->insertItem(symbol11);
	hash->insertItem(symbol12);
	hash->print();	
	
	//delete test of only symbol in a chain
	cout<<"deleting "<<symbol12->getName()<<endl;
	hash->deleteItem(symbol12);
	hash->print();
	
	//delete test first symbol of a chain
	cout<<"deleting "<<symbol1->getName()<<endl;
	hash->deleteItem(symbol1);
	hash->print();
	
	//delete test last symbol of a chain
	cout<<"deleting "<<symbol11->getName()<<endl;
	hash->deleteItem(symbol11);
	hash->print();
	
	//delete test intermediate symbol of a chain
	cout<<"deleting "<<symbol4->getName()<<endl;
	hash->deleteItem(symbol4);
	hash->print();
	
	return 0;
}
