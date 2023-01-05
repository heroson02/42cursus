#include "Client.hpp"

Client::Client(int clientFd) : _clientFd(clientFd), _regist(0) {}

Client::~Client() {}

std::string Client::getMsgBuffer()
{
	return _msgBuffer;
}

// 현재 client가 속한 채널이 있다면 return 해준다.
std::vector<std::string>::iterator Client::findMyChannelIt(std::string channelName) 
{
	std::vector<std::string>::iterator it = _myChannelList.begin();
	while (it != _myChannelList.end())
	{
		if ((*it) == channelName)
			return (it);
		it++;
	}
	return (_myChannelList.end());
}

void Client::removeMyChannelIt(std::vector<std::string>::iterator it)
{
	_myChannelList.erase(it);
}

void Client::removeChannelName(std::string serverName)
{
	std::vector<std::string>::iterator it = findMyChannelIt(serverName);
	if (it != _myChannelList.end())
		removeMyChannelIt(it);
}

std::vector<std::string> & Client::getMyChannelList()
{
	return(_myChannelList);
}

void Client::clearMsgBuffer()
{
	_msgBuffer = "";
}

void Client::appendMsgBuffer(std::string msgBuffer)
{
	_msgBuffer.append(msgBuffer);
}

std::string &Client::getRecvBuffer()
{
	return _recvBuffer;
}

void Client::appendRecvBuffer(std::string recvBuffer)
{
	_recvBuffer.append(recvBuffer);
}


void Client::clearRecvBuffer()
{
	_recvBuffer = "";
}

int Client::getClientFd()
{
	return _clientFd;
}

void Client::addChannelList(std::string channelName)
{
	_myChannelList.push_back(channelName);
}

void Client::setNickName(std::string nickName)
{
	_nickName = nickName;
}

std::string Client::getNickName()
{
	return _nickName;
}

void Client::setUser(std::string userName, std::string hostName, std::string serverName, std::string realName){
	_userName = userName;
	_hostName = hostName;
	_serverName = serverName;
	_realName = realName;
}

std::string Client::getUserName()
{
	return _userName;
}

std::string Client::getHostName()
{
	return _hostName;
}

std::string Client::getServerName()
{
	return _serverName;
}

std::string Client::getRealName()
{
	return _realName;
}

void Client::setRegist(int bit)
{
	_regist |= bit;
}

unsigned char Client::getRegist()
{
	return (_regist);
}