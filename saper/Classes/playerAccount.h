#pragma once

#include "Dependencies.h"


class playerAccount
{
protected:
	fstream fs;

	std::string nickname;
	int record;

public:

	playerAccount();
	playerAccount(string nickname);

	~playerAccount();

	void create(string nickname);

	int getRecord();
	void setRecord(int record);
	

};

