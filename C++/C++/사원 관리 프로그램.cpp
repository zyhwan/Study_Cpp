#include <iostream>
#include <string>

using namespace std;

class Employee {
	string name;
	int age;

	string position;
	int rank;
public:
	Employee(string name, int age, string position, int rank) : name(name), age(age), position(position), rank(rank) {}

	Employee(const Employee& employee)
	{
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}
	Employee() {}

	void print_info() {
		cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "만원" << endl;
 	}

	int calculate_pay() { return 200 + rank * 50; }

};


class EmployeeList {
	int alloc_employee;
	int current_employee;
	Employee** employee_list;
public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		// 사실 current_employee 보다 alloc_employee 가 더
		// 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
		// 최대한 단순하게 생각해서 alloc_employee 는
		// 언제나 current_employee 보다 크다고 생각한다.
		// (즉 할당된 크기는 현재 총 직원수 보다 많음)
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() { return current_employee; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; ++i) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		cout << "총 비용 : " << total_pay << "만원 " << endl;
	}

	~EmployeeList() {
		for (int i = 0; i < current_employee; ++i) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}

};


int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_employee(new Employee("유재석", 41, "부장", 7));
	emp_list.add_employee(new Employee("정준하", 43, "과장", 4));
	emp_list.add_employee(new Employee("박명수", 43, "차장", 5));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
}