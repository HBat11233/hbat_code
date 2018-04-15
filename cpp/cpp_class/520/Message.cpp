/*
 * Message.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: hbat
 */
#include "Message.h"
void Message::run_Message()
{
	std::cout<<"=============================================="<<std::endl;
	std::cout<<"            欢迎使用命令行文件管理器"<<std::endl;
	std::cout<<"                               ver: 0.1 by gl"<<std::endl;
	std::cout<<"=============================================="<<std::endl;
	std::cout<<"命令格式： ? xx1 xx2 …… xxN"<<std::endl;
	std::cout<<"   ?表示操作选项，xx1~xxN表示操作参数"<<std::endl;
	std::cout<<"\n操作选项如下："<<std::endl;
	std::cout<<"   md  创建文件夹       rd  删除文件夹"<<std::endl;
	std::cout<<"   cd  改变当前文件夹   ld  列出文件夹内容"<<std::endl;
	std::cout<<"   cp  复制文件/文件夹  rf  删除文件"<<std::endl;
	std::cout<<"   q   退出\n"<<std::endl;
	std::cout<<"?";\
	in_cmd();
}
std::vector<std::string> Message::split_str(std::string s)
{
	std::vector<std::string> tokens;
	std::istringstream iss(s);
	   do
	   {
		   std::string sub;
	       iss >> sub;
	       tokens.push_back(sub);
	   }while (iss);

	   tokens.erase(tokens.end()-1); // 删除最后的换行回车符

	   return tokens;
}
void Message::cmd_md()
{
	if(Message::commandArgs.size()<2)
	{
		std::cout<<"error: 请输入文件夹名字"<<std::endl;
	}
	else
	{
		std::string dirName = commandArgs[1];
		mode_t mode = 0775;
		if(mkdir(dirName.c_str(), mode)==0)
		{
			std::cout<<"创建文件夹‘"<<dirName<<"’成功"<<std::endl;
		}
		else
		{
			std::cout<<"error: 创建文件夹‘"<<dirName<<"’失败。"<<std::endl;
		}
	}
}
void Message::cmd_rd()
{
	if(commandArgs.size()<2)
	{
		std::cout<<"error: 请输入文件夹名字"<<std::endl;
	}
	else
	{
		std::string dirName = commandArgs[1];
		if(rmdir(dirName.c_str()) == 0 )
		{
			std::cout<<"删除文件夹‘"<<dirName<<"’成功"<<std::endl;
		}
		else
		{
			std::cout<<"error: 删除文件夹‘"<<dirName<<"’失败。"<<std::endl;
		}
	}
}
void Message::cmd_rf()
{
	if(commandArgs.size()<2)
	{
		std::cout<<"error: 请输入文件名字"<<std::endl;
	}
	else
	{
		std::string fileName = commandArgs[1];
		if(remove(fileName.c_str()) == 0 )
		{
			std::cout<<"删除文件‘"<<fileName<<"’成功"<<std::endl;
		}
		else
		{
			std::cout<<"error: 删除文件‘"<<fileName<<"’失败。"<<std::endl;
		}
	}
}
void Message::cmd_cd()
{
	if(commandArgs.size()<2)
	{
		std::cout<<"error: 请输入文件夹名字"<<std::endl;
	}
	else
	{
		std::string dirName = commandArgs[1];
		if(chdir(dirName.c_str())==0)
		{
			char curDir[300];
			getcwd(curDir,300);
			std::cout<<"当前工作目录更改为："<<curDir<<std::endl;
		}
		else
		{
			std::cout<<"error: 改变当前文件夹失败。"<<std::endl;
		}
	}
}
void Message::cmd_ld()
{
	DIR * curDir;
	struct dirent *ent;
	struct stat entStat;
	if((curDir=opendir("."))==NULL)
	{
		std::cout<<"error: 打开当前文件夹失败。"<<std::endl;
	}
	else
	{
		while((ent=readdir(curDir))!=NULL)
		{
			if(stat(ent->d_name, &entStat) == 0)
			{
				if(entStat.st_mode & S_IFDIR)
				{
					std::cout<<std::setw(6)<<std::left<<"d";
					std::cout<<std::right<<std::setw(10)<<entStat.st_size<<std::left<<std::setw(8)<<" bytes";
					std::cout<<ent->d_name<<"/"<<std::endl;
				}
				else if(entStat.st_mode & S_IFREG)
				{
					std::cout<<std::setw(6)<<std::left<<"-";
					std::cout<<std::right<<std::setw(10)<<entStat.st_size<<std::left<<std::setw(8)<<" bytes";
					std::cout<<ent->d_name<<std::endl;
				}
			}
		}
		closedir(curDir);
	}
}
void Message::cmd_cp()
{
	if(commandArgs.size()<3)
	{
		std::cout<<"error: 请输入源文件/文件夹名和目标文件/文件夹名。"<<std::endl;
	}
	else
	{
		std::string sourceFileName = commandArgs[1];
		std::string targetFileName = commandArgs[2];
		std::ifstream sourceFile(sourceFileName.c_str(), std::ios::binary);
		std::ofstream targetFile(targetFileName.c_str(), std::ios::binary);
		targetFile<<sourceFile.rdbuf();
		targetFile.close();
		sourceFile.close();
		std::cout<<"复制成功。"<<std::endl;
	}
}
void Message::cmd_er()
{
	std::cout<<"error: 命令错误。"<<std::endl;
}
void Message::in_cmd()
{
	getline(std::cin,commandLine);
	commandArgs=split_str(commandLine);
	while(commandArgs.size()>0 && "q"!=commandArgs[0])
	{
			if("md"==commandArgs[0])
			{
				//创建文件夹
				cmd_md();
			}
			else if("rd"==commandArgs[0])
			{
				//删除文件夹
				cmd_rd();
			}
			else if("rf"==commandArgs[0])
			{
				//删除文件
				cmd_rf();
			}
			else if("cd"==commandArgs[0])
			{
				//改变当前文件夹
				cmd_cd();
			}
			else if("ld"==commandArgs[0])
			{
				//列出文件夹内容
				cmd_ld();
			}
			else if("cp"==commandArgs[0])
			{
				//复制文件/文件夹
				cmd_cp();
			}
			else
			{
				cmd_er();
			}
			std::cout<<"?";
			getline(std::cin,commandLine);
			commandArgs=split_str(commandLine);
		}
}
