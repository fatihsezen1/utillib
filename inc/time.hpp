//time.hpp
#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <iomanip>

class Time {

public:
	// constructers
constexpr Time() :
	m_hour{}, m_minute{}, m_second{}, m_totalsec{}
{
}
constexpr Time(int hour, int minute, int second) :
	m_hour{ hour }, m_minute{ minute }, m_second{ second }, m_totalsec{}
{
	if ((hour > 23) || (minute > 59) || (second > 59)) {
		std::cerr << "[Time::Time] gecersiz bir saat bilgisi...\r\n";
		exit(EXIT_FAILURE);
	}
	else {
		m_totalsec = totalsec();
	}
}

	// getters
	constexpr int hour() const { return m_hour; }
	constexpr int second() const { return m_second; }
	constexpr int minute() const { return m_minute; }

	// setters
	void hour(int hour);
	void second(int second);
	void minute(int minute);

	// utilities
	void disp() const;
	void addsec(int second);
	void addmin(int minute);
	void addhour(int hour);
	void addtime(const Time& t);
	void addtime(int hour, int second, int minute);
	constexpr int comp(const Time& t) const
	{
		return m_totalsec - t.totalsec();
	}
	constexpr int comp(int hour, int minute, int second) const
	{
		if ((hour > 23) || (minute > 59) || (second > 59)) {
			std::cerr << "[Time::comp] gecersiz bir saat bilgisi...\r\n";
			exit(EXIT_FAILURE);
		}
		int sec = (hour * 60 * 60) + (minute * 60) + second;
		return m_totalsec - sec;
	}

	constexpr int totalsec() const
	{
		return ((m_hour * 60 * 60) + (m_minute * 60) + m_second);
	}
	void totalsec(int tsec);
	double totalmin() const;
	double totalhour() const;

private:
	void reghour()
	{
		if (m_second > 59) {
			m_minute += m_second / 60;
			m_second %= 60;
		}

		if (m_minute > 59) {
			m_hour += m_minute / 60;
			m_minute %= 60;
		}

		if (m_hour > 23) {
			m_hour %= 24;
		}
	}

private:
	int m_hour;
	int m_minute;
	int m_second;
	int m_totalsec;

};

#endif // TIME_HPP