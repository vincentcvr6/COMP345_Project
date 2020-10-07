#pragma once
#include<vector>
#include<string>

using namespace std;

class MapLoader{

private:
	string theMapFile;
	vector<vector<string>> listOfContinents; // Vectors used to store information from file to be read
	vector<vector<string>> listOfBorders;
	vector<vector<string>> listOfCountries;

public:
	void LoadMap();
	MapLoader();
	MapLoader(string mapFile);
	MapLoader(const MapLoader& somemap); //copy constructor
	string getfile();					 // Getter method 
	void setfile(string newfile);        // Setter method
};