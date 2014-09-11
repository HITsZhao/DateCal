/*
 * Date.cpp
 *
 *  Created on: Sep 5, 2014
 *      Author: Zhao
 */

#include "Date.h"
#include <iostream>

const unsigned int MONTH_OF_YEAR = 12;

Date::Date(unsigned int nYear,unsigned int nMonth,unsigned int nDay,int nNext)
	 : _m_nYear(nYear)
	 , _m_nMonth(nMonth)
	 , _m_nDay(nDay)
	 , _m_nNext(nNext)
{}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

bool Date::CalDate(unsigned int *nYear,unsigned int *nMonth,unsigned int *nDay)
{
	if(_m_nMonth > MONTH_OF_YEAR){
		std::cout << "bad Month number!" << std::endl;
		return false;
	}
	if(_m_nDay > (_DayOfMonth(&_m_nMonth,_IsLeapYear(&_m_nYear)))){
		std::cout << "bad Day number!" << std::endl;
		return false;
	}
	for(unsigned int i = 0; i < _m_nNext; i++)
	{
		_IncreaseDayByDay(&_m_nYear,&_m_nMonth,&_m_nDay);
	}
	*nYear 	= _m_nYear;
	*nMonth = _m_nMonth;
	*nDay 	= _m_nDay;
	return true;

}
void Date:: _IncreaseDayByDay(unsigned int *nYear, unsigned int *nMonth, unsigned int *nDay)
{
	if(_MonthNext(nMonth,_DayNext(nYear,nMonth,nDay))){
		nYear++;
	}
}
bool Date:: _DayNext(const unsigned int *nYear, const unsigned int *nMonth, unsigned int *nDay)
{
	if((++(*nDay)) > _DayOfMonth(nMonth, _IsLeapYear(nYear))){
		*nDay = 1;
		return true;
	}
	return false;
}

bool Date:: _MonthNext(unsigned int *nMonth,bool bIncMonth)
{
	if(!bIncMonth){
		return false;
	}
	if(++(*nMonth) > MONTH_OF_YEAR){
		*nMonth = 1;
		return true;
	}
	return false;
}

bool Date:: _IsLeapYear(const unsigned int *nYear)
{
	if(((*nYear) % 4 == 0 && *nYear % 100 != 0) || *nYear % 400 == 0)
		return true;
	return false;
}
unsigned int Date:: _DayOfMonth(const unsigned int *nMonth,bool bIsLeapYear)
{
	if((*nMonth) == 1 || (*nMonth) == 3 || (*nMonth) == 5 || (*nMonth) == 7
			|| (*nMonth) == 8 || (*nMonth) == 10 || (*nMonth) == 12 )
	{
		return 31;
	}else if((*nMonth) == 2){
		if(bIsLeapYear)
			return 29;
		else
			return 28;
	}else{
		return 30;
	}
}

