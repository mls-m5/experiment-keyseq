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
			} while (temp != 0 && file.eof() == false);
			temprow = -1;
		}
	}

}

KeyMap::~KeyMap() {
}

int KeyMap::Translate(int key) {
	for (int i = 0; i < 5; ++i){
		for (unsigned int j = 0; j < row[i].size(); ++j){
			if (row[i][j] == key){
				return j * 3 + rowtranspose[i];
			}
		}
	}

	return 20;
}

//// alternative translation function for the keyboard to act as a fiddle
//int fiddleTranspose(int row){
//	if (row == 0) return -4;
//	if (row == 1) return -3;
//	if (row == 2) return -1;
//	if (row == 3) return -2;
//	return 0;
//}
//
//int KeyMap::Translate(int key) {
//	for (int i = 0; i < 5; ++i){
//		for (unsigned int j = 0; j<row[i].size(); ++j){
//			if (row[i][j] == key){
//				return j + (3 - i) * 6 + fiddleTranspose(i) + 60; // + rowtranspose[i];
//			}
//		}
//	}
//
//	return 20;
//}


