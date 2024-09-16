#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>
#include <utility>
#include <sstream>
#include <ctype.h>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void createMatrix(size_t countRows, size_t countColumns, vector<vector<int>> &numbers) {
	for (size_t rows = 0; rows < countRows; rows++)
	{
		vector<int> inputRow;
		for (int columns = 0; columns < countColumns; columns++)
		{
			int number;
			cin >> number;
			inputRow.push_back(number);
		}
		numbers.push_back(inputRow);
	}
} 

int main()
{
	size_t countRows, countColumns;
	cin >> countRows >> countColumns;
	vector<vector<int>> numbers;

	createMatrix(countRows, countColumns, numbers);

	int sumMax = INT8_MIN;
	vector<int>vMaxSum, vCurrent;
	const size_t rowsInternalMatrix = 3,  columnsInternalMatrix = 3;

	for (int rows = 0; rows < countRows - 2; rows++)
	{
		for (int columns = 0; columns < countColumns - 2; columns++)
		{
			int sum = 0;
			for (size_t r = 0; r < rowsInternalMatrix; r++)
			{
				for (size_t c = 0; c < columnsInternalMatrix; c++)
				{
					sum += numbers[rows + r][columns + c];
					vCurrent.push_back(numbers[rows + r][columns + c]);
				}
			}
			if (sumMax < sum)
			{
				sumMax = sum;
				vMaxSum.swap(vCurrent);
				vCurrent.clear();
			}
			vCurrent.clear();
		}
	}

	cout << "Sum = " << sumMax << endl;
	size_t counter = 0;
	for (int number : vMaxSum)
	{
		cout << number << " ";
		counter++;
		if (counter == 3)
		{
			cout << endl;
			counter = 0;
		}

	}

	return 0;
}


/*

1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

*/