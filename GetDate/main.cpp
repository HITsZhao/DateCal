/*
 * main.cpp
 *
 *  Created on: Sep 5, 2014
 *      Author: Zhao
 */

#include "Date.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>

typedef struct Date_t{
	 int nYear;
	 int nMonth;
	 int nDay;
	 int nNext;
}Date_s;

const std::string USAGE_TIPS = "Usage:GetDate [YYYY-MM-DD] [Range]";
const std::string DATE_FORMAT = "YYYY-MM-DD";
bool DateFormatParse(Date_s *pDate,std::string sDate)
{
	if(sDate.size() == DATE_FORMAT.size() && sDate.find('-') == DATE_FORMAT.find('-')
			&& sDate.rfind('-') == DATE_FORMAT.rfind('-')){
		std::stringstream(sDate.substr(0,sDate.find('-'))) >> pDate->nYear;
		std::stringstream(sDate.substr(sDate.find('-') + 1,sDate.rfind('-'))) >> pDate->nMonth;
		std::stringstream(sDate.substr(sDate.rfind('-') + 1,sDate.size())) >> pDate->nDay;
		//std::cout << "DateFormat: "<< pDate->nYear << "-" << pDate->nMonth << "-" << pDate->nDay << std::endl;
		return true;
	}else{
		return false;
	}
}

bool ArgumentParse(Date_s *pDate,int argc, char **argv)
{
	if(argc > 3 || argc <= 0){
		std::cout << "Error: too many arguments" << std::endl;
		std::cout << USAGE_TIPS << std::endl;
		return false;
	}
	if(1 == argc){
		time_t t = time(NULL);
		struct tm now_t = *localtime(&t);
		pDate->nYear  = now_t.tm_year + 1900;
		pDate->nMonth = now_t.tm_mon + 1;
		pDate->nDay   = now_t.tm_mday;
		pDate->nNext  = 0;
		return true;
	}

	if(!DateFormatParse(pDate,argv[1])){
		std::cout << "Error: Bad Date Format" << std::endl;
		std::cout << USAGE_TIPS << std::endl;
		return false;
	}

	if(2 == argc){
		pDate->nNext = 1; // next day;
	}
	if(3 == argc){
		std::stringstream(std::string(argv[2])) >> pDate->nNext;
	}

	return true;
}

int main(int argc,char **argv)
{
	unsigned int nYear 	= 0;
	unsigned int nMonth = 0;
	unsigned int nDay 	= 0;
	Date_s date_get;
	if(!ArgumentParse(&date_get,argc,argv))
		return 1;
	Date date(date_get.nYear,date_get.nMonth,date_get.nDay,date_get.nNext);
	if(date.CalDate(&nYear,&nMonth,&nDay))
		std::cout 	<< nYear
					<< "-" << nMonth
					<< "-" << nDay << std::endl;
	return 0;
}



