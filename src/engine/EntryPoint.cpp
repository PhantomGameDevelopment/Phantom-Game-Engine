#include "log/Logger.h"

int main(void) {
	Phantom::Logger::EnableFileOutput();
	Phantom::Logger::SetPriority(Phantom::All);
	Phantom::Logger::Trace("This is a trace message");
	Phantom::Logger::Info("This is an info message");
	Phantom::Logger::Debug("This is a debug message");
	Phantom::Logger::Warn("This is a warning message");
	Phantom::Logger::Error("This is an error message");
	Phantom::Logger::Fatal("This is a fatal message");
	Phantom::Logger::DisableFileOutput();
}