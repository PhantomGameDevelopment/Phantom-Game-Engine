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
	public:
		static void SetPriority(LogPriority priority) {
			m_Priority = priority;
		}

		static void EnableFileOutput() {
			m_OutPath = "output.log";
			enableFileOutput();
		}

		static void EnableFileOutput(const char* filepath) {
			m_OutPath = filepath;
			enableFileOutput();
		}

		static void DisableFileOutput() {
			freeFile();
		}

		template<typename... Args>
		static void Trace(const char* msg, Args... args) {
			if (m_Priority < TracePriority) {
				log("TRACE", FatalPriority, msg, args...);
			}
		}

		template<typename... Args>
		static void Debug(const char* msg, Args... args) {
			if (m_Priority < DebugPriority) {
				log("DEBUG", FatalPriority, msg, args...);
			}
		}

		template<typename... Args>
		static void Info(const char* msg, Args... args) {
			if (m_Priority < InfoPriority) {
				log("INFO", FatalPriority, msg, args...);
			}
		}

		template<typename... Args>
		static void Warn(const char* msg, Args... args) {
			if (m_Priority < WarnPriority) {
				log("WARN", FatalPriority, msg, args...);
			}
		}

		template<typename... Args>
		static void Error(const char* msg, Args... args) {
			if (m_Priority < ErrorPriority) {
				log("ERROR", FatalPriority, msg, args...);
			}
		}

		template<typename... Args>
		static void Fatal(const char* msg, Args... args) {
			if (m_Priority < FatalPriority) {
				log("FATAL", FatalPriority, msg, args...);
			}
		}
	private:
		static LogPriority m_Priority;
		static const char* m_OutPath ;
		static FILE* m_File;

	private:
		template<typename... Args>
		static void log(const char* msgPriorStr, LogPriority p, const char* msg, Args... args) {
			if (m_Priority < p) {
				printf("[%s]\t%s\n", msgPriorStr, msg, args...);
				if (m_File) {
					fprintf(m_File, "[%s]\t%s\n", msgPriorStr, msg, args...);
				}
			}
		}

		static void enableFileOutput() {
			if (m_File != 0) {
				fclose(m_File);
			}
			m_File = fopen(m_OutPath, "a");
			if (m_File == 0) {
				printf("(Phantom::Logger) Failed to open file at: %s", m_OutPath);
			}
		}

		static void freeFile() {
			fclose(m_File);
			m_File = 0;
		}
	};
	LogPriority Logger::m_Priority = All;
	const char* Logger::m_OutPath = 0;
	FILE* Logger::m_File;
}
