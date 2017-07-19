#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class TankGame {
private:
	vector<vector<char>> map;
	int shotDownTanks = 0;

public:
	TankGame(int size) {
		//set the 2 dimensional array (map)
		vector< vector<char> > _map(size, vector<char>(size));
		map = _map;
	};

	void setElement(int i, int j, char c) {
		map[i][j] = c;
	}

	void warBegins() {
		for (int i = 0; i < (int)map.capacity(); i++)
		{
			for (int j = 0; j < (int)map.capacity(); j++) {
				if (map[i][j] == 'T')
					killEnemies(i, j, (int)map.capacity());
			}
		}
	};

	void killEnemies(int a, int b, int size) {

		int i = a;
		int j = b;
		while (j + 1< size) { //check to the east
			if (map[i][j+1] == '0' || map[i][j+1] == 'T')
				j++;
			else if (map[i][j + 1] == 'B')
				break;
			else if (map[i][j + 1] == 'E') {
				map[i][j+1] = 'X';
				break;
			}
		}
	
		i = a; j = b;
		while (j - 1 >= 0) { 	// check to the west
			if (map[i][j-1] == '0' || map[i][j-1] == 'T')
				j--;
			else if (map[i][j - 1] == 'B')
				break;
			else if (map[i][j - 1] == 'E') {
				map[i][j - 1] = 'X';
				break;
			}
		}

		i = a; j = b;
		while (i + 1< size) { 	// check to the south
			if (map[i+1][j] == '0' || map[i+1][j] == 'T')
				i ++;
			else if (map[i + 1][j] == 'B')
				break;
			else if (map[i + 1][j] == 'E') {
				map[i + 1][j] = 'X';
				break;
			}
		}

		i = a; j = b;
		while (i - 1>= 0) { 	// check to the north
			if (map[i-1][j] == '0' || map[i-1][j] == 'T')
				i--;
			else if (map[i - 1][j] == 'B')
				break;
			else if (map[i - 1][j] == 'E') {
				map[i - 1][j] = 'X';
				break;
			}
		}
	};

	void calculateResult() {
		for (int i = 0; i < (int)map.capacity(); i++)
		{
			for (int j = 0; j < (int)map.capacity(); j++) {
				if (map[i][j] == 'X')
					shotDownTanks++;
			}
		}
		cout<< "shot Down Tank : " << shotDownTanks << endl;
	}

	void showMap() {
		for (int i = 0; i < (int)map.capacity(); i++)
		{
			for (int j = 0; j < (int)map.capacity(); j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};

int main(void) {

	ifstream fin;
	fin.open("input.txt");
	ofstream fout("output.txt");

	string inputStr;
	int testNum;
	getline(fin, inputStr);

	try {
		testNum = atoi(inputStr.c_str());
		if (testNum > 3 || testNum < 1)
			throw testNum;
	}
	catch (int e) {
		cout << "wrong input. 1 < N <= 3" << endl;
	}
	

	for (int idx = 0; idx < testNum; idx++) {
		getline(fin, inputStr);
		int size = atoi(inputStr.c_str());
		TankGame tankgame(size); //create the game

		// set the map
		for (int i = 0; i < size; i++) {
			getline(fin, inputStr);
			char * c = strtok((char*)inputStr.c_str(), " ");
			tankgame.setElement(i, 0, c[0]);
			for (int j = 1; j < size; j++) {
				char * c = strtok(NULL, " ");
				tankgame.setElement(i, j, c[0]);
			}
		}
		cout << "initial map status" << endl;
		tankgame.showMap();

		tankgame.warBegins();

		cout << "After war" << endl;
		tankgame.showMap();
		tankgame.calculateResult();
		


	}

	fin.close();
	fout.close();
}