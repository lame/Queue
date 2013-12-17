#include "Queue.h"
#include <map>
#include <iomanip>
#include <iostream>
using namespace cop4530;
using namespace std;

void BFS(map<string, map<string, int> >, vector<string>);

int main(int argc, char * argv[]){
    typedef map<string, map<string, int> > MAP;
    int cityCount;
    int price;
    char fileName[80];
    
    vector <string> cityName;
    vector <string> BFSResult;
    
    string inStream;
    fstream myfile;

    MAP cities;
    

    if(argc < 2 || argc > 2){
	cout << "Improper Usage, Please enter <executable> <filename>" << endl;
	return 0;
    }

    myfile.open(argv[1]);
    while(!myfile.is_open()){
	cout << "Please enter a valid filename: ";
	cin >> fileName;
	myfile.open(fileName);
    }
//    myfile.open("proj3.input");	//REMEMBER TO TAKE OUT BEFORE SUBMISSION

    if(myfile.is_open()){
	myfile >> cityCount;
	cout << cityCount << " cities: " << endl;
	string dummy;
	getline(myfile, dummy);
	for(int i = 0; i < cityCount; i++){
	    getline(myfile, inStream);
	    cityName.push_back(inStream);   //does this need a pair?
	    cout << "    " << inStream << endl;
	}
	for(int i = 0; i < cityCount; ++i){
	    for(int j = 0; j < cityCount; ++j){
		myfile >> price;
		cities[cityName[i]][cityName[j]] = price;
	    }
	}
    }
    cout << "direct flights between cities" << endl;
    cout << "-------------------------" << endl; 
    for (int i = 0; i < (int)cityName.size(); ++i) {
      cout << cityName[i] << ":" << endl;
      for (int j = 0; j < (int)cityName.size(); ++j) {
	if(cities[cityName[i]][cityName[j]] != 0 && cities[cityName[i]][cityName[j]] != -1){ 
	cout << "    " << cityName[j] << ", $" << cities[cityName[i]][cityName[j]] << endl;
	}
      }
    }  
    BFS(cities, cityName);
    return 0;
}
void BFS(map<string, map<string, int> >cities, vector<string>cityName){
    
    Queue<vector<string> > Q;
    vector<string> Visited;
    vector<string> temp;
    vector<string> empty;
    vector<string>::iterator ITR1, ITR2, sumITR, sumITR1;
    string sourceCity;
    string destCity;
    string yn;
    int sum = 0;

    bool destFound = false;
    bool V = false;

    cout << "-------------------------" << endl; 
    cout << "Source city : ";
    getline(cin, sourceCity);
    cout << "Destination city : ";
    getline(cin, destCity);
    cout << "finding min_hop route...." << endl;
    
//    cout << "1" << endl;
    
    temp.push_back(sourceCity);
    Q.push(temp);
    Visited.push_back(sourceCity);

    if(sourceCity == destCity){
     cout << "Price is 0" << endl;
    }    
    else if(cities[sourceCity][destCity] > 0){
      cout << sourceCity << " -> " << destCity<< ", $"<< cities[sourceCity][destCity] << endl;
    }
    else{
    while(Q.empty() == false){
      for(ITR1 = cityName.begin(); ITR1 != cityName.end(); ++ITR1){	      //cycle through the cities
	temp = Q.front();      //temp now holds the initial value

	if(cities[temp.back()][*ITR1] > 0){    //if the cities are connected

//	  cout << "Connection Price : " << *ITR1 << "  " << cities[temp.back()][*ITR1] << endl;
	  for(ITR2 = Visited.begin(); ITR2 != Visited.end(); ++ITR2){	  
//	    cout << "    " << *ITR2 << endl;
	    if(*ITR1 == *ITR2){		      //has the city already been visited?
	      break;
	    }//if bracket
	    else{
	      temp.push_back(*ITR1);
	      if(temp.back() != destCity){
		Q.push(temp);
		Visited.push_back(*ITR1);
		temp.pop_back();
		break;
	      }//if bracket
	      else if(temp.back() == destCity) 
		break;
	    }//else bracket
	    if(temp.back() == destCity)
	      break;
	  }//for bracket
	if(temp.back() == destCity)
	  break;

	
	}//if values between cities bracket
      }//to first for loop
      Q.pop();		      //remove the initial value from the Q
      if(temp.back() == destCity){
//	cout << "Destination city found : " << temp.back() << endl;
	while(Q.empty() == false){Q.pop();}
      }
    }//to main while loop
    }//to main else loop
//  cout << "Print FOR : " << endl;
  int first = 0;
  int second = 1; 
  for(int i = 1; i < (int)temp.size(); ++i){
    cout << temp[i] << " -> ";
    sum += cities[temp[first]][temp[second]];
    ++first;
    ++second;
  }
  cout << ", $" << sum << endl;
//  cout << "Final Sum: " << sum << endl;
  cout << "Search another route? (Y/N) ";
  getline(cin, yn);
  if(yn == "Y" || yn == "y")
    BFS(cities, cityName);
  else
    return;
}
//	  if(V == false){
//	    cout << "storing the city name : " << *ITR1 << endl;
//	    temp.push_back(*ITR1);	    //no, STORE
//	    Q.push(temp);
//	    Visited.push_back(*ITR1);
//	    temp.pop_back();

//	    cout << "entering dest check : ";
	    
//	    if(temp.back() == destCity){
//	      cout << "Dest found" << endl;
//	      break;
//	    }
//	    else
//	      cout << "Not Found" << endl;
//	  }
//	  else{
//	    V = false;
//	    //temp.pop_back();
//	    cout << *ITR1 << " was not stored, break" << endl;
//	    break;  
//	  }
//	if(temp.back() == destCity)
//	  break;
  //    if(temp.back() == destCity)
//	break;
//	      V = true;					      //yes, break, DO NOT STORE
//	      cout << *ITR1 << " tripped to True " << endl;
