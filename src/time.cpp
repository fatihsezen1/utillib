//time.cpp
#include "time.hpp"


constexpr int DAY_SEC = 86400; // bir gün 86400 saniyedir

void Time::hour(int hour)
{
	m_hour = hour;
	m_totalsec = totalsec();
}

void Time::minute(int minute)
{
	m_minute = minute;
	m_totalsec = totalsec();
}

void Time::second(int second)
{
	m_second = second;
	m_totalsec = totalsec();
}

void Time::disp() const
{
	std::cout << std::setw(2) << std::setfill('0')
		<< m_hour << ":"
		<< std::setw(2) << std::setfill('0')
		<< m_minute << ":"
		<< std::setw(2) << std::setfill('0')
		<< m_second << '('
		<< m_totalsec << ')'
		<< std::endl;
}

void Time::addsec(int second)
{
	m_second += second;
	reghour();

	m_totalsec = totalsec();
}

void Time::addmin(int minute)
{
	m_minute += minute;
	reghour();

	m_totalsec = totalsec();
}

void Time::addhour(int hour)
{
	m_hour += hour;
	reghour();

	m_totalsec = totalsec();
}

void Time::addtime(const Time& t)
{
	m_hour += t.m_hour;
	m_minute += t.m_minute;
	m_second += t.m_second;
	reghour();

	m_totalsec = totalsec();
}

void Time::addtime(int hour, int second, int minute)
{
	m_hour += hour;
	m_minute += second;
	m_second += minute;
	reghour();

	m_totalsec = totalsec();
}

void Time::totalsec(int tsec) // setter
{
	if (tsec > INT_MAX) {
		std::cout << "[Time::totalsec] parametre INT_MAX degerinden buyuk.\r\n";
		exit(EXIT_FAILURE);
	}

	tsec = tsec % DAY_SEC;
	m_hour = tsec / (60 * 60);
	m_minute = (tsec % (60 * 60)) / 60;
	m_second = tsec % 60;
	reghour();
	m_totalsec = totalsec();
}

double Time::totalmin() const
{
	return (m_hour * 60.0) + m_minute + (m_second / 60.0);
}

double Time::totalhour() const
{
	return m_hour + (m_minute / 60.0) + (m_second / 3600.0);
}