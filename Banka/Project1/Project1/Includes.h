#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include <windows.h>   
#include<memory>
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_shared;

struct Boja {
	void setCrvena() {
		HANDLE  hConsole;
		int boja;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		boja = 12;
		SetConsoleTextAttribute(hConsole, boja);
	}
	void setDefault() {
		HANDLE  hConsole;
		int boja;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		boja = 7;
		SetConsoleTextAttribute(hConsole, boja);
	}
	void setZelena() {
		HANDLE  hConsole;
		int boja;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		boja = 10;
		SetConsoleTextAttribute(hConsole, boja);
	}

};