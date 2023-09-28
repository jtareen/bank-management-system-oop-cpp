#include <iostream>
#include "bank_acc.h"
#include <stdlib.h>
#include <cstdio>
#include <windows.h>

using namespace std;


bank_account::bank_account(string acc_type){
	account_type = acc_type;
	cout<<"Enter your name : ";
	cin>>name;
	cout<<"Enter you Father's name : ";
	cin>>father_name;
	cout<<"Enter your phone number : ";
	cin>>mobile_number;
	cout<<"Enter your account PIN(in nums) : ";
	cin>>pin;
	
	balance = 0;
	
	system("CLS");
}

void bank_account::update_balance(float amount){
	balance += amount;
}

float bank_account::getBalance(){
	return balance;
}

void bank_account::personal_info(){
	char terminate;
	cout<<"---- ACCOUNT PERSONAL INFO ----"<<endl;
	cout<<"\nNAME           :  "<<name<<endl;
	cout<<"FATHER NAME    :  "<<father_name<<endl;
	cout<<"Contact Number :  "<<mobile_number<<endl;
	
	cout<<endl;
}

void bank_account::get_balance(){
	char terminate;
	cout<<"---- ACCOUNT BALANCE ----"<<endl;
	cout<<"\nAccount Credit  :  "<<balance<<endl;
	
	cout<<endl;
}

string bank_account::getAccType(){
	return account_type;
}


void bank_account::withdraw(){
	float amount;
	cout<<"Enter Withdraw amount : ";
	cin>>amount;
	
	if(amount<=balance){
		balance -= amount;
		cout<<"\nWithdrawal Succesfull!"<<endl;
		cout<<"New account Balance : "<<balance<<endl;
	}
	else{
		cout<<"\nInsufficient Balance!"<<endl;
		cout<<"Withdrawl Failed"<<endl;
	}
	Sleep(3000);
	system("CLS");
}

bool bank_account::loginInfo_check(string num_in, int pin_in){
	return (pin_in == pin && num_in == mobile_number);
}
//   saving account fnctions

saving_acc::saving_acc(string acc_type) : bank_account(acc_type){}

void saving_acc::deposit(){
	float amount;
	cout<<"---- DEPOSIT PAGE ----"<<endl;
	cout<<"Enter deposit amount : ";
	cin>>amount;
	
	amount += amount/100 * 20;
	update_balance(amount);
	
	cout<<"Deposit Succesfull!"<<endl;
	cout<<"New account Balance : "<<getBalance()<<endl;
	Sleep(3000);
	system("CLS");
}
//   current account fnctions

current_acc::current_acc(string acc_type) : bank_account(acc_type){}

void current_acc::deposit(){
	float amount;
	cout<<"---- DEPOSIT PAGE ----"<<endl;
	cout<<"Enter deposit amount : ";
	cin>>amount;
	
	update_balance(amount);
	
	cout<<"Deposit Succesfull!"<<endl;
	cout<<"New account Balance : "<<getBalance()<<endl;
	Sleep(3000);
	system("CLS");
}

