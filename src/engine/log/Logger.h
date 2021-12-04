#pragma once
#include <stdio.h>

enum LogPriority {
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, FatalPriority
}

class Logger {
private:
	LogPriority m_Priority;


public:
	static void SetPriority(LogPriority priority) {
		m_Priority = priority;
	}

	template<typename... Args>
	static void Trace(const char* msg, Args... args) {
		if (priority < TracePriority) {
			printf("[TRACE]\t");
			printf(msg, args...);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Debug(const char* msg, Args... args) {
		if (priority < DebugPriority) {
			printf("[DEBUG]\t");
			printf(msg, args...);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Info(const char* msg, Args... args) {
		if (priority < InfoPriority) {
			printf("[INFO]\t");
			printf(msg, args...);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Warn(const char* msg, Args... args) {
		if (priority < WarnPriority) {
			printf("[WARNING]\t");
			printf(msg, args...);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Error(const char* msg, Args... args) {
		if (priority < ErrorPriority) {
			printf("[ERROR]\t");
			printf(msg, args...);
			printf("\n");
		}
	}

	template<typename... Args>
	static void Fatal(const char* msg, Args... args) {
		if (priority < FatalPriority) {
			printf("[FATAL]\t");
			printf(msg, args...);
			printf("\n");
		}
	}

}

LogPriority Logger::m_Priority = InfoPriority;