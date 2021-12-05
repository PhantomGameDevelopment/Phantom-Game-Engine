#pragma once
#include <stdio.h>
#include <ctime>

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
	public:

		static void SetPriority(LogPriority priority) {
			get().m_Priority = priority;
		}

		static void EnableFileOutput() {
			get().m_OutPath = "output.log";
			get().enableFileOutput();
		}

		static void EnableFileOutput(const char* filepath) {
			get().m_OutPath = filepath;
			get().enableFileOutput();
		}

		template<typename... Args>
		static void Trace(const char* msg, Args... args) {
			get().log("TRACE", FatalPriority, msg, args...);
		}

		template<typename... Args>
		static void Debug(const char* msg, Args... args) {
			get().log("DEBUG", FatalPriority, msg, args...);
		}

		template<typename... Args>
		static void Info(const char* msg, Args... args) {
			get().log("INFO", FatalPriority, msg, args...);
		}

		template<typename... Args>
		static void Warn(const char* msg, Args... args) {
			get().log("WARN", FatalPriority, msg, args...);
		}

		template<typename... Args>
		static void Error(const char* msg, Args... args) {
			get().log("ERROR", FatalPriority, msg, args...);
		}

		template<typename... Args>
		static void Fatal(const char* msg, Args... args) {
			get().log("FATAL", FatalPriority, msg, args...);
		}
	private:
		LogPriority m_Priority = All;
		const char* m_OutPath;
		FILE* m_File = 0;

	private:
		Logger() {}
		Logger(const Logger&) = delete;
		Logger& operator = (const Logger&) = delete;

		~Logger() {
			freeFile();
		}

		static Logger& get() {
			static Logger logger;
			return logger;
		}

		template<typename... Args>
		void log(const char* msgPriorStr, LogPriority p, const char* msg, Args... args) {
			if (m_Priority < p) {
				std::time_t current = std::time(0);
				std::tm* timestamp = std::localtime(&current);
				char buffer[80];
				strftime(buffer, 80, "%H:%M:%S", timestamp);
				printf("[%s] [%s] %s\n", buffer, msgPriorStr, msg, args...);
				if (m_File) {
					fprintf(m_File, "[%s] [%s] %s\n", buffer, msgPriorStr, msg, args...);
				}
			}
		}

		void enableFileOutput() {
			if (m_File != 0) {
				fclose(m_File);
			}
			m_File = fopen(m_OutPath, "a");
			if (m_File == 0) {
				printf("(Phantom::Logger) Failed to open file at: %s\n", m_OutPath);
			}
		}

		void freeFile() {
			fclose(m_File);
			m_File = 0;
		}
	};
}
