/*
* C++ Design Patterns: Facade
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <ostream>
#include <string>
#include <memory>

/*
 * Account Number Check ==> Subsystems A
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class AccountNumberCheck {
public:
	int getAccountNumber() const { return accountNumber; }

	bool checkAccountActive(const int &accountNumberToCheck) const
	{
		return accountNumberToCheck == getAccountNumber();
	}

private:
	int accountNumber = 12345678; // to simplify this example
};

/*
 * Security Code Check ==> Subsystems B
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class SecurityCodeCheck {
public:
	int getSecurityCode() const { return securityCode; }

	bool isCodeCorrect(const int &securityCodeToCheck) const
	{
		return securityCodeToCheck == getSecurityCode();
	}

private:
	int securityCode = 1234; // to simplify this example
};

/*
 * Fund Check ==> Subsystems C
 * implement more complex subsystem functionality
 * and have no knowledge of the facade
 */
class FundsCheck {
public:
	double getCashInAccount() const { return cashInAccount; }
	
	void decreaseCashInAccount(const double& cashWithdrawn) { cashInAccount -= cashWithdrawn; }

	void increaseCashInAccount(const double& cashDeposited) { cashInAccount += cashDeposited; }

	bool haveEnoughMoney(const double& cashToWithdrawal)
	{
		if (cashToWithdrawal > getCashInAccount()) 
		{
			std::cout<<"Error: You don't have enough money"<<std::endl;
			std::cout << "Current Balance: " << getCashInAccount() << std::endl;
			return false;
		}
		else 
		{
			decreaseCashInAccount(cashToWithdrawal);
			std::cout << "Withdrawal Complete: Current Balance is " << getCashInAccount() << std::endl;
			return true;
		}
	}

	void makeDeposit(const double& cashToDeposit)
	{
		increaseCashInAccount(cashToDeposit);
		std::cout << "Deposit Complete: Current Balance is " << getCashInAccount() << std::endl;
	}

private:
	double cashInAccount = 1000.00; // to simplify this example
};

/*
 * BankAccount ==> Facade
 * delegates client requests to appropriate subsystem object
 * and unified interface that is easier to use
 */
class BankAccount {
public:
	BankAccount(int accountNumber, int securityCode) :
		accountNumberCheck(std::make_unique<AccountNumberCheck> ()), securityCodeCheck(std::make_unique<SecurityCodeCheck>()), fundsCheck(std::make_unique<FundsCheck>()) ,
		accountNumber(accountNumber), securityCode(securityCode)
	{
		std::cout << "Welcome to ABC Bank" << std::endl;
	}

	int getAccountNumber() const { return accountNumber; }

	int getSecurityCode() const { return securityCode; }

	void withdrawCash(const double& cashToGet)
	{
		if (accountNumberCheck->checkAccountActive(getAccountNumber()) &&
			securityCodeCheck->isCodeCorrect(getSecurityCode()) &&
			fundsCheck->haveEnoughMoney(cashToGet)) 
		{
			std::cout<<"Transaction Complete"<<std::endl;
		}
		else 
		{
			std::cout << "Transaction Failed" << std::endl;
		}
	}

	void depositCash(const double& cashToDeposit)
	{
		if (accountNumberCheck->checkAccountActive(getAccountNumber()) &&
			securityCodeCheck->isCodeCorrect(getSecurityCode())) 
		{
			fundsCheck->makeDeposit(cashToDeposit);
			std::cout << "Transaction Complete" << std::endl;
		}
		else 
		{
			std::cout << "Transaction Failed" << std::endl;
		}
	}

private:
	std::unique_ptr<AccountNumberCheck> accountNumberCheck;
	std::unique_ptr<SecurityCodeCheck> securityCodeCheck;
	std::unique_ptr<FundsCheck> fundsCheck;
	int accountNumber;
	int securityCode;
};


int main()
{
	std::unique_ptr<BankAccount> bankAccount = std::make_unique<BankAccount>(12345678, 1234);
	bankAccount->withdrawCash(60.00);
	bankAccount->depositCash(990.00);
	system("pause");
	return 0;
}
