#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <windows.h>

using namespace std;

const int MAX_ORDERS = 20;
const double VAT_RATE = 0.12;

struct Order {
   string name;
   int qty;
   double price;
};

struct Customer {
   string cname;
   double cash;
   Order orders[MAX_ORDERS];
   int numOrders;
   double totalprice;
   double change;
   string choice;
   double subtotal;
   double vatAmount;
   time_t now = time(nullptr);
   tm* timeinfo = localtime(&now);
   char date[50];
};

void display(Customer c) {
   cout << "\n\n\t\t   MANGKANOR'S FAST-FOOD" << endl;
   cout << "\n\t============================================" << endl;
   cout << "\t\t       SHOP RECEIPT" << endl;
    strftime(c.date, 50, "%m/%d/%Y %I:%M%p", c.timeinfo);
   cout << "\n\tCustomer: " << c.cname << "      " << c.date << endl;
   cout << "\t============================================" << endl;
   cout << "\tQTY      ITEM  \t\t\t    AMT" << endl;
   cout << "\t-------------------------------------------" << endl;
   for (int i = 0; i < c.numOrders; i++) {
      cout << "\t " << c.orders[i].qty << "      " << c.orders[i].name << "\t\t  P" << fixed << setprecision(2) << c.orders[i].price << endl;
   }
   cout << "\t-------------------------------------------" << endl;
   cout << "\tSubtotal:              \t\tP" << fixed << setprecision(2) << c.subtotal<< endl;
   cout << "\tVAT:                   \t\tP" << fixed << setprecision(2) << c.vatAmount << endl;
   cout << "\tTotal Price:           \t\tP" << fixed << setprecision(2) << c.totalprice << endl;
   cout << "\tCash Tendered:         \t\tP" << fixed << setprecision(2) << c.cash << endl;
   cout << "\tChange:                \t\tP" << fixed << setprecision(2) << c.change << endl;
   cout << "\t-------------------------------------------" << endl;
   cout << "\nThank you for coming!" << endl;
}

   void menu() {
      cout << "\n\t==============================================================" << endl;
      cout << "\t|                           MENU                             | " << endl;
      cout << "\t==============================================================" << endl;
      cout << "\t--------------------------------------------------------------" << endl;
      cout << "\t|            MEALS            |           DRINKS             |" << endl;
      cout << "\t--------------------------------------------------------------" << endl;
      cout << "\t| (1) RiceChick - P85.00      | (7) Coca-Cola - P22.00       |" << endl;
      cout << "\t| (2) Spaghetti - P60.00      | (8) Sprite - P22.00          |" << endl;
      cout << "\t| (3) French Fries - P30.00   | (9) Mountain Dew - P22.00    |" << endl;
      cout << "\t| (4) YumBurger - P40.00      | (10) Iced Tea - P25.00       |" << endl;
      cout << "\t| (5) KaNuggets - P110.00     | (11) Orange Juice- P30.00    |" << endl;
      cout << "\t| (6) Hotdoggy - P47.00       | (12) Bottled Water - P15.00  |" << endl;
      cout << "\t--------------------------------------------------------------" << endl;
      cout << "\t==============================================================" << endl;
     }

   void loadbar () {
        SetConsoleCP(437);
        SetConsoleOutputCP(437);

        int loadbar1 = 177, loadbar2 = 219;

        for (int i = 0; i < 25; i++) {
            cout << (char)loadbar1;
            }
        cout << "\r";
        cout << "\t\t\t\t\t";

        for (int i = 0; i < 25; i++) {
            cout << (char)loadbar2;
            Sleep(100);
            }
        system("cls");
        }

int main() {
  ofstream outputFile;
  outputFile.open("receipts.txt", ios::app);
   int order;
   Customer c;

   cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading...\n\n\t\t\t\t\t";
   loadbar();

   cout << "\n\nPlease enter your Name: ";
   getline(cin, c.cname);

   cout << "\nWelcome to MangKanor's Fast-food, " << c.cname << "!" << endl;

   c.numOrders = 0;

   do {
      menu();
      cout << "\nEnter your order(1-12): ";
      cin >> order;

     switch (order) {

        case 1:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "RiceChick";
            c.orders[c.numOrders].price = 85.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

        case 2:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Spaghetti";
            c.orders[c.numOrders].price = 60.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

        case 3:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "French Fries";
            c.orders[c.numOrders].price = 30.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

        case 4:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "YumBurger";
            c.orders[c.numOrders].price = 40.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

        case 5:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "KaNuggets";
            c.orders[c.numOrders].price = 110.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 6:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Hotdoggy";
            c.orders[c.numOrders].price = 47.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 7:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Coca-Cola";
            c.orders[c.numOrders].price = 22.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 8:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Sprite Lemon";
            c.orders[c.numOrders].price = 22.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 9:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Mountain Dew";
            c.orders[c.numOrders].price = 22.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 10:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Iced Tea";
            c.orders[c.numOrders].price = 25.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 11:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Orange Juice";
            c.orders[c.numOrders].price = 30.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       case 12:
            cout << "Enter the quantity: ";
            cin >> c.orders[c.numOrders].qty;
            c.orders[c.numOrders].name = "Bottled Water";
            c.orders[c.numOrders].price = 15.00;
            c.subtotal += c.orders[c.numOrders].price * c.orders[c.numOrders].qty;
            c.numOrders++;

            cout << c.orders[c.numOrders-1].qty << " " << c.orders[c.numOrders-1].name << " is added to your order(s).\n" << endl;

            do {
           cout << "Do you want to order again? (y/n): ";
            cin >> c.choice;
           } while (c.choice != "Y" && c.choice != "y" && c.choice != "N" && c.choice != "n");
            break;

       default:
            cout << "Invalid input. Please try again." << endl;
            break;
   }

} while (order > 12 || c.choice == "Y" || c.choice == "y");

    c.vatAmount = c.subtotal * VAT_RATE;
    c.totalprice += c.subtotal + c.vatAmount;

   cout << "\n\n\n\n\t\t\t\t\t   Order Processing...\n\n\t\t\t\t\t";
   loadbar();

      do {
        cout << "\nPlease enter your payment: P";
        cin >> c.cash;

        if(c.cash >= c.totalprice) {
          c.change = c.cash - c.totalprice;
         display(c);
        }
        else {
           cout << "Insufficient Amount! Please enter a right amount of cash." << endl;
        }

    } while(c.cash < c.totalprice);

   outputFile << "\t\t   MANGKANOR'S FAST-FOOD" << endl;
   outputFile << "\n\t============================================" << endl;
   outputFile << "\t\t       SHOP RECEIPT" << endl;
   strftime(c.date, 50, "%m/%d/%Y %I:%M%p", c.timeinfo);
   outputFile << "\n\tCustomer: " << c.cname << "      " << c.date << endl;
   outputFile << "\t============================================" << endl;
   outputFile << "\tQTY      ITEM  \t\t\t    AMT" << endl;
   outputFile << "\t-------------------------------------------" << endl;
   for (int i = 0; i < c.numOrders; i++) {
      outputFile << "\t " << c.orders[i].qty << "      " << c.orders[i].name << "\t\t  P" << fixed << setprecision(2) << c.orders[i].price << endl;
   }
   outputFile << "\t-------------------------------------------" << endl;
   outputFile << "\tSubtotal:              \t\tP" << fixed << setprecision(2) << c.subtotal<< endl;
   outputFile << "\tVAT:                   \t\tP" << fixed << setprecision(2) << c.vatAmount << endl;
   outputFile << "\tTotal Price:           \t\tP" << fixed << setprecision(2) << c.totalprice << endl;
   outputFile << "\tCash Tendered:         \t\tP" << fixed << setprecision(2) << c.cash << endl;
   outputFile << "\tChange:                \t\tP" << fixed << setprecision(2) << c.change << endl;
   outputFile << "\t-------------------------------------------\n\n\n" << endl;

return 0;
}
