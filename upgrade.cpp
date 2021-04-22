#include <iostream>
using namespace std;

// 강화를 위주로 구현 (미완)

class ItemHandler {

};

class Item {
private:
	string name;
	string desc;
	int type;
public:
	Item(string _name, string _desc,int _type) :
		name(_name),desc(_desc),type(_type) {}
};

class Weapon : public Item{
private:
	// 몇 성인지
	int star;
	// 최대 몇 성까지 강화할 수 있는지
	const int maxStar = 10;
	// 강화 확률
	const int chance[10] = { 100,95,90,85,80,75,70,65,60,55 };
	// 무기 데미지
	int damage;
public:
	Weapon(string _name, string _desc, int _type, int _damage) 
		: Item(_name,_desc,_type),damage(_damage) {}



	void Upgrade() {
		
	}
};

class Equipment : public Item {
private:
public:
};

int main(void) {
	return 0;
}
