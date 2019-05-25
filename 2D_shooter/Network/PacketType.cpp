#include "PacketType.h"


void PacketType::makePacketType(const int type, sf::Packet & packet)
{
	packet << type;
}
