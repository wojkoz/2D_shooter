#include "Network.h"


void Network::send()
{
	//socket.send(packet, ip, port);
	socket.receive(packet, ip, port);
	int x;
	std::string s;
	packet >> x >> s;
	std::cout << x << "\t" << s << std::endl;
}

Network::Network(unsigned short serverPort, std::string &ipAddress)
{
	ip = sf::IpAddress(ipAddress);
	port = serverPort;

	if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
		std::cout << "Socket error port:\t" << socket.getLocalPort()<<std::endl;
	}
	packet << 12 << "osiem";
	socket.send(packet, ip, port);
	packet.clear();

}


Network::~Network()
{
}
