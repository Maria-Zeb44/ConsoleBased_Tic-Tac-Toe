
class TTT {
	char** board;
	int size;
	char Cplayer;

public:
	TTT();
	~TTT();
	void display();
	bool isVAlidMove(int r, int c);
	bool checkWin();
	bool isDraw();
	void makeMove(int r, int c);
	void resetBoard();
	void play();
};
