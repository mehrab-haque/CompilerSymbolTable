#ifndef SYMBOLTABLE_H
#define SYMBOLABLE_H

#include <string>
#include "SymbolInfo.h"
#include "ScopeTable.h"

class SymbolTable{
	int bucketSize;
	ScopeTable *currentScope;
	void printScopesRecursively(ScopeTable *scope);
	public:
		SymbolTable(int bucketSize);
		void enterScope();
		void exitScope();
		bool insertSymbol(string name,string type);
		bool removeSymbol(string name);
		SymbolInfo *lookup(string name);
		void printCurrentScope();
		void printAllScopes();
};

void SymbolTable::printScopesRecursively(ScopeTable *scope){
	if(scope->getParentScope()!=NULL)
		scope=scope->getParentScope();
	scope->print();
}

void SymbolTable::printAllScopes(){
	this->printScopesRecursively(currentScope);
}

void SymbolTable::printCurrentScope(){
	this->currentScope->print();
}

SymbolInfo *SymbolTable::lookup(string name){
	SymbolInfo *foundSymbol=NULL;
	ScopeTable *tmpScope=currentScope;
	while(tmpScope!=NULL){
		foundSymbol=tmpScope->lookup(name);
		if(foundSymbol!=NULL)
			break;
		tmpScope=tmpScope->getParentScope();
	}
	return foundSymbol;
}

bool SymbolTable::removeSymbol(string name){
	return this->currentScope->deleteSymbol(name);
}

bool SymbolTable::insertSymbol(string name,string type){
	SymbolInfo *newSymbol=new SymbolInfo(name,type);
	return this->currentScope->insertSymbol(newSymbol);
}

void SymbolTable::exitScope(){
	ScopeTable *parentScope=this->currentScope->getParentScope();
	if(parentScope==NULL){
		delete currentScope;
		currentScope=new ScopeTable(this->bucketSize);
		return;
	}
	ScopeTable *tmpScope=this->currentScope;
	this->currentScope=this->currentScope->getParentScope();
	delete tmpScope;
}

void SymbolTable::enterScope(){
	ScopeTable *newScope=new ScopeTable(bucketSize,currentScope);
	this->currentScope=newScope;
}

SymbolTable::SymbolTable(int bucketSize){
	this->bucketSize=bucketSize;
	currentScope=new ScopeTable(bucketSize);
}

#endif
