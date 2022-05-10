#include "Contact.h"

void Contact::init(){
	int choice;
	Contact contact;
	while(1){
		system("cls");
		cout << "1. Add new contact" << endl;
		cout << "2. View all contacts" << endl;
		cout << "3. Search contact" << endl;
		cout << "4. Update Contact" << endl;
		cout << "5. Delete Contact" << endl;
		cout << endl << "Enter your choice: ";
		fflush(stdin);
		cin >> choice;
		switch(choice){
			case 1:
				contact.addNewContact();
				break;
			case 2:
				contact.viewAllContacts();
				break;
			case 3:
//				contact.searchContact();
				break;
			case 4:
//				contact.updateContact();
				break;
			case 5:
//				contact.deleteContact();
				break;
		}
	}
}

void Contact::setName(char n[30]){
	strcpy(name, n);
}

void Contact::setContactNumber(char c[11]){
	strcpy(contactNumber, c);
}

void Contact::setEmail(char e[30]){
	strcpy(email, e);
}

char * Contact::getName(){
	return name;
}

char * Contact::getContactNumber(){
	return contactNumber;
}

char * Contact::getEmail(){
	return email;
}

void Contact::display(){
	system("cls");
	cout << "Name: " << name << endl;
	cout << "Contact Number: " << contactNumber << endl;
	cout << "Email: " << email << endl;
	cout << endl << "Press any key to continue...";
	getch();
}

void Contact::addNewContact(){
	system("cls");
	cout << "Name: ";
	fflush(stdin);
	gets(name);
	cout << "Contact Number: ";
	fflush(stdin);
	gets(contactNumber);
	cout << "Email: ";
	fflush(stdin);
	gets(email);
	
	ofstream fout;
	fout.open("contact.dat", ios::app|ios::binary);
	fout.write((char*)this, sizeof(*this));
	fout.close();
	cout << "Data added successfully" << endl;
	Sleep(1000);
}

void Contact::viewAllContacts(){
	system("cls");
	ifstream fin;
	Contact temp;
	fin.open("contact.dat", ios::in|ios::binary);
	if(!fin){
		perror("Error");
		Sleep(2000);
	}else{
		fin.read((char*)&temp, sizeof(temp));
		while(fin.eof() == 0){
			cout << setw(30) << temp.name << " " << setw(11) << temp.contactNumber << " " << setw(30) << temp.email << endl;
			fin.read((char*)&temp, sizeof(temp));
		}
	}
	fin.close();
	cout << "\nPress any key to continue...";
	getch();
}