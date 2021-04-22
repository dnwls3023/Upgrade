#include <iostream>
#include <vector>
#include <random>
using namespace std;

// 강화를 위주로 구현

class ItemHandler {
private:
	vector<Item> Items;
};

class Item {
private:
	string name;
	string desc;
	int type;
public:
	Item(string _name, string _desc,int _type) :
		name(_name),desc(_desc),type(_type) {}

	void print() {
		string str[3] = { "","무기","장비" };
		
		cout << "아이템 이름 : " << name << endl;
		cout << "아이템 종류 : " << str[type] << endl;
		cout << "아이템 설명 : " << desc << endl;
	}
};

int money;

class Weapon : public Item{
private:
	// 몇 성인지
	int star;
	// 최대 몇 성까지 강화할 수 있는지
	const int maxStar = 10;
	// 강화 확률
	const int chance[10] = { 100,95,90,85,80,75,70,65,60,55 };
	// 강화 비용
	const int cost[10] = { 100,200,400,800,1500,3000,6000,10000,15000,30000 };
	// 데미지 증가량
	const int increaseDamage[10] = { 2,3,5,10,13,16,19,25,30,40 };

	// 기본 무기 데미지
	const int default_damage;
	// 무기 데미지
	int damage;
public:
	Weapon(string _name, string _desc, int _type, int _damage) 
		: Item(_name,_desc,_type),damage(_damage),default_damage(_damage) ,star(0) {}

	void print() {
		Item::print();
		for (int i = 0; i < 30; ++i) cout << '-';
		cout << star << "성 아이템" << endl;
		cout << "데미지 : " << default_damage << "(+" << damage - default_damage << ")" << endl;
	}

	void Upgrade() {
		if (star == maxStar) {
			cout << "이미 최대 강화 수치이므로 강화가 불가능 합니다." << endl;
		}

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(1, 100);

		if (money >= cost[star]) money -= cost[star];
		else {
			cout << "돈이 부족합니다." << endl;
			return;
		}

		if (chance[star] - dis(gen) >= 0) {
			cout << "강화 성공!!" << endl;
			damage += increaseDamage[star];
			star++;
		}
		else {
			cout << "강화 실패!" << endl;
		}
	}
};

class Equipment : public Item {
private:
public:
};

class Player {
private:
public:
};

int main(void) {
	return 0;
}
