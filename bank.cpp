#include <iostream>
#include "bank.h"
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
using namespace std;

bank::bank(){
	for(int i=0; i<10 ; i++){
		accounts[i]=NULL;
	}
	landingPage();
}

void bank::landingPage(){
	char choice;
	while(true){
		cout<<"----  WELCOME ----"<<endl;
		cout<<"PRESS  C  to create new account"<<endl;
		cout<<"PRESS  S  to signIn"<<endl;
		cout<<"\nYour choice  :  ";
		cin>>choice;
		if(choice == 'C' || choice == 'c'){
			system("CLS");
			createAcc();
			mainMenu();
		}
		else if(choice == 'S' || choice == 's'){	
			system("CLS");
			if(signIn()){
				system("CLS");
				mainMenu();
			}
			else{
				cout<<"\nInvalid Login Info";
				Sleep(3000);
				system("CLS");
			}
		}
		else{
			cout<<"Invalid choice";
			Sleep(3000);
		}
		system("CLS");
	}
}

void bank::createAcc(){
	char choice;
	int *index;
	for(int i=0;i<10;i++){
		if(accounts[i] == NULL){
			index = new int;
			*index = i;
			break;
		}
	}
	TOP:
	cout<<"What type of Account you want to open \n";
	cout<<"For SAVING ACCOUNT press S"<<endl;
	cout<<"For CURRENT ACCOUNT press C"<<endl;
	cout<<"YOUR CHOICE  :  ";
	cin>>choice;
	
	if(choice == 'S' || choice == 's'){
		accounts[*index] = new saving_acc("SAVING");
	}
	
	else if(choice == 'C' || choice == 'c'){
		accounts[*index] = new current_acc("CURRENT");
	}
	else{
		cout<<"\nINVALID CHOICE"<<endl;
		cout<<"Please select correct option"<<endl;
		Sleep(3000);
		system("CLS");
		goto TOP;
	}
	current_account = accounts[*index];
	
	delete index;
}


void bank::mainMenu(){
	char choice;
	bool loop = true;
	while(loop){
	cout<<"--- WELCOME TO YOUR "<<current_account->getAccType()<<" ACCOUNT ---"<<endl;
	cout<<"Press 'D' to deposit"<<endl;
	cout<<"Press 'W' to Withdraw"<<endl;
	cout<<"Press 'I' to check personal info"<<endl;
	cout<<"Press 'B' to check balance"<<endl;
	cout<<"Press 'L' to Logout of account"<<endl;
	cout<<"\nYour choice  :  ";
	cin>>choice;
	
	 switch (choice) {
        case 'D':
    	case 'd':
    		system("CLS");
            current_account->deposit();
            break;
        case 'W':
        case 'w':
        	system("CLS");
            current_account->withdraw();
            break;
        case 'I':
        case 'i':
        	system("CLS");
            current_account->personal_info();
            break;
        case 'B':
        case 'b':
        	system("CLS");
            current_account->get_balance();
            break;
        case 'L':
        case 'l':
        	current_account = NULL;
        	loop=false;
        	break;
        default:
            cout << "Invalid choice. plase select between -> 'D , W , I , B'\n"<<endl;
    }
	}
}

bool bank::signIn(){
	string num;
	int pin;
	cout<<"---- WELCOME TO SIGNIN PAGE ----"<<endl;
	cout<<"\nENTER YOUR NUMBER  : ";
	cin>>num;
	cout<<"ENTER YOUR PIN  : ";
	cin>>pin;
	for(int i=0;i<10;i++){
		if(accounts[i] != NULL){
			if(accounts[i]->loginInfo_check(num,pin)){
				current_account = accounts[i];
				return true;
			}
		}
	}
	return false;
}

