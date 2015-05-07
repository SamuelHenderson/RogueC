#include <math.h>

class Ai {
public:
	virtual void update(Actor *owner) = 0;
};

class MonsterAi : public Ai {
public:
	void update(Actor *owner);
	inline double round(double x) { return (floor(x + 0.5)); }	
protected:
	int moveCount;
	void moveOrAttack(Actor *owner, int targetx, int targety);
};

class PlayerAi : public Ai {
public:
	void update(Actor *owner);
	void handleActionKey(Actor *owner, int ascii);
	
protected:
	bool moveOrAttack(Actor *owner, int targetx, int targety);
	Actor *choseFromInventory(Actor *owner);
};