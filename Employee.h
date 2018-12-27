#pragma once
#include <string>
#include "Date.h"
class Employee
{
private:
	std::string* frst_name;
	std::string* scd_name;
	std::string* position;
	const Date birth;
	const Date hire;
	int salary;
public:
	Employee();
	Employee(std::string, std::string, std::string, int d = 1, int m = 1, int = 1);
	Employee(const Employee &other);
	~Employee();

	void set_salary();
	void set(std::string, std::string, std::string);
	void print();
	void change_pos(const std::string);
	void change_salary(const int new_sal);
	int age();
	int experience();
	int years_from(Date date);
	void raise_salary();
	void lay_off();



};

