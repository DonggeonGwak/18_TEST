//1. * *캐릭터 생성 및 관리 * *
//-원하는 이름으로 캐릭터를 하나 뿅!만들 수 있어야 합니다.
//- **레벨 1 * *, ** 초기 체력 200 * *, ** 공격력 30 * *, ** 경험치 0 * *으로 시작하고, 레벨업에 필요한 경험치는** 100 * *고정!
//- 언제든지 캐릭터 상태 확인 가능!
//2. * *레벨업 효과 * *
//-레벨이 오를 때마다 체력과 공격력이 폭발적으로(? ) 상승합니다.
//- **체력 * *: `(현재 체력 + (레벨 × 20))`,** 공격력** : `(현재 공격력 + (레벨 × 5))`
//- 레벨업 시 체력은 최대치까지 완전히 회복!
//- 최대 레벨은 * *10으로 제한.* *
//3. * *전투 시스템 * *
//-랜덤으로 출몰(? )하는 몬스터와 턴제로 싸웁니다.
//- 전투 시작 조건 :
//-캐릭터 생성 직후
//- 전투 승리 후 상점 방문을 스킵하거나, 상점 이용 후
//- 전투 승리 : 경험치 50 획득 & 10~20 골드 랜덤 획득
//- 경험치 누적 100 이상 → 자동 레벨업
//4. * *몬스터 설명 * *
//-몬스터도 이름, 체력, 공격력을 가집니다.
//- 몬스터 스펙은 캐릭터 레벨에 비례해서 랜덤하게 생성 :
//-체력 : (레벨 × 20) ~(레벨 × 30)
//- 공격력 : (레벨 × 5) ~(레벨 × 10)
//5. * *아이템 및 골드 관리 * *
//-전투에서 이기면 골드를 얻고, 가끔(30 % 확률) 아이템이 떨어집니다.
//- 아이템은 * *체력 + 50 * *또는 * *공격력 + 10 * *을 해주는 멋진 효과!
//- 전투 중에는 "이럴 때 아이템!" 하고 랜덤하게 사용됩니다. (디테일은 자유롭게!)
//- 아이템은 사용 순간 사라지고, 효과는 바로 캐릭터에게 반영됩니다.
//6. * *게임 로그 확인 * *
//-“전투 ? 아이템 사용 ? 골드 획득 ? ” 중요한 이벤트는 콘솔에 쭉 기록됩니다.
//- 로그를 통해 오늘 어떤 몬스터를 몇 마리 눕혔는지~한 눈에 확인 가능!



#include <iostream>
#include <string>

using namespace std;

template<typename Monster>
class Gamemanager
{

public:

	Monster* generateMonster(int level);
	void battle(int* character);
	void displayInventory(int* character);

};

class Character
{
public:
	string name;
	int level;
	int health;
	int attack;
	int experience;
	int gold;
	Character(string characterName)
	{
		name = characterName;
		level = 1;
		health = 200;
		attack = 30;
		experience = 0;
		gold = 0;
	}
	void displayStatus()
	{
		cout << "캐릭터: " << name << endl;
		cout << "레벨: " << level << ", HP: " << health << ", 공격력: " << attack << ", 경험치: " << experience << ", 골드: " << gold << endl;
	}
	void levelup()
	{
		if (experience >= 100 && level < 10)
		{
			level++;
			health += (level * 20);
			attack += (level * 5);
			experience = 0;
			cout << name << " 레벨업!! " << level << "HP와 공격력 증가!!" << endl;
		}
		else if (level >= 10)
		{
			cout << name << " 최대 레벨에 도달하였습니다!!" << endl;
		}
	}
	void usehealthBoost()
	{
		int healthBoost = 50;
		health += healthBoost;
		cout << name << " 아이템을 사용하였습니다. HP가" << healthBoost << "만큼 증가합니다." << endl;

	}
	void useAttackBoost()
	{
		int attackBoost = 10;
		attack += attackBoost;
		cout << name << " 아이템을 사용하였습니다. 공격력이 " << attackBoost << "만큼 증가합니다." << endl;
	}
};
class Monster
{
public:
	virtual const string& getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;

};
class Goblin : public Monster
{
public:
	string name;
	int health;
	int attack;
	Goblin(int level)
	{
		name = "고블린";
		health = rand() % (level * 10) + (level * 20); // Health between level*20 and level*30
		attack = rand() % (level * 5) + (level * 5); // Attack between level*5 and level*10
	}
	const string& getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
		cout << name << "가 " << damage << "의 피해를 입었습니다. 남은 체력: " << health << endl;
	}
};

class Orc : public Monster
{
public:
	string name;
	int health;
	int attack;
	Orc(int level)
	{
		name = "오크";
		health = rand() % (level * 10) + (level * 20); // Health between level*20 and level*30
		attack = rand() % (level * 5) + (level * 5); // Attack between level*5 and level*10
	}
	const string& getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
		cout << name << "가 " << damage << "의 피해를 입었습니다. 남은 체력: " << health << endl;
	}
};

class Troll : public Monster
{
public:
	string name;
	int health;
	int attack;

	Troll(int level)
	{
		name = "트롤";
		health = rand() % (level * 10) + (level * 20); // Health between level*20 and level*30
		attack = rand() % (level * 5) + (level * 5); // Attack between level*5 and level*10
	}
	const string& getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
		cout << name << "가 " << damage << "의 피해를 입었습니다. 남은 체력: " << health << endl;
	}
};

class Slime : public Monster
{
public:
	string name;
	int health;
	int attack;
	Slime(int level)
	{
		name = "슬라임";
		health = rand() % (level * 10) + (level * 20); // Health between level*20 and level*30
		attack = rand() % (level * 5) + (level * 5); // Attack between level*5 and level*10
	}
	const string& getName() const override
	{
		return name;
	}

	int getHealth() const override
	{
		return health;
	}

	int getAttack() const override
	{
		return attack;
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
		cout << name << "가 " << damage << "의 피해를 입었습니다. 남은 체력: " << health << endl;
	}
};

int main()
{
	string characterName;
	cout << "이름을 입력해주세요 주인님: ";
	cin >> characterName;
	Character player(characterName);
	player.displayStatus();


	while (true)
	{
		int choice;
		cout << "1. 플레이어 스텟!!" << endl;
		cout << "2. 싸움 시작!!" << endl;
		cout << "3. 아이템 사용!!" << endl;
		cout << "4. 게임 종료!!" << endl;

		cin >> choice;
		if (choice == 1)
		{
			player.displayStatus();
		}
		else if (choice == 2)
		{
		}
		else if (choice == 3)
		{
		}
		else if (choice == 4)
		{
			cout << "게임 종료..." << endl;
			break;
		}
		else
		{
			cout << "잘못된 입력값 입니다. 1,2,3,4 중에 입력해주세요." << endl;
		}
	}


	return 0;
}