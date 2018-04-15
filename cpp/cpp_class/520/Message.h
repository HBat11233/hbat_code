/*
 * Message.h
 *
 *  Created on: 2018年4月9日
 *      Author: hbat
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

class Message
{
public:
	void run_Message();
	std::vector<std::string> split_str(std::string);
	void cmd_md();
	void cmd_rd();
	void cmd_rf();
	void cmd_cd();
	void cmd_ld();
	void cmd_cp();
	void cmd_er();
	void in_cmd();
private:
	std::string commandLine;
	std::vector<std::string> commandArgs;
};

#endif /* MESSAGE_H_ */
