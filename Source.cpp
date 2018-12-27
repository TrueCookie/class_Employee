#include <iostream>
#include "Employee.h"
#include "conio.h"

int main() {

	Employee emp1("Daniel", "Hostage", "security", 24, 12, 1998);

	Employee* brigade1 = new Employee[5];
	brigade1[0].set("John", "Trooper", "security");
	brigade1[1].set("David", "Lich", "manager");
	brigade1[2].set("William", "Trash", "director dep");
	brigade1[3].set("John", "Vice", "director");
	brigade1[4].set("Milana", "Sykes", "cashier");

	for (int i = 0; i < 5; ++i) {
		brigade1[i].print();
	}

	emp1.raise_salary();
	emp1.print();

	_getch();
	return 0;
}