#pragma once
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

class Network
{
public:

	void receivePacket(sf::Packet &packet);
	void sendPacket(sf::Packet &p);
	Network(unsigned short serverPort, std::string &ipAddress);
	~Network();
private:
	sf::UdpSocket socket;
	sf::IpAddress ip;
	unsigned short port;
	
};

