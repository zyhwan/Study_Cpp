#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int pos_x, int pos_y);

	int GetX() const {
		return x;
	}
	int GetY() const{
		return y;
	}
};

class Geometry {
private:
	Point* point_array[100];
	int num_points;
public:
	Geometry() {
		cout << "디폴트 생성자 호출!" << endl;
		num_points = 0;
	}
	~Geometry() {
		for (int i = 0; i < num_points; ++i) {
			delete point_array[i];
		}
	}
	void AddPoint(const Point& point) {
		point_array[num_points++] = new Point(point.GetX(), point.GetY());
	}
	// 모든 점들 간의 거리를 출력하는 함수 입니다.
	void PrintDistance();

	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
	// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
	// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
	// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
	void PrintNumMeets();

};

Point::Point(int pos_x, int pos_y)
{
	x = pos_x;
	y = pos_y;
}

void Geometry::PrintDistance()
{
	for (int i = 0; i < num_points; ++i) {
		int x1 = point_array[i]->GetX();
		int y1 = point_array[i]->GetY();
		for (int j = i + 1; j < num_points; ++j) {
			int x2 = point_array[j]->GetX();
			int y2 = point_array[j]->GetY();

			int distance = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
			cout << "(" << x1 << ", " << y1 << ")" << "와 (" << x2 << ", " << y2 << ") 사이 거리: " << distance << endl;
		}
	}
}

void Geometry::PrintNumMeets()
{
	int cnt = 0;

	for (int i = 0; i < num_points; i++) {
		int x1 = point_array[i]->GetX();
		int y1 = point_array[i]->GetY();

		for (int j = i + 1; j < num_points; j++) {
			int x2 = point_array[j]->GetX();
			int y2 = point_array[j]->GetY();

			for (int k = 0; k < num_points; k++) {
				if (k == i || k == j) continue;

				int x3 = point_array[k]->GetX();
				int y3 = point_array[k]->GetY();

				for (int l = k + 1; l < num_points; l++) {
					if (l == i || l == j) continue;

					int x4 = point_array[l]->GetX();
					int y4 = point_array[l]->GetY();

					int increase_x1 = x2 - x1;
					int increase_x2 = x4 - x3;

					if (increase_x1 == 0 && increase_x2 != 0) {
						cnt++;
						continue;
					}
					else if (increase_x1 != 0 && increase_x2 == 0) {
						cnt++;
						continue;
					}
					else if (increase_x1 == 0 && increase_x2 == 0) //
					{
						continue;
					}

					double a1 = (y2 - y1) / increase_x1;
					double a2 = (y4 - y3) / increase_x2;

					std::cout << a1 << " " << a2 << std::endl;

					if (a1 == a2) {
						continue;
					}
					else {
						cnt++;
					}
				}
			}
		}
	}

	std::cout << "교점의 개수 : " << cnt << std::endl;
}

int main() {
	Geometry gm = Geometry();
	gm.AddPoint(Point(1, 1));
	gm.AddPoint(Point(1, 2));
	gm.AddPoint(Point(1, 3));
	gm.AddPoint(Point(1, 4));
	gm.AddPoint(Point(2, 2));

	gm.PrintDistance();
	gm.PrintNumMeets();

	return 0;
}