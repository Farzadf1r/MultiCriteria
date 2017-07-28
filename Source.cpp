#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>
#include <string>
#include <vector>

using namespace std;


int Trapezoid(int x, int a, int b, int c, int d)  //  function for fuzzy trapezoidal number (a,b,c,d)
{

	float t;

	if (x <= a) {
		t = 0;
	}

	else if ((a <= x) && (x <= b)) {
		t = ((x - b) / (b - a));
	}

	else if ((c <= x) && (x <= d)) {
		t = ((d - x) / (d - c));
	}

	else if (d <= x) {
		t = 0;
	}

	else if ((b <= x) && (x <= c)) {
		t = 1;
	}

	else {
		t = 0;
	}
	
	return t;
}

void NumericValues()
{
	vector<vector<long double>> assignedDM{
		{ 0,1,1.263,1.579,1,1.263 },
		{ 1,0,1,1.579,1.474,1.895 },
		{ 1.263,1,0,1.579,1.895,2 },
		{ 1.579,1.579,1.579,0,1.579,1.579 },
		{ 1,1.474,1.895,1.579,0,1 },
		{ 1.263,1.895,2,1.579,1,0 } };

	for (int i = 0; i<6; i++)    //This loops on the rows.
	{

		for (int j = 0; j<6; j++) //This loops on the columns
		{
			cout << assignedDM[i][j] << " \t";
		}
		cout << endl << endl;
	}
	cout << "-----------------------------------------------" << endl << endl;
}





void DynamicPerformanceMatriX1() // Matrix of dynamic size
{

	int row1, col1;
	float sj;
	float min;
	float max;


	cout << "Enter no of rows of the performance matrix : ";
	cin >> row1;
	cout << "Enter no of columns of the performance matrix : ";
	cin >> col1;
	// max and min condition 


	//using dynamic memory to initialize matrices 
	float** P1matrix = new float*[row1];
	for (int i = 0; i < row1; ++i)
		P1matrix[i] = new float[col1];
	int p = 0, q = 0;

	for (unsigned i = 0; i<row1; i++) {
		for (unsigned j = 0; j<col1; j++) {
			cout << "Enter the " << i + 1 << " * " << j + 1 << " entry: ";
			cin >> P1matrix[i][j];
		}
	}

	cout << endl << endl;
	cout << "Performance Matrix X1 ( P1matrix[i][j] ) is: " << endl << endl;
	for (unsigned i = 0; i<row1; i++) {
		for (unsigned j = 0; j<col1; j++) {
			cout << P1matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}
	

	min = P1matrix[0][0];
	max = P1matrix[0][0];


	for (unsigned i = 0; i < row1; i++) {
		for (unsigned j = 0; j < col1; j++) {

			if (P1matrix[i][j] > max)
				max = P1matrix[i][j];

			if (P1matrix[i][j] < min)
				min = P1matrix[i][j];

		}
	}
	
	cout << endl;
	cout << "Min is: " << min << endl;
	cout << "Max is: " << max << endl;
	

	//Local preference relations

	cout << endl
		<< "Please determin the threshold sj: ";
	cin >> sj;

	cout << endl;


	for (unsigned i = 0; i<row1; i++) {
		for (unsigned j = 0; j<col1; j++) {
			for (unsigned k = 0; k<row1; k++) {

				if (abs(P1matrix[i][j] - P1matrix[k][j])<sj) {
					cout << "(a" << i << " H" << j << " a" << k << ")= " << "I"
						<< endl << endl;
				}

				else if (abs(P1matrix[i][j] - P1matrix[k][j])>sj) {
					cout << "(a" << i << " H" << j << " a" << k << ")= " << "FSD or SSD or TSD"
						<< endl << endl;
				}

				else cout << "(a" << i << " H" << j << " a" << k << ")= " << "non SD"
					<< endl << endl;

			}
		}
		cout << endl << endl;
	}
	cout << endl;
}




void DynamicPerformanceMatriX2() // Matrix of dynamic size
{

	int row2, col2;
	int sj;
	cout << "Enter no of rows of the performance matrix 2: ";
	cin >> row2;
	cout << "Enter no of columns of the performance matrix 2: ";
	cin >> col2;

	float** P2matrix = new float*[row2];
	for (int i = 0; i < row2; ++i)
		P2matrix[i] = new float[col2];
	int p = 0, q = 0;

	for (unsigned i = 0; i<row2; i++) {
		for (unsigned j = 0; j<col2; j++) {
			cout << "Enter the " << i + 1 << " * " << j + 1 << " entry: ";
			cin >> P2matrix[i][j];
		}
	}

	cout << endl << endl;
	cout << "Performance Matrix X2 ( P2matrix[i][j] ) is: " << endl << endl;
	for (unsigned i = 0; i<row2; i++) {
		for (unsigned j = 0; j<col2; j++) {
			cout << P2matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}

	cout << endl
		<< "Please determin the threshold sj: ";
	cin >> sj;

	cout << endl;


	for (unsigned i = 0; i<row2; i++) {
		for (unsigned j = 0; j<col2; j++) {
			for (unsigned k = 0; k<row2; k++) {

				if (abs(P2matrix[i][j] - P2matrix[k][j])<sj) {
					cout << "(a" << i << " H" << j << " a" << k << ")= " << "I"
						<< endl << endl;
				}

				else if (abs(P2matrix[i][j] - P2matrix[k][j])>sj) {
					cout << "(a" << i << " H" << j << " a" << k << ")= " << "FSD or SSD or TSD"
						<< endl << endl;
				}

				else cout << "(a" << i << " H" << j << " a" << k << ")= " << "non SD"
					<< endl << endl;

			}
		}
		cout << endl << endl;
	}

	cout << endl;
}

int main()
{
	int i;
	int *po;
	cout << "Enter the number of Matrices: ";
	cin >> i;
	po = new int[i];
	cout << endl;

	for (int r = 0; r < i; r++)
	{
		cout << "Matrix Number " << r + 1 << " :" << endl << endl;

		DynamicPerformanceMatriX1();
		

		cout << endl
			<< "Numerical Values Assigned to the distance measure D (ai D ak): " << endl
			<< endl;
		NumericValues();


	}

	
	system("pause");

	return 0;

}



