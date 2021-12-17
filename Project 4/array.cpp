#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// return n after appending each string onto the same string
int reduplicate(string a[], int n) {
	if (n < 0) {
		return -1;						// return -1 if given bad argument
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[i] + a[i];				// copy the string onto the back of the string "mo" -> "momo"
	}
	return n;							// return n as given in the parameters
}

// return position of string that matches target
int locate(const string a[], int n, string target) {
	if (n < 0) {
		return -1;						// return -1 if given bad argument
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == target) {
			return i;					// if string at position i matches target, return i
			break;						
		}
	}
	return -1;							// return -1 if no string matches target
}

// return position of "greatest" string 
int locationOfMax(const string a[], int n) {
	if (n <= 0) {
		return -1;						// return -1 if given bad argument
	}
	int max = 0;						
	for (int i = 1; i < n; i++) {
		if (a[i] > a[max]) {
			max = i;					// if string at position i is greater than or equal to current greatest string, string at i becomes max
		}
	}
	return max;							// return position of string with greatest value
}

// return original position of string that gets moved to last position of array after copying all elements after it one place to the left
int circleLeft(string a[], int n, int pos) {
	if (n <= 0 || pos < 0 || pos > n - 1) {
		return -1;						// return -1 if given bad argument
	}
	for (int i = 0; i < n; i++) {
		if (i == pos) {					
			string temp = a[n - 1];		// if position at i equals pos, set temp equal to the string at last position of array
			a[n-1] = a[i];				// string at position i becomes the last position of array
			for (int j = i; j < n-2 ; j++) {
				a[j] = a[j + 1];		// the following elements are moved one position to the left

			}
			if (n == 1) {				
				return 0;					// return 0 when there is only one element in focus
			}
			else if (n == pos + 1) {
				return pos;
			}
			else {
				a[n - 2] = temp;			// string in temp goes to second to last position of array
				return i;					// return i;
				break;
			}
		}
	}
	return -1;							// return -1 if the loop passes with no i being equal to pos
}

// return number of sequences of one or more consecutive identical items
int enumerateRuns(const string a[], int n) {
	int count = 0;
	if (n < 0) {		
		return -1;						// return -1 if given bad argument
	}
	if (n == 0) {
		return 0;						// return 0 if array size in parameters is 0
	}
	for (int i = 0; i < n - 1 ; i++) {
		if (a[i] != a[i + 1]) {			
			count++;					// increment count if string at position i is not equal to the following string
		}
	}
	count = count + 1;					// add one more to count to get the number of sequences
	return count;						// return count
}

// return n after reversing the order of elements based on n
int flip(string a[], int n) {
	string temp;
	if (n < 0) {
		return -1;						// return -1 if given bad argument
	}
	for (int i = 0; i < n/2; i++) {
		temp = a[i];					// set temp equal to string at position i
		a[i] = a[n - 1 - i];			// set string at position i equal to string with same relative position from the opposite side
		a[n - 1 - i] = temp;			// set string at same relative position from opposite side equal to string in temp
	}
	return n;							// return given n
}

// return position of first corresponding elements of a1 and a2 that are not equal
int locateDifference(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0) {
		return -1;						// return -1 if given bad argument
	}
	if (n2 == 0) {
		return 0;						//return 0 if n2 equals 0
	}
	for (int i = 0; i < n1 && i < n2; i++) {		// iterating across a1
		if (a1[i] != a2[i]) {			
			return i;					// if string a1 at position i does not equal corresponding string in a2, return i
		}
	}
	if (n1 < n2) {
		return n1;						// if all strings in a1 are correspondingly present in a2, return n1
	}
	else {
		return n2;						// if all strings in a2 are correspondingly present in a1, return n2
	}
							
}

// return position in a1 where subsequence of all n2 elements of a2 appear in a1
int subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0 || n1 < n2) {
		return -1;						// return -1 if given bad argument
	}
	if (n2 == 0 || (n1 == 0 && n2 == 0)) {
		return 0;						// return 0 if n2 array has 0 elements or if both arrays have 0 elements
	}
	int count = 0;
	for (int i = 0; i < n1; i++) {		// iterates through a1
		if (a2[0] == a1[i]) {			// if first string at a2 equals a1 string at position i
			for (int j = 0; j < n2 && (i + j < n1); j++) {		// iterate through a2 
				if (a2[j] == a1[i + j]) {
					count++;			// increment count if a2 string at position j equals a1 string at position (i+j)
				}
			}
			if (count == n2) {
				return i;				// return i if the count equals n2
				break;
			}
		}
	}
	return -1;							// return -1 if there are not matching contigous subsequences between n1 and n2
}

// return smallest position in a1 of an element that is equal to any of the n2 elements in a2
int locateAny(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0) {
		return -1;						// return -1 if given bad argument
	}
	for (int i = 0; i < n1; i++) {		//iterate through a1
		for (int j = 0; j < n2; j++) {	// iterate through a2
			if (a1[i] == a2[j]) {		
				return i;				// if a1 string at position i is equal to a2 string at position j, return i
			}
		}
	
	}
	return -1;							// return -1 if there are no matches found between a1 and a2
}

// return position of first element that is not less than separator
int separate(string a[], int n, string separator) {
	if (n < 0) {
		return -1;						// return -1 if given bad argument
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) { // sorts strings in a in alphabetical order
			if (a[i] > a[j]) {
				string temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {		
		if (separator <= a[i]) {
			return i;					// if separator is valued less than or equal to a string at position i, return i
		}
	}
	return n;							// return n when there are no elements that are less than or equal to separator

}


int main()
{
	string h[7] = { "moana", "mulan", "ariel", "tiana", "", "belle", "elsa" };
	assert(locate(h, 7, "belle") == 5);
	assert(locate(h, 7, "ariel") == 2);
	assert(locate(h, 2, "ariel") == -1);
	assert(locationOfMax(h, 7) == 3);

	string g[4] = { "moana", "mulan", "belle", "raya" };
	assert(locateDifference(h, 4, g, 4) == 2);
	assert(circleLeft(g, 4, 1) == 1 && g[1] == "belle" && g[3] == "mulan");

	string c[4] = { "ma", "can", "tu", "do" };
	assert(reduplicate(c, 4) == 4 && c[0] == "mama" && c[3] == "dodo");

	string e[4] = { "ariel", "tiana", "", "belle" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "mulan", "mulan", "mulan", "belle", "belle" };
	assert(enumerateRuns(d, 5) == 2);

	string f[3] = { "tiana", "ariel", "raya" };
	assert(locateAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "raya" && f[2] == "tiana");

	assert(separate(h, 7, "elsa") == 3);

	cout << "All tests succeeded" << endl;
}