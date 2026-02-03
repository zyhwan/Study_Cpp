#include<iostream>

using namespace std;

struct Animal {
	string name;
	int age;
	int health;
	int food;
	int clean;
};

void create_Animal(Animal* ani) {

	cout << "동물의 이름은? "; 
	cin >> ani->name;

	cout << endl << "동물의 나이는?";
	cin >> ani->age;

	ani->health = 100;
	ani->food = 100;
	ani->clean = 100;
}

void play(Animal* ani) {
	ani->health += 20;
	ani->food -= 20;
	ani->clean -= 10;
}

void one_day_pass(Animal* ani) {
	ani->health -= 10;
	ani->food -= 10;
	ani->clean -= 10;
}

void show(Animal* ani) {
	cout << "이름: " << ani->name << endl;
	cout << "나이: " << ani->age << endl;
	cout << "건강: " << ani->health << endl;
	cout << "배고픔: " << ani->food << endl;
	cout << "청결도: " << ani->clean << endl;
}


int main() {
	struct Animal* list[30];
	int animal_num{};

	while (1) {
		int num{};
		int play_with{};

		cout << "1. 동물 추가하기" << endl;
		cout << "2. 놀기" << endl;
		cout << "3. 상태 보기" << endl;

		cin >> num;

		switch (num) {
		case 1:
			list[animal_num] = new Animal;
			create_Animal(list[animal_num]);
			animal_num++;
			break;
		case 2:
			cout << "어떤 동물?";
			cin >> play_with;
			if(play_with < animal_num) play(list[play_with]);
			break;
		case 3:
			cout << "누구껄 보게?";
			cin >> play_with;
			if (play_with < animal_num) show(list[play_with]);
			break;
		}

		for (int i = 0; i < animal_num; ++i) {
			one_day_pass(list[i]);
		}
	}

	for (int i = 0; i < animal_num; ++i) {
		delete list[i];
	}

	return 0;
}

//돌아온 마이펫