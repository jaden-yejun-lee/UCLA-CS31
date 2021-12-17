#include "grid.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

// function for determining whether or not a plan has the correct form
bool hasCorrectForm(string plan) {
	// if a plan is an empty string return true
	if (plan == "") {
		return true;
	}
	// if it doesnt end in a turn letter return false
	if (plan.at(plan.size() - 1) != 'L' && plan.at(plan.size() - 1) != 'R' && plan.at(plan.size() - 1) != 'l' && plan.at(plan.size() - 1) != 'r')
		return false;

	// if there are 3 numbers in a row within the plan return false
	for (int j = 0; j != plan.size(); j++)
		if (isdigit(plan.at(j)))
			if (j + 2 < plan.size() && (isdigit(plan.at(j + 1))) && (isdigit(plan.at(j + 2))))
				return false;


	int count = 0;
	// for every integer and turn value, the count increments by 1
	for (int i = 0; i < plan.size(); i++) {
		if ((plan.at(i)) == 'L' || plan.at(i) == 'R' || plan.at(i) == 'l' || plan.at(i) == 'r' || isdigit(plan.at(i)))
			count++;
	}


	// if the count equals the size of the plan return true
	if (count == plan.size())
		return true;
	else
		return false;
}

// function for determining the number of steps the car can take
int determineSafeDistance(int r, int c, char dir, int maxSteps) {
	int x = getRows();
	int y = getCols();

	// if the car starts anywhere off the grid, return -1
	if (r > x || r < 1)
		return -1;
	if (c > y || c < 1)
		return -1;
	// if there is a wall at the cars starting point, return -1
	if (isWall(r, c))
		return -1;
	// if maxsteps is a negative number, return -1
	if (maxSteps < 0)
		return -1;

	// if the direction is (east, west, north, south), iterate through the path (east, west, north, south)ward and determine number of possible steps
	if (dir == 'E' || dir == 'e') {
		int count = 0;
		for (int i = 1; i < y; i++) {
			// if the car's position is not at the edge, there isn't a wall in front of the car, and the maximum number of steps < the count, increment count and move position 1 to the (east, west, north, south)
			if (c != y && !isWall(r, c + 1) && maxSteps != count) {
				count++;
				c += 1;
			}
			else
				break;
		}
		//eventually return the number of steps
		return count;
	}

	if (dir == 'W' || dir == 'w') {
		int count = 0;
		for (int j = c; j > 0; j--) {
			if (c != 1 && !isWall(r, c - 1) && maxSteps != count) {
				count++;
				c -= 1;
			}
			else
				break;
		}
		return count;
	}

	if (dir == 'N' || dir == 'n') {
		int count = 0;
		for (int j = r; j > 0; j--) {
			if (r != 1 && !isWall(r - 1, c) && maxSteps != count) {
				count++;
				r -= 1;
			}
			else
				break;
		}
		return count;
	}


	if (dir == 'S' || dir == 's') {
		int count = 0;
		for (int i = 1; i < x; i++) {
			if (r != x && !isWall(r + 1, c) && maxSteps != count) {
				count++;
				r += 1;
			}
			else
				break;
		}
		return count;
	}
	// if dir is not a direction letter, return -1
	return -1;
}

// function where car follows plan
int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nSteps) {

	// if the plan doesn't have the correct form, return 2;
	if (!hasCorrectForm(plan)) {
		return 2;
	}
	else {
		int x = getRows();
		int y = getCols();
		// if the start position is not within the grid, return 2
		if (sr > x || sr < 1 || sc > y || sc < 1) {
			return 2;
		}
		// if the end position is not within the grid, return 2
		if (er > x || er < 1 || ec > y || ec < 1) {
			return 2;
		}
		// if there is a wall at the start position, return 2
		if (isWall(sr, sc)) {
			return 2;
		}
		// if there is a wall at the end position, return 2
		if (isWall(er, ec)) {
			return 2;
		}
		// if the direction character is not upper/lower case (N,E,W,S), return 2
		if (dir != 'N' && dir != 'n' && dir != 'E' && dir != 'e' && dir != 'S' && dir != 's' && dir != 'W' && dir != 'w')
			return 2;

		nSteps = 0;
		int r = sr;
		int c = sc;

		// iterate through each character of the whole plan
		for (int i = 0; i != plan.size(); i++) {

			// if the car's new position is past the edge of the grid, return 3
			if (r > x || c > y) {
				return 3;	
			}


			int t;

			// if dir equals (N,E,S,W) and if the character in focus is a direction letter, translate current direction(dir) accordingly
			if (dir == 'N' || dir == 'n') {
				if (plan.at(i) == 'L' || plan.at(i) == 'l') {
					dir = 'W';
				}
				if (plan.at(i) == 'R' || plan.at(i) == 'r') {
					dir = 'E';
				}
			}
			else if (dir == 'E' || dir == 'e') {
				if (plan.at(i) == 'L' || plan.at(i) == 'l') {
					dir = 'N';
				}
				if (plan.at(i) == 'R' || plan.at(i) == 'r') {
					dir = 'S';
				}
			}
			else if (dir == 'S' || dir == 's') {
				if (plan.at(i) == 'L' || plan.at(i) == 'l') {
					dir = 'E';
				}
				if (plan.at(i) == 'R' || plan.at(i) == 'r') {
					dir = 'W';
				}
			}
			else
			{
				if (plan.at(i) == 'L' || plan.at(i) == 'l') {
					dir = 'S';
				}
				if (plan.at(i) == 'R' || plan.at(i) == 'r') {
					dir = 'N';
				}
			}
			// if character in focus is a digit, perform this sequence
			if (isdigit(plan.at(i))) {
				int q = i + 1;
				// if there are two numbers adjacent to each other, count the two number characters as one individual number
				if (isdigit(plan.at(q))) {
					// the first number character represents the tens and gets multiplied by 10 and the second number represents the ones place so it adds the second number to the first one
					t = (((plan.at(i) - '0') * 10) + plan.at(q) - '0');
					i++;
				}
				else {
					t = plan.at(i) - '0';
				}
				int f = determineSafeDistance(r, c, dir, t);
				// if the number in plan is less than the safe distance of steps, add/subtract t accordingly depending on the direction
				if (t <= f) {
					if (dir == 'N' || dir == 'n') {
						r = r - t;
					}
					if (dir == 'E' || dir == 'e') {
						c = c + t;
					}
					if (dir == 'W' || dir == 'w') {
						c = c - t;
					}
					if (dir == 'S' || dir == 's') {
						r = r + t;
					}
					// add t to the total number of steps taken
					nSteps += t;

				}
				else {
					// add the safe distance that the car could have gone and return 3
					nSteps += f;
					return 3;
				}
			}

		}

		// if car ends up at (er,ec) return 0
		if (r == er && c == ec)
			return 0;
		// else if car does not end up at (er,ec) return 1
		else
			return 1;
	}
}

int main()
{
	setSize(3, 4);
	setWall(1, 4);
	setWall(2, 2);
	setWall(3, 2);
	assert(hasCorrectForm("2R1r"));
	assert(!hasCorrectForm("1Lx"));
	assert(hasCorrectForm("")); 
	assert(!hasCorrectForm("2R1r3")); 
	assert(!hasCorrectForm("231R1r"));
	assert(!hasCorrectForm("23l R1r")); 
	assert(hasCorrectForm("LL2R2R2L1R")); 
	assert(hasCorrectForm("ll2r2r2l1r"));
	assert(hasCorrectForm("r"));
	assert(!hasCorrectForm(" ")); 

	assert(determineSafeDistance(3, 1, 'N', 2) == 2);
	assert(determineSafeDistance(4, 1, 'N', 2) == -1); 
	assert(determineSafeDistance(0, 1, 'N', 2) == -1);
	assert(determineSafeDistance(2, 5, 'N', 2) == -1);
	assert(determineSafeDistance(1, 4, 'N', 2) == -1); 
	assert(determineSafeDistance(3, 1, 'e', 2) == 0); 
	assert(determineSafeDistance(3, 1, 'n', 5) == 2); 
	assert(determineSafeDistance(1, 3, 's', 2) == 2); 
	assert(determineSafeDistance(2, 4, 'w', 3) == 1); 
	assert(determineSafeDistance(2, 3, 'e', 2) == 1); 
	assert(determineSafeDistance(3, 1, 'U', -1) == -1);
	assert(determineSafeDistance(3, 1, 'N', -1) == -1); 


	int len;
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'S', "LL2R2r2L1R", len) == 0 && len == 7);
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'N', "1Lx", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(2, 4, 1, 1, 'w', "3R1L", len) == 3 && len == 1); 
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'n', "2r2l", len) == 1 && len == 4);
	len = -999;
	assert(obeyPlan(2, 2, 3, 4, 'n', "2r2l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(1, 5, 3, 4, 'n', "2r2l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(6, 2, 3, 4, 'n', "2r2l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(2, 3, 1, 4, 'p', "2r2l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'n', "2R2r1r2l", len) == 3 && len == 5);
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'n', "2R2r3l", len) == 3 && len == 6);
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'e', "2R2r3l", len) == 3 && len == 0);
	len = -999;
	assert(obeyPlan(3, 1, 3, 4, 'e', "", len) == 1 && len == 0);


	setSize(12, 20);
	len = -999;
	assert(obeyPlan(5, 6, 12, 20, 'e', "10L4r4r11r", len) == 0 && len == 29);
	len = -999;
	assert(obeyPlan(5, 2, 12, 20, 'e', "19r", len) == 3 && len == 18);

	setSize(25, 30);
	setWall(10, 10);
	setWall(15, 14);
	setWall(20, 20);
	setWall(20, 23);
	setWall(19, 27);
	setWall(23, 30);
	setWall(25, 29);
	len = -999;
	assert(obeyPlan(7, 7, 22, 30, 'e', "23R15l", len) == 0 && len == 38);
	len = -999;
	assert(obeyPlan(7, 7, 22, 30, 'e', "23R14l", len) == 1 && len == 37);
	len = -999;
	assert(obeyPlan(20, 20, 22, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 23, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(0, 12, 22, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 0, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 0, 22, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 23, 0, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(26, 12, 22, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 31, 22, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 26, 30, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 23, 31, 'e', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 21, 30, 'A', "23R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 21, 30, 'e', "23R15", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 21, 30, 'e', "233R15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(20, 12, 21, 30, 'e', "23pR15l", len) == 2 && len == -999);
	len = -999;
	assert(obeyPlan(7, 7, 22, 30, 'e', "20R15L3r", len) == 3 && len == 31);
	len = -999;
	assert(obeyPlan(7, 7, 22, 30, 'e', "20R11L5r", len) == 3 && len == 34);
	len = -999;
	assert(obeyPlan(7, 7, 22, 30, 'S', "20R15L3r", len) == 3 && len == 18);
	len = -999;
	assert(obeyPlan(7, 7, 22, 30, 'e', "20R11L3r4R", len) == 0 && len == 38);





	cerr << "All tests passed" << endl;
}
