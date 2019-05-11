#include "PacketType.h"

void makePacketType(const PacketType & type, sf::Packet & packet)
{
	packet << int(type);
	
}
