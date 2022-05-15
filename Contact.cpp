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
				contact.searchContact();
				break;
			case 4:
				contact.updateEmail();
				break;
			case 5:
//				contact.deleteContact();
				break;
			case 6:
				exit(0);
				break;
			default:
				system("cls");
				cout << "Wrong choice entered, please enter a valid choice" << endl;
				Sleep(1500);
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
		exit(1);
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

void Contact::searchContact(){
	system("cls");
	char nameToSearch[30];
	Contact temp;
	int count;
	ifstream fin;
	bool found = false;
	count = 0;
	cout << "Enter full name of contact to search: ";
	fflush(stdin);
	gets(nameToSearch);
	fin.open("contact.dat", ios::in|ios::binary);
	if(!fin){
		perror("Error");
		Sleep(2000);
		exit(1);
	}else{
		fin.read((char*)&temp, sizeof(temp));
		while(fin.eof() == 0){
			if(strcmp(nameToSearch, temp.name) == 0){
				temp.display();
				cout << endl;
				found = true;
				count++;
			}
			fin.read((char*)&temp, sizeof(temp));
		}
		fin.close();
	}
	if(found == true){
		cout << endl << "There are " << count << " contact(s) registered by this name" << endl;
	}else{
		cout << "Not found" << endl;
	}
	cout << "Press any key to continue...";
	getch();
}

bool Contact::exists(char c[12]){
	bool found = false;
	ifstream fin;
	fin.open("contact.dat", ios::in|ios::binary);
	Contact temp;
	fin.read((char*)&temp, sizeof(temp));
	while(fin.eof() == 0){
		if(strcmp(c, temp.contactNumber) == 0){
			found = true;
			break;
		}
		fin.read((char*)&temp, sizeof(temp));
	}
	fin.close();
	return found;
}

void Contact::updateEmail(){
	system("cls");
	char con[12], em[30];
	Contact temp;
	cout << "Enter your contact number: ";
	fflush(stdin);
	gets(con);
	fstream file;
	if(exists(con) == true){
		cout << "Enter new email: ";
		fflush(stdin);
		gets(em);
		file.open("contact.dat", ios::in | ios::out | ios::ate | ios::binary);
		file.seekg(0);
		if(!file){
			perror("Error");
			Sleep(2000);
			exit(1);
		}else{
			file.read((char*)&temp, sizeof(temp));
			while(file.eof() == 0){
				if(strcmp(con, temp.contactNumber) == 0){
					file.seekp(file.tellp() - sizeof(temp));
					strcpy(temp.email, em);
					file.write((char*)&temp, sizeof(temp));
					break;
				}
				file.read((char*)&temp, sizeof(temp));
			}
			file.close();
			cout << "Email updated successfully" << endl;
			Sleep(1000);
		}
	}else{
		cout << "This contact does not exists" << endl;
		Sleep(1500);
	}
}