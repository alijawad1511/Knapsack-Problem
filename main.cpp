#include<iostream>
using namespace std;
int main()
{
	const int CAPACITY = 8;					// Knapsack Capacity
	const int OBJECTS = 4;					// Objects
	int p[OBJECTS+1] = { 0,1,2,5,6 };			// Profits
	int wt[OBJECTS+1] = { 0,2,3,4,5 };		// Weights


	// Items/Objects
	cout << "@@@( Items/Objects Available )@@@\n\n";
	for (int i = 1; i <= OBJECTS; i++)
		cout << "(" << wt[i] << ", " << p[i] << ")\t";
	cout << "\n\n\n";

	// Memorization Table Declaration
	int V[5][9];


	// Initialize first row 0
	for (int w = 0; w <= CAPACITY; w++)
		V[0][w] = 0;

	// Initialize first column 0
	for (int i = 0; i <= OBJECTS; i++)
		V[i][0] = 0;



	// Initializing Memorization Table
	for (int i = 1; i <= OBJECTS; i++)
	{
		for (int w = 0; w <= CAPACITY; w++)
		{
			if (wt[i] <= w)
				V[i][w] = max(V[i - 1][w], (V[i - 1][w - wt[i]] + p[i]));
			else
				V[i][w] = V[i - 1][w];
		}
	}


	//Display Memorization Table
	cout << "@@@( Memorization Table )@@@\n\n";
	for (int i = 0; i <= OBJECTS; i++)
	{
		for (int w = 0; w <= CAPACITY; w++)
			cout << V[i][w] << "\t";
		cout << endl;
	}


	//Display Maximum Profit
	cout << "\nMaximum Profit : " << V[OBJECTS][CAPACITY]<<"\n\n";



	// Selected Oj=bjects/Items(Weights) in Knapsack to get max profit
	int i = OBJECTS;
	int j = CAPACITY;

	cout << "@@@( Selected Items in Knapsack for Maximum Profit)@@@\n\n";
	while (i > 0 && j > 0)
	{
		if (V[i][j] == V[i - 1][j])
		{
			i--;
		}
		else
		{
			cout << "(" << wt[i] << ", " << p[i] << ")\t";
			j = j - wt[i];
			i--;
		}
	}
	cout << "\n\n";

	return 0;
}