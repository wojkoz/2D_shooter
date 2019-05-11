#pragma once
#include "SFML/Network/Packet.hpp"
enum class PacketType {
	Disconnect = -1, Connect, Player_Update
};
void makePacketType(const PacketType& type, sf::Packet& packet);
