#pragma once
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

class Network
{
public:
	sf::Packet packet;
	void send();
	Network(unsigned short serverPort, std::string &ipAddress);
	~Network();
private:
	sf::UdpSocket socket;
	sf::IpAddress ip;
	unsigned short port;
	
};

