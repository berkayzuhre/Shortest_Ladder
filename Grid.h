#pragma once
#include <list>
#include <stdlib.h>
using namespace std;

struct Pos {
	int row, column;
};

class Edge {
public:

	int sinkc;
	int sinkr;
	int ladder_lenght;

	Edge(int sink_r,int sink_c,int l_l) {

		sinkr = sink_r;
		sinkc = sink_c;
		ladder_lenght = l_l;

	}
};



class Grid
{
public:
	Grid(int);
	~Grid();


	bool check;
	int height;
	int minLadder;

	list<Edge> pEdge;

	void Add_Edge(int,int,int,int,Grid**);


private:

};

