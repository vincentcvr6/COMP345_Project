#include "MapLoader.h"
//#include "Map.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
string theMapFile;

string MapLoader::getfile() {					   // Getter for the new maploader
	return theMapFile;
}

void MapLoader::setfile(string mapLoaderNewFile) {  // Setter for the new maploader object 
	theMapFile = mapLoaderNewFile;
}

MapLoader::MapLoader(){  // Default constructor
	theMapFile = "";
}

MapLoader::MapLoader(const MapLoader& somemap){  // Copy constructor
	theMapFile = somemap.theMapFile;
}

void MapLoader::LoadMap() {  // Method for objects that are not correctly fomated 
	if (theMapFile == "") {
		cout << "There is no file to load" << endl;
	}
	else {
		ifstream input(theMapFile);
		while (!input.eof()) {
		}
		input.close();
	}
}

MapLoader::MapLoader(string mapFile){ // Constructor that creates a map from a mapfile
	theMapFile = mapFile;
	ifstream input(mapFile);
	while (!input.eof()){
		string tmp;					 // Stores lines from the mapfile
		int idx;					 // Stores the size of the data that will go in vector
		int position=0;				 // Used to save memory locations for continents, countries and borders

		getline(input,tmp);
		cout << tmp << endl;
		cout << "\n" << endl;

		if(tmp.find("[continents]") != -1){     
			position = 0;					    // Storage allocation for the 2d vector
			while(tmp.find("[countries]") == -1){
				listOfContinents.push_back(vector<string>()); // Creates memory space for continents
				getline(input,tmp);
				idx = tmp.find(" ");           // Stores the index of the last character of the continent's name
				if(idx == -1){ 
					break; 
				} 
				listOfContinents[position].push_back(tmp.substr(0,idx)); // When no more continents, store in vector

				tmp.erase(0,idx++);
				idx = tmp.find(" ");
				listOfContinents[position].push_back(tmp.substr(0, idx));

				if (idx == -1){ 
					break; 
				} 
				tmp.erase(0,idx++);
				idx = tmp.find(" ");
				listOfContinents[position].push_back(tmp.substr(0,idx));

				cout << "Continent #" << position << " is " << listOfContinents[position][0] << listOfContinents[position][1] << listOfContinents[position][2] << endl;
				cout << "\n" << endl;
				position++;  // Goes to the next memory location for the next continent  
			}
		}

		position=0; // Resets variable for other usage

		if (tmp.find("[countries]") != -1){   // If there exists countries
			while (tmp.find("[borders]") == -1){
				getline(input,tmp);
				if (tmp.find(';') != -1){  // If there are comments after the list of countries 
					continue; 
				}
				listOfCountries.push_back(vector<string>()); 
				for (int k = 0; k < 5; k++){
					idx = tmp.find(" "); // Puts the index of the country in variable 
					if (k == 0 && idx == -1){
						break; 
					}
					listOfCountries[position / 5].push_back(tmp.substr(0, idx));
					tmp.erase(0,idx++);
					position++;
				}
				cout << "Country #" << (position / 5) - 1 << " is " << listOfCountries[(position / 5) - 1][0] << listOfCountries[(position / 5) - 1][1] << listOfCountries[(position / 5) - 1][2] << listOfCountries[(position / 5) - 1][3] << listOfCountries[(position / 5) - 1][4] << endl;
				cout << "\n" << endl;
			}
		}

		if (tmp.find("[borders]") != -1){  // If there exists borders
			for (int j = 0; j < (position / 5); j++) { // Goes through all the countries and gathers information on borders
				getline(input, tmp);
				if (tmp.at(0) == ';'){     // If there are comments after the continent declaration 
					j = j - 1;
					continue;
				}
				listOfBorders.push_back(vector<string>()); 
				do {
					idx = tmp.find(" "); // puts the index of the border in variable 
					listOfBorders[j].push_back(tmp.substr(0,idx));  // Puts in border memory list 
					tmp.erase(0,idx++);
				} while (idx != -1);
				cout << "Border #" << j << " is " << listOfBorders[j][0] << " " << listOfBorders[j][1] << "..." << endl;
				cout << "\n" << endl;
			}
		}
	}
	input.close();
}

