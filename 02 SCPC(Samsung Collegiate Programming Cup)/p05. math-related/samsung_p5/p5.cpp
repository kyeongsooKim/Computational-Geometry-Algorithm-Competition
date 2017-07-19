#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

struct Point {
	int x;
	int y;
};

class Radar {
private:
	Point ctr; //centre of a Radar
	int r; // radius of a Radar
	int totalEnem; // total enimies
	vector<Point> foundEnem; // enemies cought by radar
	
public:
	bool checkEnemy(Point p);
	void printEnemies(ofstream* fout);
	Radar(int x, int y, int r, int n); // constructor

};

void Radar::printEnemies(ofstream* fout) {
	vector<Point>::const_iterator pos;    //vector container¿« iterator
	int totalnum = 0;
	for (pos = foundEnem.begin(); pos != foundEnem.end(); ++pos) {
		cout << '('<< pos->x << ' ' << pos->y
			<< ") is the position of enemy caught by radar"<< endl;
		totalnum++;
	}
	cout << "total number of enemies covered by radar : " << totalnum << "\n\n";
	*fout << totalnum << endl;
}

bool Radar::checkEnemy(Point p) {
	int xdiff, ydiff;
	xdiff = p.x - ctr.x;
	ydiff = p.y - ctr.y;
	//pow((double)xdiff, 2) = simply xdiff*xdiff
	if (sqrt(pow((double)xdiff, 2) + pow((double)ydiff, 2)) <= r) {
		foundEnem.push_back(p);
		return true;
	}
	return false;
}

Radar::Radar(int x, int y, int r, int n) {
	this->ctr.x = x;
	this->ctr.y = y;
	this->r = r;
	this->totalEnem = n;
}

int main(void) {

	ofstream fout("output.txt");
	ifstream fin("input.txt");
	string str;

	getline(fin, str);
	int testNum;

	try {
		testNum = atoi(str.c_str());
		if (testNum > 7 || testNum <= 3)
			throw testNum;
	}
	catch (int e) {
		cout << "test case should be within 3 < N <= 5" << endl;
		return 0;
	}

	for (int i = 0; i < testNum; i++) {
		getline(fin, str);
		int x, y, r, n;
		x = atoi(strtok((char*)str.c_str(), " "));
		y = atoi(strtok(NULL, " "));
		r = atoi(strtok(NULL, " "));
		n = atoi(strtok(NULL, " "));
		Radar radar(x, y, r, n); // create rador with given radius and center.

		getline(fin, str);
		
		Point p;
		p.x = atoi(strtok((char*)str.c_str(), " "));
		p.y = atoi(strtok(NULL, " "));
		radar.checkEnemy(p); // check if the enemy is within variable of Radar.

		char * nextStr;
		while ((nextStr = strtok(NULL, " ")) != NULL) {
			Point p;
			p.x = atoi(nextStr);
			p.y = atoi(strtok(NULL, " "));
			radar.checkEnemy(p);
		}
		cout << '#' << i + 1 << endl;
		fout << '#' << i + 1 << " ";
		radar.printEnemies(&fout);
		
	}

	fin.close();
	fout.close();

	return 0;
}