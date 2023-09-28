using namespace std;
class bank_account{
	private:
		string account_type;
		string name;
		string father_name;
		string mobile_number;
		float balance;
		int pin;
	public:
		bank_account(string acc_type);
		void personal_info();
		void get_balance();
		string getAccType();
		bool loginInfo_check(string num_in,int pin_in);
		virtual void deposit(){
		}
		void withdraw();
		void update_balance(float amount);
		float getBalance();
};

class saving_acc : public bank_account{
	public:
		saving_acc(string acc_type);
		void deposit() override;
};

class current_acc : public bank_account{
	public:
		current_acc(string acc_type);
		void deposit() override;
};

