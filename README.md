# Banking Management System

This is a simple Banking Management System developed using C++. It allows users to perform various banking operations such as creating accounts, depositing money, withdrawing money, modifying account details, and viewing account balances. The system stores data in a binary file for persistence.

## Features

1. **Account Management**  
   - Create a new account  
   - Modify an existing account  
   - Delete an account

2. **Deposit and Withdraw**  
   - Deposit money into an account  
   - Withdraw money from an account  
   - Check account balance

3. **Account Display**  
   - View details of a specific account  
   - View the list of all account holders

## Files in the Project

- **account.dat**: This is the binary file where account details are stored.
- **account.cpp**: The main C++ source file containing the code for the banking system.
- **README.md**: This README file.

## Structure of the Code

1. **account class**  
   - Handles account information such as account number, name, account type, and balance.
   - Includes functions for creating an account, displaying account details, modifying accounts, depositing money, withdrawing money, and reporting account information.

2. **Main Functions**  
   - `write_account()`: Allows the user to create a new account and saves it to the file.
   - `display_sp(int n)`: Displays the details of a specific account.
   - `modify_account(int n)`: Allows the user to modify an existing account's details.
   - `delete_account(int n)`: Deletes an account from the file.
   - `deposit_withdraw(int n, int option)`: Handles deposits and withdrawals based on user input.
   - `display_all()`: Displays a list of all accounts.
   - `intro()`: Displays a welcome message for the banking system.

## How to Compile and Run

1. **Compile the Program**  
   - Use a C++ compiler like g++ to compile the code:
     ```bash
     g++ account.cpp -o banking_system
     ```

2. **Run the Program**  
   - After compiling, run the program:
     ```bash
     ./banking_system
     ```

3. **Use the Program**  
   - The program will display a menu with options to perform different banking operations (e.g., create account, deposit, withdraw, view balance).
   - Choose an option by entering the corresponding number.

## Example Usage

1. **Creating an Account**  
   - Choose option `1` to create a new account.
   - Enter the account number, name, account type (C/S), and initial deposit.

2. **Depositing Money**  
   - Choose option `2` to deposit money into an account.
   - Enter the account number and the amount to deposit.

3. **Withdrawing Money**  
   - Choose option `3` to withdraw money from an account.
   - Enter the account number and the amount to withdraw (make sure there is sufficient balance).

4. **Viewing Account Details**  
   - Choose option `4` to view the details of a specific account by entering the account number.

5. **Listing All Accounts**  
   - Choose option `5` to display a list of all account holders and their account details.

6. **Modifying an Account**  
   - Choose option `7` to modify an existing account by entering the account number and updating the details.

7. **Closing an Account**  
   - Choose option `6` to delete an account by entering the account number.

## Important Notes

- Account data is stored in the `account.dat` file in binary format.
- The minimum balance for a saving account is 500, and for a current account, it is 1000.
- The program uses a simple text-based menu interface for interaction.
