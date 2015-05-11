#include <math.h>

class Ai : public Persistent {
public:
	virtual void update(Actor *owner) = 0;
	static Ai *create(TCODZip &zip);
protected:
	enum AiType {
		MONSTER, CONFUSED_MONSTER, PLAYER
	};
};

class MonsterAi : public Ai {
public:
	void update(Actor *owner);
	inline double round(double x) { return (floor(x + 0.5)); }
	void save(TCODZip &zip);
	void load(TCODZip &zip);
protected:
	int moveCount;
	void moveOrAttack(Actor *owner, int targetx, int targety);
};

class ConfusedMonsterAi : public Ai {
public:
	ConfusedMonsterAi(int nbTurns, Ai *oldAi);
	void update(Actor *owner);
	void save(TCODZip &zip);
	void load(TCODZip &zip);
protected:
	int nbTurns;
	Ai *oldAi;
};

class PlayerAi : public Ai {
public:
	void update(Actor *owner);
	void handleActionKey(Actor *owner, int ascii);
	void save(TCODZip &zip);
	void load(TCODZip &zip);
protected:
	bool moveOrAttack(Actor *owner, int targetx, int targety);
	Actor *choseFromInventory(Actor *owner);
};