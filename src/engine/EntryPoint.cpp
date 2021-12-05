#include "log/Logger.h"

int main(void) {
	Phantom::Logger::SetPriority(Phantom::LogPriority::All);
	Phantom::Logger::Trace("Hello World (%d, %s)", 5, "Hein Dekkers");
}