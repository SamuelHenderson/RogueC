class Engine {
public:
	enum GameStatus {
		STARTUP,
		IDLE,
		NEW_TURN,
		VICTORY,
		DEFEAT
	} gameStatus;
	
	TCOD_key_t lastKey;
	TCOD_mouse_t mouse;
	TCODList<Actor *> actors;
	Actor *player;
	Actor *stairs;
	Map *map;
	int fovRadius;
	int screenWidth;
	int screenHeight;
	int level;
	void nextLevel();
	Gui *gui;
	
	Engine(int screenWidth, int screenHeight);
	~Engine();
	void update();
	void render();
	void sendToBack(Actor *actor);
	Actor *getClosestMonster(int x, int y, float range) const;
	bool pickATile(int *x, int *y, float maxRange = 0.0f);
	Actor *getActor(int x, int y) const;
	void init();
	void term();
	void load();
	void save();
};

extern Engine engine;