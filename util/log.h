#pragma once

#include <string>

namespace Log {

	enum class Level : char {
		INFO = 0,
		WARNING = 1,
		ERROR = 2,
		FATAL = 3,
		NONE = 4
	};
	
	enum class Color {
		DEBUG = 10,
		INFO = 11,
		WARNING = 14,
		ERROR = 12,
		FATAL = 192,
		NORMAL = 15,
		SUBJECT = 13
	};

	class subject {
	public:
		subject(const std::string& title);
		~subject();

		subject(subject&& other) = delete;
		subject(const subject&) = delete;
		subject& operator=(subject&& other) = delete;
		subject& operator=(const subject&) = delete;
	};

	void setDelimiter(std::string delimiter);
	
	void setColor(int color);

	void debug(std::string format, ...);
	void info(std::string format, ...);
	void warn(std::string format, ...);
	void error(std::string format, ...);
	void fatal(std::string format, ...);
	void print(std::string format, ...);
	void print(std::string format, Color color, ...);

	void setLogLevel(Log::Level logLevel);
	Level getLogLevel();
};