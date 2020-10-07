#include "MapLoader.h"
#include<iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string fileOfMap[1];
	fileOfMap[1] = {"C:\\Users\\Desktop\\germany.map"};

	for (int j = 0; j < 1; j++){
		cout << "Loop #" << j << endl;
		cout << "\n" << endl;

		try {
			MapLoader* ptr = new MapLoader(fileOfMap[j]);  // Pointer pointing to mapLoader object
			cout << "\n" << *ptr;

			delete(ptr); // To avoid memory leaks
			ptr = NULL;
		}
		catch (int someError){
			cout << "error" << endl;
			cout << "\n" << endl;
		}
	}
}