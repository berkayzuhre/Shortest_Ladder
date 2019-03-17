#include <iostream>
#include <sstream>
#include <fstream>
#include <queue> 
#include "Grid.h"

struct Compare {
	bool operator()(Edge const & p1, Edge const & p2) {
		// return "true" if "p1" is ordered before "p2", for example:
		return p1.ladder_lenght > p2.ladder_lenght;
	}
};


int main(int argc, char* argv[]) {
	// below reads the input file
	// in your next projects, you will implement that part as well
	if (argc != 3) {
		cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
		return 1;
	}

	ifstream infile(argv[1]);

	int N, M;



	Grid* Gridland[1000000];



	priority_queue<Edge,vector<Edge>,Compare> direction;



	//read Gridland height and width
	infile >> N>>M;

	//read Gridland
	int temp_Num;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			infile >> temp_Num;
			Grid* temp1 =  new Grid(temp_Num);
			Gridland[i*M+j]=temp1;

		}

	}


	int Q;

	int row, col;

	Pos start, end;

	infile >> Q;

	for (int i = 0; i < 1; i++) {
		infile >> row >> col;
		start.column = col - 1; start.row = row - 1;
		infile >> row >> col;
		end.column = col - 1; end.row = row - 1;

	}

	Pos pivot = start;

	Gridland[(pivot.row)*M+pivot.column]->minLadder = 0;

	int Ladder = -1;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
Gridland[i*M+j]->Add_Edge(i,j,N,M,Gridland);
		}

	}


	while (!Gridland[end.row*M+end.column]->check) {

		Gridland[pivot.row*M+pivot.column]->check = true;
		


		for (auto Edges : Gridland[pivot.row*M+pivot.column]->pEdge) {
			if (!Gridland[Edges.sinkr*M+Edges.sinkc]->check) {
				direction.push(Edges);
			}
		}

		pivot.row = direction.top().sinkr;
		pivot.column = direction.top().sinkc;


		if (direction.top().ladder_lenght > Ladder) {

			Gridland[pivot.row*M+pivot.column]->minLadder = direction.top().ladder_lenght;
			Ladder = direction.top().ladder_lenght;
		}

		else if (direction.top().ladder_lenght <= Ladder) {
			Gridland[pivot.row*M+pivot.column]->minLadder = Ladder;
		}

		direction.pop();
	}


	ofstream myfile;
	myfile.open(argv[2]);
	myfile<<Gridland[end.row*M+end.column]->minLadder;
	myfile.close();






	return 0;
}
