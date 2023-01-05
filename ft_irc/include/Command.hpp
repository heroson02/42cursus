#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <map>
#include <set>
#include "Channel.hpp"
#include "Client.hpp"
#include "Util.hpp"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/poll.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <string>
#include "Define.hpp"

class Server;

class Command
{
private:
	bool isLetter(char c);
	bool isNumber(char c);
	bool isSpecial(char c);
	bool isDuplication(std::string s, std::map<int, Client *> clientList);
	bool nickValidate(std::string s);
	Server *_server;

	std::string makeFullname(int fd);
	void makePrivMessage(Client *client, std::string senderName, std::string receiver, std::string msg);
	void channelMessage(std::string msg, Client *client, Channel *channel);
	void makeNumericReply(int fd, std::string flag, std::string str);
	void makeCommandReply(int fd, std::string command, std::string str);
	void welcomeMsg(int fd, std::string flag, std::string msg, std::string name);
	void allInChannelMsg(int target, std::string channelName, std::string command, std::string msg);
	void nameListMsg(int fd, std::string channelName);
public:
	Command(Server *server);
	~Command();
	void welcome(std::vector<std::string> cmd, Client *client, std::map<int, Client *> clientList);
	void privmsg(std::vector<std::string> s, Client *client);
	void notice(std::vector<std::string> s, Client *client);
	void nick(std::vector<std::string> s, Client *client);
	void kick(std::vector<std::string> s, Client *client);
	void join(std::vector<std::string> s, Client *client);
	void part(std::vector<std::string> s, Client *client);
	void quit(std::vector<std::string> s, Client *client);
	void pong(std::vector<std::string> s, Client *client);
	void alreadyRegist(Client *client);
};

#endif