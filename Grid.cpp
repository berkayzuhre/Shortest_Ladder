#include "Grid.h"


Grid::Grid(int A)
{

	height = A;
	check = false;

}

Grid::~Grid()
{
}


void Grid::Add_Edge(int i,int j,int N,int M,Grid** A) {


	if (i != 0) {

		Edge temp_E(i-1,j, abs(A[(i-1)*M+j]->height - height));
		pEdge.push_back(temp_E);

	}
	if (j != 0) {

		Edge temp_E(i, j-1, abs(A[(i)*M+j-1]->height - height));
		pEdge.push_back(temp_E);
	} 
	if (i != N - 1) {
		Edge temp_E( i+1, j, abs(A[(i+1)*M+j]->height -height));
		pEdge.push_back(temp_E);
	}
	if (j != M - 1) {
		Edge temp_E( i, j + 1, abs(A[(i)*M+j+1]->height - height));
		pEdge.push_back(temp_E);
	}

}
