#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct menuItemType {
	string menuItem;
	double menuPrice;
};


// PROTOTYPES
void getData(struct menuItemType * array, int n);
menuItemType * showMenu(struct menuItemType array[], int n, int& count); // Postcondition: The items on display have been printed to cout (one per line).
double printCheck(struct menuItemType result[], int count); //user input
char get_user_command();
void orderNo();
int main()
{
	const int NUM_ITEMS = 8;
	struct menuItemType menu[8];
	int count = 0;
	int x = 0;
	

	cout << "Resturant Billing System !" << endl;
	cout << "Date:03/26/2019 " << endl;
	cout << "Danny's Resturant & Pizzeria" << endl;
	cout << "****************************" << endl;

	while (x != 6) {
		getData(menu, 8);
		struct menuItemType * result = showMenu(menu, 8, count);
		printCheck(result, count);
		cout << "To end Program Enter '6' ";
		cin >> x;
	}
	
}

char get_user_command() {
	char command;
	cout << "Enter menu item: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

double printCheck(struct menuItemType result[], int count) {

	cout << endl;
	orderNo();
	cout << "This is your bill: " << endl;
	double checkAmount = 0;

	for (int i = 0; i<count; i++) {
		cout << (i + 1) << ")" << result[i].menuItem << ": " << result[i].menuPrice << endl;
		checkAmount = checkAmount + result[i].menuPrice;
	}

	cout << "Tax (5%): " << checkAmount * .05 << endl;
	checkAmount = checkAmount * (1.05);
	cout << "Total is: " << checkAmount << endl;

	return checkAmount;
}

menuItemType * showMenu(struct menuItemType array[], int n, int& count) {
	const int MAX_ITEMS = 100;
	struct menuItemType bill[MAX_ITEMS];


	cout << "PLEASE TAKE A LOOK AT THE FOLLOWING MENU AND ENTER THE MENU ITEM YOU WOULD LIKE TO ORDER!" << endl << endl;
	for (int i = 0; i<n; i++) {
		cout <<setw(2)<< (i + 1) << ")" << array[i].menuItem << ": " << array[i].menuPrice << endl;
	}

	cout <<setw(2)<<"Q)Stop Ordering" << endl;
	count = 0;


	char choice;
	do {
		//print_menu( );
		choice = toupper(get_user_command());
		switch (choice)
		{
		case '1': {
			bill[count].menuItem = "Plain Egg";
			bill[count].menuPrice = 1.45;
			count++;
		}break;
		case '2': {
			bill[count].menuItem = "Bacon and Egg";
			bill[count].menuPrice = 2.45;
			count++;
		}break;
		case '3': {
			bill[count].menuItem = "Muffin";
			bill[count].menuPrice = 0.99;
			count++;
		}break;
		case '4': {
			bill[count].menuItem = "French Toast";
			bill[count].menuPrice = 1.99;
			count++;
		}break;
		case '5': {
			bill[count].menuItem = "Fruit Basket";
			bill[count].menuPrice = 2.49;
			count++;
		}break;
		case '6': {
			bill[count].menuItem = "Cereal";
			bill[count].menuPrice = 0.69;
			count++;
		}break;
		case '7': {
			bill[count].menuItem = "Coffee";
			bill[count].menuPrice = 0.50;
			count++;
		}break;
		case '8': {
			bill[count].menuItem = "Tea";
			bill[count].menuPrice = 0.75;
			count++;
		}break;
		case 'Q': cout << "Exiting out!" << endl;
			break;
		default: cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q') && (count < 100));

	return bill;
}

void getData(struct menuItemType * array, int n) {
	int count = 0;
	while (count < n) {
		switch (count) {
		case 0: {
			array[count].menuItem = "Plain Egg";
			array[count].menuPrice = 1.45;
		} break;
		case 1: {
			array[count].menuItem = "Bacon and Egg";
			array[count].menuPrice = 2.45;
		} break;
		case 2: {
			array[count].menuItem = "Muffin";
			array[count].menuPrice = 0.99;
		} break;
		case 3: {
			array[count].menuItem = "French Toast";
			array[count].menuPrice = 1.99;
		} break;
		case 4: {
			array[count].menuItem = "Fruit Basket";
			array[count].menuPrice = 2.49;
		} break;
		case 5: {
			array[count].menuItem = "Cereal";
			array[count].menuPrice = 0.69;
		} break;
		case 6: {
			array[count].menuItem = "Coffee";
			array[count].menuPrice = 0.50;
		} break;
		case 7: {
			array[count].menuItem = "Tea";
			array[count].menuPrice = 0.75;
		} break;
		}
		count++;
	}
}
void orderNo() {
	double random = rand ();
	cout <<"Order No: "<< random << endl;
}

