#pragma once
#include <stdio.h>

namespace Phantom {
	enum LogPriority {
		All,
		TracePriority,
		DebugPriority,
		InfoPriority,
		WarnPriority,
		ErrorPriority,
		FatalPriority,
		None
	};

	class Logger {
	private:
		static LogPriority m_Priority;

	public:
		static void SetPriority(LogPriority priority) {
			m_Priority = priority;
		}

		template<typename... Args>
		static void Trace(const char* msg, Args... args) {
			if (m_Priority < TracePriority) {
				printf("[TRACE]\t");
				printf(msg, args...);
				printf("\n");
			}
		}

		template<typename... Args>
		static void Debug(const char* msg, Args... args) {
			if (m_Priority < DebugPriority) {
				printf("[DEBUG]\t");
				printf(msg, args...);
				printf("\n");
			}
		}

		template<typename... Args>
		static void Info(const char* msg, Args... args) {
			if (m_Priority < InfoPriority) {
				printf("[INFO]\t");
				printf(msg, args...);
				printf("\n");
			}
		}

		template<typename... Args>
		static void Warn(const char* msg, Args... args) {
			if (m_Priority < WarnPriority) {
				printf("[WARNING]\t");
				printf(msg, args...);
				printf("\n");
			}
		}

		template<typename... Args>
		static void Error(const char* msg, Args... args) {
			if (m_Priority < ErrorPriority) {
				printf("[ERROR]\t");
				printf(msg, args...);
				printf("\n");
			}
		}

		template<typename... Args>
		static void Fatal(const char* msg, Args... args) {
			if (m_Priority < FatalPriority) {
				printf("[FATAL]\t");
				printf(msg, args...);
				printf("\n");
			}
		}

	};
	LogPriority Logger::m_Priority = InfoPriority;
}
