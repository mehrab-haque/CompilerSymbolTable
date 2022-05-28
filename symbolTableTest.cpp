#include <iostream>
#include "SymbolTable.h"

using namespace std;

int main(){
	
	SymbolTable *symbolTable=new SymbolTable(4);
	
	cout<<symbolTable->printAllScopes();
	symbolTable->insertSymbol("a","int");
	symbolTable->insertSymbol("c","int");
	symbolTable->enterScope();
	symbolTable->insertSymbol("a","int");
	symbolTable->insertSymbol("b","int");
	symbolTable->insertSymbol("d","int");
	cout<<symbolTable->printAllScopes();
	
	SymbolInfo *foundSymbol=symbolTable->lookup("d");
	if(foundSymbol==NULL)cout<<"not found"<<endl;
	else cout<<foundSymbol->print();
	
	symbolTable->exitScope();
	cout<<symbolTable->printAllScopes();
	
	foundSymbol=symbolTable->lookup("d");
	if(foundSymbol==NULL)cout<<"not found"<<endl;
	else cout<<foundSymbol->print();
	
	symbolTable->enterScope();
	symbolTable->insertSymbol("f","int");
	symbolTable->insertSymbol("b","int");
	symbolTable->insertSymbol("d","int");
	
	cout<<symbolTable->printAllScopes();
	
	foundSymbol=symbolTable->lookup("f");
	if(foundSymbol==NULL)cout<<"not found"<<endl;
	else cout<<foundSymbol->print();
	
	symbolTable->removeSymbol("f");
	cout<<symbolTable->printAllScopes();
	
	return 0;
}
