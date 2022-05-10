#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include "menu.h"
using namespace std;

class Contact
{
	private:
		char name[30];
		char contactNumber[11];
		char email[30];
	public:
		void init();
		void setName(char [30]);
		void setContactNumber(char [11]);
		void setEmail(char [30]);
		char * getName();
		char * getContactNumber();
		char * getEmail();
		void display();
		void addNewContact();
};

#endif