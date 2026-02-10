#include <iostream>

using namespace std;

class Date {
	int year_{};
	int month_{};  // 1 부터 12 까지.
	int day_{};    // 1 부터 31 까지.
	int day_each_of_month[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	void ShowDate();
};


int main() {
	Date Mydate;
	
	int year{}, month{}, date{};

	cout << "날짜를 설정해주세요(년, 월, 일)";
	cin >> year >> month >> date;

	Mydate.SetDate(year, month, date);

	while (1) {
		cout << "1. 날짜 추가 2. 월 추가 3. 년 추가 4. 날짜 확인";
		int num{};
		int answer{};

		cin >> num;

		switch (num) {
		case 1:
			cout << "추가할 날짜 수를 입력하세요.";
			cin >> answer;
			Mydate.AddDay(answer);
			break;
		case 2:
			cout << "추가할 월 수를 입력하세요.";
			cin >> answer;
			Mydate.AddMonth(answer);
			break;
		case 3:
			cout << "추가할 년 수를 입력하세요.";
			cin >> answer;
			Mydate.AddYear(answer);
			break;
		case 4:
			Mydate.ShowDate();
			break;
		}
	}

	return 0;
}

void Date::SetDate(int year, int month, int date)
{
	year_ = year;
	month_ = month;
	day_ = date;
}

void Date::AddDay(int inc)
{
	day_ += inc;

	while (day_ > day_each_of_month[month_]) {
		if (month_ == 2) { //2월일 경우엔 -28일
			day_ -= day_each_of_month[month_];
			month_++;
		}
		else {
			day_ -= day_each_of_month[month_];
			month_++;
		}
	}
	if (day_ == 0) {
		day_ = 1;
	}

}

void Date::AddMonth(int inc)
{
	month_ += inc;
	while (month_ > 12) {
		month_ = month_ - 12;
		year_++;
	}
	if (month_ == 0) {
		month_ = 1;
	}

	if (day_ > day_each_of_month[month_]) {
		day_ = day_each_of_month[month_];
	}

}

void Date::AddYear(int inc)
{
	year_ += inc;
}

void Date::ShowDate()
{
	cout << year_ << "년 " << month_ << "월 " << day_ << "일 입니다." << endl;
}
