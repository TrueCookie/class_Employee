#define _CRT_SECURE_NO_WARNINGS

#include "Employee.h"
#include <ctime>
#include <iostream>
#include <iomanip>

Employee::Employee(){
	frst_name = new std::string("no name");
	scd_name = new std::string("no name");
	position = new std::string("no position");
}

Employee::Employee(std::string name1, std::string name2, std::string pos, int d, int m, int g):hire(d, m, g) {
	frst_name = new std::string(name1);
	scd_name = new std::string(name2);
	position = new std::string(pos);
	this->set_salary();
}

Employee::Employee(const Employee &other) {
	frst_name = new std::string(*other.frst_name);
	scd_name = new std::string(*other.scd_name);
	position = new std::string(*other.position);
	salary = other.salary;
}

Employee::~Employee(){
	delete frst_name;
	delete scd_name;
	delete position;
}

void Employee::set_salary() {
	if (*this->position == "director") {
		salary = 80000;
	}
	else if (*this->position == "director dep") {
		salary = 60000;
	}
	else if (*this->position == "manager") {
		salary = 60000;
	}
	else if (*this->position == "cashier") {
		salary = 30000;
	}
	else if (*this->position == "security") {
		salary = 25000;
	}
}

void Employee::set(std::string name1, std::string name2, std::string pos) {
	frst_name = new std::string(name1);
	scd_name = new std::string(name2);
	position = new std::string(pos);
	this->set_salary();
}

void Employee::print() {
	std::cout << std::setw(8) << *frst_name << std::setw(8) << *scd_name << std::setw(13);
	std::cout << "Position: " << std::setw(11) << *position << std::setw(10) << "Salary: " << salary << " Experience: " << experience() << std::endl;
}

void Employee::change_pos(const std::string new_pos) {
	*position = new_pos;
}

void Employee::change_salary(const int new_sal) {
	salary = new_sal;
}

int Employee::age() {
	return this->years_from(birth);
}

int Employee::experience() {
	return this->years_from(hire);
}

int Employee::years_from(Date date) {
	time_t t = time(NULL);
	tm *timeinfo = localtime(&t);
	Date today(timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year);
	return today.days_range(date) / 365;
}

void Employee::raise_salary() {
	if(this->experience() >= 15) {
		salary *= 1.03;
	} else if (this->experience() >= 20) {
		salary *= 1.05;
	} else if (this->experience() >= 25) {
		salary *= 1.1;
	}else if (this->experience() >= 30) {
		salary *= 1.15;
	}
}

void Employee::lay_off() {
	std::cout << "YOU'RE FIRED! YOU'RE FIRED! YOU'RE FIRED! YOU'RE FIRED! YOU'RE FIRED! YOU'RE FIRED!" << std::endl;
}















