#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



//KVE - This engine calculates a path in a three-dimensional symmetric space of size SIZExSIZExSIZE and produces the result.


// 0 - air
// 1 - block
// 2 - exit
// 3 - executor



const int SIZE = 10; //MATRIX SIZE (DEFAULT IS 10)
const int PROCENT = 15; //BLOCK SPAWN PROCENT (DEFAULT IS 15)
const int LIMIT = 1000; //LIMIT FOR LOGICAL CHECK

void initMatrix(int matrix[SIZE][SIZE][SIZE]) { //Init matrix and generate space

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			for (int z = 0; z < SIZE; z++) {
				matrix[x][y][z] = (rand() % 100 < PROCENT) ? 1 : 0; // Random initialization based on PROCENT

			}
		}
	}

}


void setExitPosition(int matrix[SIZE][SIZE][SIZE], int exitPosition[3]) { //Function for set exit position

	matrix[exitPosition[0]][exitPosition[1]][exitPosition[2]] = 2; //Set exit position

}


void setExecutorPosition(int matrix[SIZE][SIZE][SIZE], int executorPosition[3]) { //Function for set Executor position

	matrix[executorPosition[0]][executorPosition[1]][executorPosition[2]] = 3; //Set Executor position

}

void ifExectutorIsLocked(int matrix[SIZE][SIZE][SIZE], int executorPosition[3]) { //Function for check if Executor is locked in blocks

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			for (int z = 0; z < SIZE; z++) {

				if (executorPosition[0] == x && executorPosition[1] == y && executorPosition[2] == z) {

					if (z < SIZE - 1 && matrix[x][y][z + 1] == 1) { //Check for z-coordinate
						if (z > 0 && matrix[x][y][z - 1] == 1) {

							if (y < SIZE - 1 && matrix[x][y + 1][z] == 1) { //Check for y-coordinate
								if (y > 0 && matrix[x][y - 1][z] == 1) {

									if (x < SIZE - 1 && matrix[x + 1][y][z] == 1) { //Check for x-coordinate
										if (x > 0 && matrix[x - 1][y][z] == 1) {

											cout << "Executor is locked in"; //Print lock message

										}
									}
								}
							}
						}

					}

				}
			}
		}
	}
}


void ifExitIsLocked(int matrix[SIZE][SIZE][SIZE], int exitPosition[3]) { //Function for check if exit is locked in blocks

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			for (int z = 0; z < SIZE; z++) {
				if (exitPosition[0] == x && exitPosition[1] == y && exitPosition[2] == z) {

					if (z < SIZE - 1 && matrix[x][y][z + 1] == 1) { //Check for z-coordinate
						if (z > 0 && matrix[x][y][z - 1] == 1) {

							if (y < SIZE - 1 && matrix[x][y + 1][z] == 1) { //Check for y-coordinate
								if (y > 0 && matrix[x][y - 1][z] == 1) {

									if (x < SIZE - 1 && matrix[x + 1][y][z] == 1) { //Check for x-coordinate
										if (x > 0 && matrix[x - 1][y][z] == 1) {

											cout << "Exit is locked in"; //Print lock message

										}
									}
								}
							}
						}

					}

				}
			}
		}
	}
}




void InitexecutorCurrentPosition(int matrixx[SIZE][SIZE][SIZE], int executorCurrentPosition[3], int executorPosition[3]) { //Function for init Executor current position

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			for (int z = 0; z < SIZE; z++) {

				if (executorPosition[0] == x && executorPosition[1] == y && executorPosition[2] == z) {

					executorCurrentPosition[0] = x;
					executorCurrentPosition[1] = y;
					executorCurrentPosition[2] = z;
				}
			}
		}
	}
}


int main() { //MAIN FUNCTION

	srand(time(0)); //Init seed bases on time

	int matrix[SIZE][SIZE][SIZE]; //MAIN MATRIX

	int cx; //Init an x coordinate shortcut
	int cy; //Init an y coordinate shortcut
	int cz; //Init an z coordinate shortcut

	initMatrix(matrix); //Call initMatrix function for matrix init

	int exectutor = 0; 
	int executorPosition[3] = { rand() % SIZE, rand() % SIZE, rand() % SIZE };
	int executorCurrentPosition[3];
	int exitPosition[3] = { rand() % SIZE, rand() % SIZE, rand() % SIZE };
	int attempts = 0; //Set attempts

	cx = executorCurrentPosition[0]; //Set cx
	cy = executorCurrentPosition[1]; //Set cy
	cz = executorCurrentPosition[2]; //Set cz

	bool isMoved = false; //Set flag for Executor move stage


	setExitPosition(matrix, exitPosition); //Call setExitPosition function to set exit position
	setExecutorPosition(matrix, executorPosition); //Call setExecutorPosition function to set Executor position
	ifExectutorIsLocked(matrix, executorPosition); //Call ifExectutorIsLocked function to check if Exetor is locked in the blocks
	ifExitIsLocked(matrix, exitPosition); //Call ifExitIsLocked function to check if exit is locked in the blocks
	InitexecutorCurrentPosition(matrix, executorCurrentPosition, executorPosition); //Call InitexecutorCurrentPosition function to init Executor current position

	while (executorCurrentPosition[0] != exitPosition[0] || executorCurrentPosition[1] != exitPosition[1] || executorCurrentPosition[2] != exitPosition[2]) { //MAIN CYCLE

		attempts++;
		isMoved = false;
		cx = executorCurrentPosition[0];
		cy = executorCurrentPosition[1];
		cz = executorCurrentPosition[2];

		if (attempts > LIMIT) break; //Logical check


		if (cx < exitPosition[0] && cx < SIZE - 1 && matrix[cx + 1][cy][cz] != 1) { //Check if exit position is bigger than cx 

			executorCurrentPosition[0]++;
			isMoved = true;

		}

		else if (cx > exitPosition[0] && cx > 0 && matrix[cx - 1][cy][cz] != 1) { //Check if exit position is smaller than cx 

			executorCurrentPosition[0]--;
			isMoved = true;

		}

		else if (cy < exitPosition[1] && cy < SIZE - 1 && matrix[cx][cy + 1][cz] != 1) { //Check if exit position is bigger than cy

			executorCurrentPosition[1]++;
			isMoved = true;

		}

		else if (cy > exitPosition[1] && cy > 0 && matrix[cx][cy - 1][cz] != 1) { //Check if exit position is smaller than cx 

			executorCurrentPosition[1]--;
			isMoved = true;

		}

		else if (cz < exitPosition[2] && cz < SIZE - 1 && matrix[cx][cy][cz + 1] != 1) { //Check if exit position is bigger than cz

			executorCurrentPosition[2]++;
			isMoved = true;

		}

		else if (cz > exitPosition[2] && cz > 0 && matrix[cx][cy][cz - 1] != 1) { //Check if exit position is smaller than cx 

			executorCurrentPosition[2]--;
			isMoved = true;

		}

		if (!isMoved) { //Check if Executor is locked in

			cout << "Executor is locked in!" << endl;
			break;

		}

	}

	if (executorCurrentPosition[0] == exitPosition[0] && executorCurrentPosition[1] == exitPosition[1] && executorCurrentPosition[2] == exitPosition[2]) { //Check if Executor find exit
		cout << "Executor reached the exit in " << attempts << " attempts." << endl;

	}
	else {

		cout << "Executor has been locked in!" << endl;

	}

	return 0;
}