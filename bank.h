#include "bank_acc.h"

class bank{
	private:
		bank_account *accounts[10];
		bank_account *current_account;
	public:
		bank();
		void mainMenu();
		void landingPage();
		void createAcc();
		bool signIn();
};

