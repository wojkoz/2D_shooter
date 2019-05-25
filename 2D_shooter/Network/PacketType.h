#pragma once
#include "SFML/Network/Packet.hpp"
class PacketType {
public:
	const int Disconnect = -1, Connect = 0, Player_Update = 1;

	void makePacketType(const int type, sf::Packet& packet);
};

