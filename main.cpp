#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "SymbolTable.h"

using namespace std;

int main(){
	
	string line;
	
	ifstream infile("input.txt");
	bool isFirstLine=true;
	
	SymbolTable *symbolTable;
	
	
	
	while (getline(infile, line))
	{
	    istringstream iss(line);
	    if(isFirstLine){
	    	isFirstLine=false;
	    	int bucket_size;
	    	iss>>bucket_size;
	    	symbolTable=new SymbolTable(bucket_size);
		}else{
			string command;
		    iss>>command;
		    if(command.compare("I")==0){
		    	string name,type;
		    	iss>>name>>type;
		    	symbolTable->insertSymbol(name,type);
			}
			else if(command.compare("L")==0){
		    	string name;
		    	iss>>name;
		    	symbolTable->lookup(name);
			}
			else if(command.compare("P")==0){
		    	string printType;
		    	iss>>printType;
		    	if(printType.compare("A")==0)
		    		symbolTable->printAllScopes();
		    	else if(printType.compare("C")==0) 
					symbolTable->printCurrentScope();
			}
			else if(command.compare("D")==0){
		    	string name;
		    	iss>>name;
		    	symbolTable->removeSymbol(name);
			}
			else if(command.compare("S")==0){
		    	symbolTable->enterScope();
			}
			else if(command.compare("E")==0){
		    	symbolTable->exitScope();
			}
		}
	}
		
	return 0;
}
