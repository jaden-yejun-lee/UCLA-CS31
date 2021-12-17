#include <iostream>
#include <string>
using namespace std;


int main()
{
	//declaring variables
	int startOdo;
	int endOdo;
	int rentalDays;
	string customerName;
	string yesNo;
	int month;


	//establishing the value of start odometer
	cout << "Odometer at start: ";
	cin >> startOdo;
	if (startOdo < 0) {
		cout << "---" << endl;
		cout << "The starting odometer reading must not be negative.";
		return 1;
	}

	//establishing the value of end odometer
	cout << "Odometer at end: ";
	cin >> endOdo;
	if (endOdo < startOdo) {
		cout << "---" << endl;
		cout << "The ending odometer reading must be at least as large as the starting reading.";
		return 2;
	}

	//establishing the value of days the vehicle was rented
	cout << "Rental days: ";
	cin >> rentalDays;
	cin.ignore(10000, '\n');
	if (rentalDays <= 0) {
		cout << "---" << endl;
		cout << "The number of rental days must be positive.";
		return 3;
	}

	//establishing the name of the customer
	cout << "Customer name: "; //check this code (especially the blank spacing part)
	getline(cin, customerName);
	if (customerName == "") {
		cout << "---" << endl;
		cout << "You must enter a customer name.";
		return 4;
	}

	//establishing whether or not the vehicle was a luxury car
	cout << "Luxury car? (y/n): ";
	getline(cin, yesNo);
	if (yesNo != "y" && yesNo != "n") {
		cout << "---" << endl;
		cout << "You must enter y or n.";
		return 5;
	}

	//estabilishing the month during which the vehicle was rented
	cout << "Month (1=Jan, 2=Feb, etc.): ";
	cin >> month;
	if (month < 1 || month > 12) {
		cout << "---" << endl;
		cout << "The month number must be in the range 1 through 12.";
		return 6;
	}

	//establishing rental charge as a variable with decimal places
	double rentalCharge = 0;

	//setting two places after the decimal
	cout.setf(ios::fixed);
	cout.precision(2);

	//calculating miles driven
	int milesDriven;
	milesDriven = endOdo - startOdo;

	//logic for the calculation of the rental costs
	if (yesNo == "y") {
		rentalCharge = 71 * rentalDays;
	}
	else
		rentalCharge = 43 * rentalDays;

	if (milesDriven > 100) {
		rentalCharge += 100 * 0.27;
	}
	else {
		rentalCharge += milesDriven * 0.27;
		cout << "---" << endl;
		cout << "The rental charge for " << customerName << " is $" << rentalCharge;
		return 7;
	}

	if (milesDriven < 500 && (month == 12 || month <= 3)) {
		rentalCharge += 0.27 * (milesDriven - 100);
	}
	else if (milesDriven < 500 && (month >= 4 && month <= 11)) {
		rentalCharge += 0.21 * (milesDriven - 100);
	}
	else if (milesDriven > 500 && (month == 12 || month <= 3)) {
		rentalCharge += 0.27 * 400;
		rentalCharge += 0.17 * (milesDriven - 500);
	}
	else if (milesDriven > 500 && (month >= 4 && month <= 11)) {
		rentalCharge += 0.21 * 400;
		rentalCharge += 0.17 * (milesDriven - 500);
		//prints out the rental charge
	} cout << "---" << endl;
	cout << "The rental charge for " << customerName << " is $" << rentalCharge << endl;
}