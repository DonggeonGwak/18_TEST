//1. * *ĳ���� ���� �� ���� * *
//-���ϴ� �̸����� ĳ���͸� �ϳ� ��!���� �� �־�� �մϴ�.
//- **���� 1 * *, ** �ʱ� ü�� 200 * *, ** ���ݷ� 30 * *, ** ����ġ 0 * *���� �����ϰ�, �������� �ʿ��� ����ġ��** 100 * *����!
//- �������� ĳ���� ���� Ȯ�� ����!
//2. * *������ ȿ�� * *
//-������ ���� ������ ü�°� ���ݷ��� ����������(? ) ����մϴ�.
//- **ü�� * *: `(���� ü�� + (���� �� 20))`,** ���ݷ�** : `(���� ���ݷ� + (���� �� 5))`
//- ������ �� ü���� �ִ�ġ���� ������ ȸ��!
//- �ִ� ������ * *10���� ����.* *
//3. * *���� �ý��� * *
//-�������� ���(? )�ϴ� ���Ϳ� ������ �ο�ϴ�.
//- ���� ���� ���� :
//-ĳ���� ���� ����
//- ���� �¸� �� ���� �湮�� ��ŵ�ϰų�, ���� �̿� ��
//- ���� �¸� : ����ġ 50 ȹ�� & 10~20 ��� ���� ȹ��
//- ����ġ ���� 100 �̻� �� �ڵ� ������
//4. * *���� ���� * *
//-���͵� �̸�, ü��, ���ݷ��� �����ϴ�.
//- ���� ������ ĳ���� ������ ����ؼ� �����ϰ� ���� :
//-ü�� : (���� �� 20) ~(���� �� 30)
//- ���ݷ� : (���� �� 5) ~(���� �� 10)
//5. * *������ �� ��� ���� * *
//-�������� �̱�� ��带 ���, ����(30 % Ȯ��) �������� �������ϴ�.
//- �������� * *ü�� + 50 * *�Ǵ� * *���ݷ� + 10 * *�� ���ִ� ���� ȿ��!
//- ���� �߿��� "�̷� �� ������!" �ϰ� �����ϰ� ���˴ϴ�. (�������� �����Ӱ�!)
//- �������� ��� ���� �������, ȿ���� �ٷ� ĳ���Ϳ��� �ݿ��˴ϴ�.
//6. * *���� �α� Ȯ�� * *
//-������ ? ������ ��� ? ��� ȹ�� ? �� �߿��� �̺�Ʈ�� �ֿܼ� �� ��ϵ˴ϴ�.
//- �α׸� ���� ���� � ���͸� �� ���� ��������~�� ���� Ȯ�� ����!



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
		cout << "ĳ����: " << name << endl;
		cout << "����: " << level << ", HP: " << health << ", ���ݷ�: " << attack << ", ����ġ: " << experience << ", ���: " << gold << endl;
	}
	void levelup()
	{
		if (experience >= 100 && level < 10)
		{
			level++;
			health += (level * 20);
			attack += (level * 5);
			experience = 0; 
			cout << name << " ������!! " << level << "HP�� ���ݷ� ����!!" << endl;
		}
		else if (level >= 10)
		{
			cout << name << " �ִ� ������ �����Ͽ����ϴ�!!" << endl;
		}
	}
	void usehealthBoost()
	{
		int healthBoost = 50; 
		health += healthBoost;
		cout << name << " �������� ����Ͽ����ϴ�. HP��" << healthBoost << "��ŭ �����մϴ�." << endl;

	}
	void useAttackBoost()
	{
		int attackBoost = 10; 
		attack += attackBoost;
		cout << name << " �������� ����Ͽ����ϴ�. ���ݷ��� " << attackBoost << "��ŭ �����մϴ�." << endl;
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
		name = "���";
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
		cout << name << "�� " << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << health << endl;
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
		name = "��ũ";
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
		cout << name << "�� " << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << health << endl;
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
		name = "Ʈ��";
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
		cout << name << "�� " << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << health << endl;
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
		name = "������";
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
		cout << name << "�� " << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << health << endl;
	}
};

int main()
{
	string characterName;
	cout << "�̸��� �Է����ּ��� ���δ�: ";
	cin >> characterName;
	Character player(characterName);
	player.displayStatus();


	while (true)
	{
		int choice;
		cout << "1. �÷��̾� ����!!" << endl;
		cout << "2. �ο� ����!!" << endl;
		cout << "3. ������ ���!!" << endl;
		cout << "4. ���� ����!!" << endl;

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
			cout << "���� ����..." << endl;
			break;
		}
		else
		{
			cout << "�߸��� �Է°� �Դϴ�. 1,2,3,4 �߿� �Է����ּ���." << endl;
		}
	}


	return 0;
}