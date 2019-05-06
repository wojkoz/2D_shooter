#include "Network.h"


void Network::receivePacket(sf::Packet &packet)
{
	socket.receive(packet, ip, port);
}

void Network::sendPacket(sf::Packet & p)
{
	socket.send(p, ip, port);
}

Network::Network(unsigned short serverPort, std::string &ipAddress)
{
	ip = sf::IpAddress(ipAddress);
	port = serverPort;

	if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
		std::cout << "Socket error port:\t" << socket.getLocalPort()<<std::endl;
	}
	socket.setBlocking(false);
}


Network::~Network()
{
}


