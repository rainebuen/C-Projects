#include <iostream>
using namespace std;

int main()
{
    cout<<"\t=== BANKING SYSTEM ===\n";

    int accnum[3];
    float balance[3];
    string name[3];
    float deposit = 0;
    float withdraw = 0;
    int choice = 0;
    int account_number = 0;

    
    for(int y = 0; y < 3; y++) {
      cout << "\nEnter Account Number: ";
         cin >> accnum[y];
      cout << "Enter Name: ";
      cin.ignore();
         getline(cin, name[y]);
      cout << "Enter Balance: ";
         cin >> balance[y]; }
                
do {
    cout <<"\n\n\t Select one option below \n" << endl;
       cout << "   1: Display All" << endl;
       cout << "   2: By Account Number" << endl;
       cout << "   3: Deposit" << endl;
       cout << "   4: Withdrawal" << endl;
       cout << "   5: Quit" << endl;
     cout << "\n Enter your choice: ";
        cin >> choice;
        
    switch (choice) {
        case 1:
         cout << "\n\n\t---ACCOUNTS---" << endl;
         
          for (int i = 0; i < 3; i++) {
            cout << "\n-Account Details-" << endl; 
            cout << "\nAccount Number: " << accnum[i] << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Balance: " << balance[i] << endl;  }
          break;
      
        case 2:
           cout << "\nWhat Account Number?: ";
             cin >> account_number;
       
           for(int d = 0; d < 3; d++) {
             if(accnum[d] == account_number) {
                cout << "\n-Account Details-" << endl; 
                cout << "\nAccount Number: " << accnum[d] << endl;
                cout << "Name: " << name[d] << endl;
                cout << "Balance: " << balance[d] << endl;}
           }
         break;
     
       case 3:
          cout << "\nWhat Account Number?: ";
            cin >> account_number;
        
          for(int n = 0; n < 3; n++) { 
             if(accnum[n] == account_number) {
                 cout << "\n-Account Details-" << endl;
                 cout << "\nAccount Number: " << accnum[n] << endl;
                 cout << "Name: " << name[n] << endl;
                 cout << "Balance: " << balance[n] << endl;
   
               cout << "\nHow much money do you want to deposit?: ";
                 cin >> deposit; 
                   balance[n] = balance[n] + deposit; 
                 cout << "The deposit is successful!" << endl; 
                   cout << "\n-Account Details-" << endl;
                   cout << "\nAccount Number: " << accnum[n] << endl;
                   cout << "Name: " << name[n] << endl;
                   cout << "New Balance: " << balance[n] << endl; break;
             }
          } 
        break;
        
       case 4:      
          cout << "\nWhat Account Number?: ";
            cin >> account_number;
        
          for(int w = 0; w < 3; w++) { 
             if(accnum[w] == account_number) {
                 cout << "\n-Account Details-" << endl;
                 cout << "\nAccount Number: " << accnum[w] << endl;
                 cout << "Name: " << name[w] << endl;
                 cout << "Balance: " << balance[w] << endl;
   
               cout << "\nHow much money do you want to withdraw: ";
                 cin >> withdraw; 
                   balance[w] = balance[w] - withdraw; 
               cout << "The withdrawal is successful!" << endl; 
                 cout << "\n-Account Details-" << endl;
                 cout << "\nAccount Number: " << accnum[w] << endl;
                 cout << "Name: " << name[w] << endl;
                 cout << "Remaining Balance: " << balance[w] << endl; break;
             }
          } 
        break;
           
      case 5:
         cout << "\n\tThank you and Goodbye!";
        break;
        
        default:
         cout << "\nError! Invalid Choice.";
        break;
    }  

} while(choice != 5);

  return 0;

}
