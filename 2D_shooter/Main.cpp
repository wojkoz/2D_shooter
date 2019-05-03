#include "Game.h"
#include "Network/Network.h"
#include <thread>
using namespace std;


int main() {
	unsigned short x;
	string s;
	cin >> x;
	cin >> s;
	Network network(x,s);
	network.send();
	Game game;
	
	game.run();


	return 0;
}