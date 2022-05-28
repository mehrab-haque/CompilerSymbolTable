#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

//Dependencies
#include<iostream>
#include <string>
#include<sstream>

using namespace std;

//Class Signatures

//This class represents a Symbol
class SymbolInfo{
	string name;
	string type;

	stringstream printStream;

	SymbolInfo *nextSymbol;
	public:
		SymbolInfo(string name,string type);
		void setName(string name);
		string getName();
		void setType(string type);
		string getType();
		void setNextSymbol(SymbolInfo *nextSymbol);
		SymbolInfo *getNextSymbol();
		string print();
		~SymbolInfo();	
};

SymbolInfo::~SymbolInfo(){
	//delete this->nextSymbol;
}

SymbolInfo::SymbolInfo(string name,string type){
	this->name=name;
	this->type=type;
	this->nextSymbol=NULL;
}

string SymbolInfo::getName(){
	return this->name;
}

void SymbolInfo::setName(string name){
	this->name=name;
}

string SymbolInfo::getType(){
	return this->type;
}

void SymbolInfo::setType(string type){
	this->type=type;
}

SymbolInfo *SymbolInfo::getNextSymbol(){
	return this->nextSymbol;
}

void SymbolInfo::setNextSymbol(SymbolInfo *nextSymbol){
	this->nextSymbol=nextSymbol;
}

string SymbolInfo::print(){
	printStream.str("");
	printStream<<"########SYMBOL INFO START########"<<endl;
	printStream<<"<"<<name<<","<<type<<">"<<endl;
	printStream<<"########SYMBOL INFO END########"<<endl<<endl;
	return printStream.str();
}


#endif
