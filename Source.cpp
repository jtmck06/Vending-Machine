#include<iostream>
#include<iomanip>
#include<string>

class Vending {
private:
	int money[5] = { 20,20,20,20,0 };
	int stock[5] = { 30,30,30,30,30 };
	double itemPrice[5] = { 1.50,1.25,1,1.25,1.50 };
	double sales[5] = {0,0,0,0,0};
public:
	double getPrice(int item, int quanity);
	void getSales(int item, double actSales);
	void displaySales();
	void getStock(int quanity,int item);
	bool vendingPower();
	double MoneySpent(double cost);
	double change(double owe);
	void vendingDeposit();
	void vendingCapcity();
	void Profit();
};
bool Vending::vendingPower() {
	int input;
	bool power = false;
	std::cout << "Vending machine is off" << std::endl;
	std::cout << "Press 1 to turn on the vending machine" << std::endl;
	std::cin >> input;
	if (input == 1)
		power = true;
	else
		power = false;
	return power;
}
//Determines the overall price by finding the price of the selected item from the "itemPrice" array
double Vending::getPrice(int item,int quanity) {
	double price;
	item = item - 1;
	itemPrice[item];

	price = itemPrice[item] * quanity;
	return price;
}
void Vending::getSales(int item,double actSales) {
	item = item - 1;
	sales[item]+=actSales;
}
//shows the sales made
void Vending::displaySales()
{
	std::cout << "The sales for Coke: " << sales[0] << std::endl;
	std::cout << "The sales for Doritos: " << sales[1] << std::endl;
	std::cout << "The sales for Snickers: " << sales[2] << std::endl;
	std::cout << "The sales for Chex Mix: " << sales[3] << std::endl;
	std::cout << "The sales for Pepsi: " << sales[4] << std::endl;
}
//subtracts the quanity of the selected item from the stock 
void Vending::getStock(int quanity,int item) {
	item = item - 1;
	stock[item] -= quanity;
}
//Collects the change owed to the user once the sale is made
double Vending::change(double owe) {
	double moneyNeeded = 0.0;
	double moneyTaken =0;
	do {
		if (moneyTaken == 0.01) {
			money[0]--;
		}
		else if (moneyTaken == 0.05) {
			money[1]--;
		}
		else if (moneyTaken == 0.10){
			money[2]--;
		}
		else if (moneyTaken == 0.25) {
			money[3]--;
		}
		moneyTaken -= moneyNeeded;
	} while (owe < 0);
	return moneyNeeded;
}
//Function collects the money that the user puts into the vending machine and stops once the money put in
// is greater than or equal to the cost
double Vending::MoneySpent(double cost)
{
	double moneySpent = 0.0;
	double moneyInserted;
	do
	{
		std::cout << "Please enter coins or $1 dollar bills.\n";
		std::cout << "*THIS VENDING MACHINE DOES NOT BILLS GREATER THAN $1!!*\n";
		std::cin >> moneyInserted;
		

		if (moneyInserted == 0.01)
		{
			money[0]++;
		}

		else if (moneyInserted == 0.05)
		{
			money[1]++;
		}

		else if (moneyInserted == 0.10)
		{
			money[2]++;
		}

		else if (moneyInserted == 0.25)
		{
			money[3]++;
		}
		else if (moneyInserted == 1.00)
		{
			money[4]++;
		}
		else
		{
			std::cout << "This is coin is not accepted" << std::endl;
			break;
		}
		moneySpent += moneyInserted;

	} while (moneySpent < cost);

	return moneySpent;
}
//Function collects excess money 
void Vending::vendingDeposit()
{
	if (money[0] >= 100)
	{
		money[0] = 20;
		std::cout << "The excess pinnies have been collected" << std::endl;
	}
	if (money[1] >= 100)
	{
		money[1] = 20;
		std::cout << "The excess nickels have been collected" << std::endl;
	}
	if (money[2] >= 100)
	{
		money[2] = 20;
		std::cout << "The excess dimes have been collected" << std::endl;
	}
	if (money[3] >= 100)
	{
		money[3] = 20;
		std::cout << "The excess quarters bills have been collected" << std::endl;
	}
	if (money[4] >= 20)
	{
		money[4] = 0;
		std::cout << "The excess 1 dollar bills have been collected" << std::endl;
	}
	if (money) {

	}
}
//Function restocks the items once there are 4 or less in stock
void Vending::vendingCapcity()
{
	if (stock[0] <= 4)
	{
		stock[0] = 30;
		std::cout << "The Coke has been refilled to max capcity" << std::endl;
	}
	if (stock[1] <= 4)
	{
		stock[1] = 30;
		std::cout << "The Doritos has been refilled to max capcity" << std::endl;
	}
	if (stock[2] <= 4)
	{
		stock[2] = 30;
		std::cout << "The Snickers has been refilled to max capcity" <<std:: endl;
	}
	if (stock[3] <= 4)
	{
		stock[3] = 30;
		std::cout << "The Chex Mix has been refilled to max capcity" << std::endl;
	}
	if (stock[4] <= 4)
	{
		stock[4] = 30;
		std::cout << "The pepsi has been refilled to max capcity" << std::endl;
	}
}
//adds up sales from each item and subtracts that from the monthly expenses
void Vending::Profit() {
	int monthlyExpenses = 215;
	double profit;
	profit = (sales[0] + sales[1]+ sales[2]+ sales[3]+ sales[4])-monthlyExpenses;
	std::cout << "You have made "<< profit << " in profit this month"<< std::endl;
}
//menu whrere you select your desired item(s) andthe amount you want
int main() {
	Vending snackPro;
	bool power = snackPro.vendingPower();
	std::string buy;
	
	if (power == true) {
		std::cout << "Snack Pro Vending!!\n\n";
		do {
			double moneyInserted, owe;
			int quanity, item;
			double price, actSales;
			std::string vendingOpt;
			int coke = 1, doritos = 2, snickers = 3, chexmix = 4, pepsi = 5, cancel = 6;

			std::cout << "Vending Options\n"
				<< "1.Coke: $1.50\n"
				<< "2.Doritos: $1.25\n"
				<< "3.Snickers: $1.00\n"
				<< "4.Chex Mix: $1.25\n"
				<< "5.Pepsi: $1.50\n"
				<< "6.Cancel\n\t";
			std::cin >> item;
			std::cout << std::fixed << std::showpoint << std::setprecision(2);

			switch (item) {
			case 1:vendingOpt = "Coke";
				break;
			case 2:vendingOpt = "Doritos";
				break;
			case 3:vendingOpt = "Snickers";
				break;
			case 4:vendingOpt = "Chex Mix";
				break;
			case 5:vendingOpt = "Pepsi";
				break;
			default:std::cout << "Invaild option was chosen" << std::endl;
			}
			if (item >= 0 || item <= 5) {
				std::cout << "How many do you want?" << std::endl;
				std::cin >> quanity;
				price = snackPro.getPrice(item, quanity);
				std::cout << "Please insert $" << price << std::endl;
				moneyInserted = snackPro.MoneySpent(price);
				snackPro.getStock(item, quanity);
				owe = moneyInserted - price;
				if (owe > 0) {
					std::cout << "You will recive $" << owe << " in change" << std::endl;
					snackPro.change(owe);
					actSales = moneyInserted - owe;
					snackPro.getSales(item, actSales);
					std::cout << "Would you like another item?" << std::endl;
					std::cout << "\t yes or no" << std::endl;
					std::cin >> buy;
				}
				else if (owe == 0) {
					std::cout << "Thank You for shopping!!" << std::endl;
					actSales = moneyInserted - owe;
					snackPro.getSales(item, actSales);
					std::cout << "Would you like another item?" << std::endl;
					std::cout << "\t yes or no" << std::endl;
					std::cin >> buy;
				}

			}
		} while (buy == "yes");
		snackPro.vendingDeposit();
		snackPro.vendingCapcity();
		snackPro.displaySales();
		snackPro.Profit();
	}
	return 0;
}
	