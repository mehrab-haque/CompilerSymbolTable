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
		    	bool isInserted=symbolTable->insertSymbol(name,type);
				if(!isInserted){
					SymbolInfo *symbol=symbolTable->lookup(name);
					cout<<"This word already exists"<<endl<<"< "<<symbol->getName()<<", "<<symbol->getType()<<" > already exists in the currentScopeTable"<<endl<<endl;
				}
					
				else{
					string scopeId=symbolTable->getCurrentScopeId();
					int hashPos=symbolTable->getHashPos(name);
					int chainPos=symbolTable->getChainPos(name);
					cout<<"Inserted in ScopeTable# "<<scopeId<<" at position "<<hashPos<<", "<<chainPos<<endl<<endl;
				}
			}
			else if(command.compare("L")==0){
		    	string name;
		    	iss>>name;
		    	SymbolInfo *symbol=symbolTable->lookup(name);
		    	if(symbol==NULL)
		    		cout<<"Not Found"<<endl<<endl;
		  		else{
		  			string scopeId=symbolTable->getCurrentScopeId();
					int hashPos=symbolTable->getHashPos(name);
					int chainPos=symbolTable->getChainPos(name);
					cout<<"Found in ScopeTable# "<<scopeId<<" at position "<<hashPos<<", "<<chainPos<<endl<<endl;
				}
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
		    	SymbolInfo *symbol=symbolTable->lookupCurrent(name);
		    	if(symbol==NULL)
		    		cout<<"Not Found"<<endl<<name<<" is not found"<<endl<<endl;
	    		else{
	    			string scopeId=symbolTable->getCurrentScopeId();
					int hashPos=symbolTable->getHashPos(name);
					int chainPos=symbolTable->getChainPos(name);
					symbolTable->removeSymbol(name);
					cout<<"Found in ScopeTable# "<<symbolTable->getCurrentScopeId()<<" at position "<<hashPos<<", "<<chainPos<<endl<<"Found it"<<endl<<"Deleted entry at position "<<hashPos<<", "<<chainPos<<" in the current scopetable"<<endl<<endl;
				}
			}
			else if(command.compare("S")==0){
		    	symbolTable->enterScope();
		    	cout<<"New ScopeTable with id# "<<symbolTable->getCurrentScopeId()<<" is created"<<endl<<endl;
			}
			else if(command.compare("E")==0){
				if(symbolTable->isGlobalScope())
					cout<<"Cannot exit global scope until the inputs finish, global symbols are cleared instead"<<endl<<endl;
				else{
					string deletedScopeId=symbolTable->getCurrentScopeId();
			    	cout<<"ScopeTable with id "<<deletedScopeId<<" is removed"<<endl<<"Destroying the ScopeTable"<<endl<<endl;
				}
				symbolTable->exitScope();
			}
		}
	}
		
	delete symbolTable;
	return 0;
}
