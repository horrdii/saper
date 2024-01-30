#include "playerAccount.h"


playerAccount::playerAccount(string nickname) {

	create(nickname);

}

playerAccount::playerAccount() {
	
}

playerAccount::~playerAccount() {

	if(fs.is_open())
		fs.close();

}


void playerAccount::create(string nickname) {

	string path = "./players/" + nickname + ".txt";

	fs.open( path.c_str(), ios::in | ios::out );

	if (!fs.is_open()) {
		fs.open(path.c_str(), ios::in | ios::out | ios::app);
		record = 0;
		fs << to_string(record);

		return;
	}
	
}



int playerAccount::getRecord() {
	return record;
}

void playerAccount::setRecord(int record) {
	
	if (record > this->record) {
		fs.clear();
		 
		fs << record;
	}

}