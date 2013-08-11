/*
 * KeyMap.h
 *
 *  Created on: 29 apr 2013
 *      Author: mattias
 */

#ifndef KEYMAP_H_
#define KEYMAP_H_

#include <string>
#include <vector>

class KeyMap {
public:
	KeyMap(std::string fname);
	virtual ~KeyMap();

	int Translate(int key);

private:
	std::vector<int> row[5];
	int rowtranspose[5];
};

#endif /* KEYMAP_H_ */
