#include "Game.h"
#include "Network/Network.h"
using namespace std;


int main() {
	unsigned short x;
	string s;
	cin >> x;
	getline(std::cin, s);
	Network network(x,s);
	network.send();
	Game game;
	
	game.run();


	return 0;
}