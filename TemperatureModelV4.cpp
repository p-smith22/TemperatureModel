/****************************************************************************************************
* Parker Smith Fall 2023
* Purpose: The purpose of this code is to create a two dimensional array that will have a set temperature on each of the edges. After each iteration, the array should adjust and try to average out the value of the temperatues on the middle tiles. The code should stop creating iterations once the differences in every tile because less than epsilon. 
* Input Needed: The user needs to input the size of the array, the temperature on each of the four edges, and epsilon (the allowable delta)
* Output Expected: The user should expect to receieve the original array as well as each iteration until a delta less than epsiolon is achieved. 
* Processing: The code first prompts the user to input all of the above values, and call a funciton to make sure they are within the allowbale range. Then, the code will put all these valeus into a function call for the original array. This array will set all values to zero, assign the edges to the input values, and calculate the corners by averaging the two adjacent tiles. Then, the main function will call another programmer function and send the new array and epsilon. Within this next function, a series of for loops will be run that will continuously recalculate the averages of the tiles. There is an embedded if statement that ensures that the difference is greater than epsilon. As soon as it is not, a test variable is changed which will trip the while condition at the end of the do loop. 
* Test Values: Array Dimensions...5x7, Edge Values...Top - 100 Left - 75 Right - 75 Bottom - 90, Epsilon...0.01
* 
* Original Array:
* 87.5	100.0	100.0	100.0	100.0	100.0	87.6
* 75.0	0		0		0		0		0		75.0
* 75.0	0		0		0		0		0		75.0
* 75.0	0		0		0		0		0		75.0
* 82.5	90.0	90.0	90.0	90.0	90.0	82.5
* 
* Final Iteration:
* 87.5	100.0	100.0	100.0	100.0	100.0	87.5
* 75.0	87.9	92.6	93.8	92.6	87.9	75.0
* 75.0	83.2	88.6	90.0	88.6	83.9	75.0
* 75.0	84.2	87.9	89.0	87.9	84.2	75.0
* 82.5	90.0	90.0	90.0	90.0	90.0	82.5
******************************************************************************************************/

#include <iostream>		//library files
#include <iomanip>

using namespace std;

const int max_r = 26, max_c = 30;		//defines max dimensions of array

void value_check(double&);														//function prototypes
void initial(double[][30], int, int, double, double, double, double);
void inside_rows(double[][30], int, int, double);

int main()		//main function
{
	int rows, columns;			//variable declarations
	double Array[max_r][30];
	double top, left, right, bottom, epsilon;

	cout << "PLEASE INPUT THE NUMBER OF ROWS IN THE ARRAY: \n";		//prompt user for rows
	cin >> rows;
	
	while (rows > 26 || rows < 3)		//checks value, forces reinput if invalid...has to be above 3 to ensure there are interior tiles
	{
		cout << "ERROR...INVLAID INPUT...PLEASE INPUT A VALUE GREATER THAN Three AND LESS THAN OR EQUAL TO 26: \n";
		cin >> rows;
	}

	cout << "PLEASE INPUT THE NUMBER OF COLUMNS IN THE ARRAY : \n";		//prompt user for columns
	cin >> columns;

	while (columns > 30 || columns < 3)		//checks value, forces reinput if invalid...has to be above 3 to ensure there are interior tiles
	{
		cout << "ERROR...INVALID INPUT...PLEASE INPUT A VALUE GREATER THAN Three AND LESS THAN OR EQUAL TO 30: \n";
		cin >> columns;
	}

	cout << "PLEASE INPUT THE TEMPERATURE ALONG THE TOP EDGE: \n";		//prompts for edge temperatures, function call to check values
	cin >> top;
	value_check(top);

	cout << "PLEASE INPUT THE TEMPERATURE ALONG THE LEFT EDGE: \n";		//prompts for edge temperatures, function call to check values
	cin >> left;
	value_check(left);

	cout << "PLEASE INPUT THE TEMPERATURE ALONG THE RIGHT EDGE: \n";		//prompts for edge temperatures, function call to check values
	cin >> right;
	value_check(right);

	cout << "PLEASE INPUT THE TEMPERATURE ALONG THE BOTTOM EDGE: \n";		//prompts for edge temperatures, function call to check values
	cin >> bottom; 
	value_check(bottom);

	cout << "WHAT IS THE VALUE OF EPSILON? \n";		//prompt for epsilon
	cin >> epsilon;
	cout << endl;

	initial(Array, rows, columns, top, left, right, bottom);		//function call to build original array

	inside_rows(Array, rows, columns, epsilon);		//function call for inside rows

	return 0;		//end main
}

/****************************************************************************************************
* Purpose: The purpose of this function is to ensure the temperature input is within the allowable range.
* Input Needed: The function pulls the temperature inputs for each edge and forces the user to reinput if they are invalid. 
* Output Expected: The function will verify the temperature and return a new value if the initial value is invalid. 
* Processing: The function uses a while loop to run a reprompt as long as the input is not valid. 
* Test Values: N/A
******************************************************************************************************/

void value_check(double& temperature)		//programmer function
{
	while (temperature < 0 || temperature > 300)		//checks temperature of each edge, forces reinput if invalid
	{
		cout << "ERROR...INVALID INPUT...PLEASE INPUT A VALUE GREATER THAN OR EQUAL TO ZERO AND LESS THAN OR EQUAL TO 300: \n";
		cin >> temperature;
	}
}

/****************************************************************************************************
* Purpose: The purpose of this function is to construct the original array with the edge temperatures. 
* Input Needed: The function needs the array, the size of the array, and the respective edge temperatures.
* Output Expected: The function will return the new array, set up similar to the format below. 
* Processing: The function will set all values of the array to zero. Then, it will apply the temperatures to each edge, leaving the corners as zero. Finally, it will average the two adjacent tiles and calculate the corner values. All of this is done with for loops. 
* Test Values: Array Dimensions...5x7, Edge Values...Top - 100 Left - 75 Right - 75 Bottom - 90, Epsilon...0.01
* 
* Original Array:
* 87.5	100.0	100.0	100.0	100.0	100.0	87.6
* 75.0	0		0		0		0		0		75.0
* 75.0	0		0		0		0		0		75.0
* 75.0	0		0		0		0		0		75.0
* 82.5	90.0	90.0	90.0	90.0	90.0	82.5
******************************************************************************************************/

void initial(double Array[][30], int rows, int columns, double top, double left, double right, double bottom)		//programmer function
{
	int s, n;		//variable declarations

		for (n = 0; n < rows; n++)			//nested for loop to assign entire array to zero
		{
			for (s = 0; s < columns; s++)
			{
				Array[n][s] = 0;
			}
		}
	
		for (n = 1; n < (columns - 1); n++)		//assings top edge
		{
			Array[0][n] = top;
		}
	
		for (n = 1; n < (columns - 1); n++)		//assigns bottom edge
		{
			Array[(rows-1)][n] = bottom;
		}
		
		for (n = 1; n < (rows - 1); n++)		//assigns left edge
		{
			Array[n][0] = left;
		}

		for (n = 1; n < (rows - 1); n++)		//assigns right edge
		{
			Array[n][(columns-1)] = right;
		}
		
		Array[0][0] = (Array[1][0] + Array[0][1]) / 2.0;		//calculations for corners, essentially finds values of the two adjacent tiles and averages them for corner values
		Array[0][(columns - 1)] = (Array[0][(columns - 2)] + Array[1][(columns - 1)]) / 2.0;
		Array[(rows - 1)][0] = (Array[(rows - 2)][0] + Array[(rows - 1)][1]) / 2.0;
		Array[(rows - 1)][(columns - 1)] = (Array[(rows - 2)][(columns - 1)] + Array[(rows - 1)][(columns - 2)]) / 2.0;

		cout << "ORIGNIAL ARRAY: \n\n";		//title for original array

		for (n = 0; n < rows; n++)		//nested for to output original function
		{
			for (s = 0; s < columns; s++)
			{
				cout << setw(6) << setprecision(1) << fixed << Array[n][s] << "\t";		//format output
			}
			cout << endl;
		}
		cout << endl;
}

/****************************************************************************************************
* Purpose: The purpose of this function is to find the value of the inside tiles by averaging the 4 adjacent tiles. Then, the code will contiually run this until the difference is less than epsilon. 
* Input Needed:	The function will pull the array and epsilon from main. 
* Output Expected: The function should output each iteration, with the last output iteration being the final array. 
* Processing: The function uses a do while loop to rerun the averaging until the test variable gets updated. Within the while, a for loop is continuously run to recalculate the averages of each tile. Each average is subtracted from its previous value to check the epsilon of the tile. If the value is greater than the input epsilon, then the test variable remains and the loop will run again. When everything remains less than epsilon, the test variable is changed and the loop will end itself. 
* Test Values: Array Dimensions...5x7, Edge Values...Top - 100 Left - 75 Right - 75 Bottom - 90, Epsilon...0.01
* 
* Final Iteration:
* 87.5	100.0	100.0	100.0	100.0	100.0	87.5
* 75.0	87.9	92.6	93.8	92.6	87.9	75.0
* 75.0	83.2	88.6	90.0	88.6	83.9	75.0
* 75.0	84.2	87.9	89.0	87.9	84.2	75.0
* 82.5	90.0	90.0	90.0	90.0	90.0	82.5
******************************************************************************************************/

void inside_rows(double Array[][30],int rows, int columns, double epsilon)		//programmer function
{
	int n, s, i = 1, test;		//variable declarations
	double temp, difference;	

	do					
	{	
		test = 0;		//sets test variable
		for (n = 1; n < (rows - 1); n++)		//nested for that goes through each tile on the interior
		{
			for (s = 1; s < (columns - 1); s++)
			{
				temp = (Array[(n - 1)][s] + Array[(n + 1)][s] + Array[n][(s - 1)] + Array[n][(s + 1)]) / 4.0;		//calculates the average of each tile with the four adjacent tiles, assings it to a temporary variable
				difference = Array[n][s] - temp;		//finds the difference between the new value and the old value

				if (difference > epsilon || difference < (-epsilon))		//reassings the test variable if the difference is larger than epsilon
				{
					test = 1; 
				}

				Array[n][s] = temp;			//reassings new value to array
			}
		} 

		cout << "ITERATION " << i << ": \n\n";		//iteration heading

		for (n = 0; n < rows; n++)		//outputs array
		{
			for (s = 0; s < columns; s++)
			{
				cout << setw(6) << setprecision(1) << fixed << Array[n][s] << "\t";		//format output
			}
			cout << endl;
		}
		cout << endl;

		i++;		//update, only used to change the number in the iteration heading

	} while (test == 1);		//if test variable was tripped in the above if statement, the loop is run again
}