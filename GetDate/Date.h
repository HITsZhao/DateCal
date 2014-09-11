/*
 * Date.h
 *
 *  Created on: Sep 5, 2014
 *      Author: Zhao
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(unsigned int nYear,unsigned int nMonth,unsigned int nDay,int nNext);
	~Date();
	bool CalDate(unsigned int *nYear,unsigned int *nMonth,unsigned int *nDay);
private:
	unsigned int _m_nYear;
	unsigned int _m_nMonth;
	unsigned int _m_nDay;
			 int _m_nNext;
private:
	bool _IsLeapYear(const unsigned int *nYear);
	unsigned int _DayOfMonth(const unsigned int *nMonth,bool bIsLeapYear);
	void _IncreaseDayByDay(unsigned int *nYear, unsigned int *nMonth, unsigned int *nDay);
	bool _DayNext(const unsigned int *nYear, const unsigned int *nMonth, unsigned int *nDay);
	bool _MonthNext(unsigned int *nMonth,bool bIncMonth);

};

#endif /* DATE_H_ */
