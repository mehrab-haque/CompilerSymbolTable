#include <iostream>
#include "ScopeTable.h"

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
	
	ScopeTable *globalScope=new ScopeTable(10);

	ScopeTable *scope1=new ScopeTable(10,globalScope);
	ScopeTable *scope2=new ScopeTable(10,globalScope);
	ScopeTable *scope21=new ScopeTable(10,scope2);
	
	scope21->insertSymbol(symbol2);
	scope21->insertSymbol(symbol3);
	
	scope21->deleteSymbol(symbol3->getName());
	
	scope1->print();
	scope2->print();
	scope21->print();
	
	return 0;
}
