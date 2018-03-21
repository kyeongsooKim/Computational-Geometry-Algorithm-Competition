#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Area {
private:
	int **map = NULL;
	int size;

public:
	Area(int size); //constructor
	~Area();
	void initArea();
	int getValue(int i, int j);
	void setValue(int i, int j, int value);
	int showSafeSpot();
	void showAllArea();
	void getBomb(int i, int j, int bomb);

};

class Bomb {
private:
	int px;
	int py;
	int bombType;

public:
	Bomb(int px, int py, int bombType) {
		this->px = px;
		this->py = py;
		this->bombType = bombType;
	}
};

Area::Area(int size) {
	this->size = size;
	map = new int*[size];//dynamic memory allocation using new.
	for (int i = 0; i < size; i++)
	{
		map[i] = new int[size];
	}

}

Area::~Area() {// free memory allocation. 

	for (int i = 0; i < size; i++)
	{
	delete[] map[i];
	}
	delete[] map; 
}


void Area::initArea() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = 0;
		}
	}
}

int Area::getValue(int i, int j) {
	if (i >= size || j >= size) {
		throw "Array index out of bounds";
	}
	return map[i][j];
}

void Area::setValue(int i, int j, int value) {
	if (i >= size || j >= size) {
		throw "Array index out of bounds";
	}
	else {
		map[i][j] = value;
	}
}

int Area::showSafeSpot() {
	int safeSpotCount = size * size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] != 0)
				safeSpotCount--;
		}
	}
	return safeSpotCount;
}

void Area::showAllArea() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ('A' <= map[i][j] && map[i][j] <= 'C') {
				cout << (char)map[i][j] << " ";
			}
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Area::getBomb(int i, int j, int bomb) {
	switch (bomb) {
	case 'C':
		if (i > 2) map[i - 3][j] = 1;
		if (j > 2) map[i][j - 3] = 1;
		if (i < size - 3) map[i + 3][j] = 1;
		if (j < size - 3) map[i][j + 3] = 1;
	case 'B': if (i > 1) map[i - 2][j] = 1;
		if (j > 1) map[i][j - 2] = 1;
		if (i < size - 2) map[i + 2][j] = 1;
		if (j < size - 2) map[i][j + 2] = 1;
	case 'A': if (i > 0) map[i - 1][j] = 1;
		if (j > 0) map[i][j - 1] = 1;
		if (i < size - 1) map[i + 1][j] = 1;
		if (j < size - 1) map[i][j + 1] = 1;
	}
	map[i][j] = bomb;
}

int main()
{
	ofstream fout("output.txt");
	ifstream fin("input.txt");

	string str;
	int testNum;
	int ptx = 0, pty = 0; // x and y coordinates

	getline(fin, str);
	testNum = atoi(str.c_str()); //c_str() : change std::string to const char* format


	try {
		for (int i = 0; i <testNum; i++) {
			getline(fin, str);
			Area area(atoi(str.c_str())); //creates the area.
			area.initArea();
			getline(fin, str);

			// "String[] bombsInfo = str.split(",");" in Java
			string bombsInfo[3];
			char * c_bumbsInfo[3];
			int startIdx = 0;
			int endIdx;

			for (int j = 0; j < 3; j++) {
				endIdx = str.find(",", startIdx);
				bombsInfo[j] = str.substr(startIdx, endIdx - startIdx);
				startIdx = endIdx + 1;
				c_bumbsInfo[j] = (char*)bombsInfo[j].c_str(); //to use strtok()
			}
			// "String[] bombsInfo = str.split(",");" in Java ended

			char * result;
			char bombType = 'A';
			for (int j = 0; j < 3; j++) {
				int bombIsReady = 0;
				result = strtok(c_bumbsInfo[j], " ");

				while (result != NULL) //push every bombs for each type
				{
					if (bombIsReady == 0) {
						ptx = atoi(result);
						bombIsReady++;
						result = strtok(NULL, " ");
					}
					else if (bombIsReady == 1) //getbomb whenver coordinate(x,y) is made
					{
						pty = atoi(result);
						bombIsReady++;
						area.getBomb(ptx, pty, bombType);
						ptx = 0;
						pty = 0;
						bombIsReady = 0;
						result = strtok(NULL, " ");
					}
				}

				bombType++;
			}

			fout << "#" << (i + 1) << " " << area.showSafeSpot() << endl;
			area.showAllArea();
		}

		fin.close();
		fout.close();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	return 0;

}