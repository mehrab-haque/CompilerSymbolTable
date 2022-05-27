#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	string line;
	
	ifstream infile("input.txt");
	bool isFirstLine=false;
	
	while (getline(infile, line))
	{
	    istringstream iss(line);
	    if(isFirstLine){
	    	isFirstLine=false;
	    	int bucket_size;
	    	iss>>bucket_size;
	    	cout<<bucket_size<<endl;
		}else{
			string command;
		    iss>>command;
		    if(command.compare("I")==0){
		    	string name,type;
		    	iss>>name>>type;
		    	cout<<"Insert "<<name<<' '<<type<<endl;
			}
			else if(command.compare("L")==0){
		    	string name;
		    	iss>>name;
		    	cout<<"Lookup "<<name<<endl;
			}
		    
		}
	}
		
	return 0;
}
