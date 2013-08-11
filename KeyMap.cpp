/*
 * KeyMap.cpp
 *
 *  Created on: 29 apr 2013
 *      Author: mattias
 */

#include "KeyMap.h"
#include <fstream>
using std::string;
using std::ifstream;

KeyMap::KeyMap(string fname) {
	ifstream file(fname);

	int temp;
	int temprow;

	if (file.is_open()){
		while(!file.eof()){
			file >> temprow;
			if (temprow == -1) break;
			file >> temp;
			rowtranspose[temprow] = temp;
			file >> temp;
			do{
				row[temprow].push_back(temp);
				file >> temp;
			}while (temp != 0 && file.eof() == false);
			temprow = -1;
		}
	}

}

KeyMap::~KeyMap() {
	// TODO Auto-generated destructor stub
}

int KeyMap::Translate(int key) {
	for (int i = 0; i < 5; ++i){
		for (unsigned int j = 0; j<row[i].size(); ++j){
			if (row[i][j] == key){
				return j * 3 + rowtranspose[i];
			}
		}
	}

	return 20;
}


