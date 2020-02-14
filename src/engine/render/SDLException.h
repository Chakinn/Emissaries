#pragma once

#include <exception>
#include <string>

namespace engine {
	namespace render {
		class SDLException : std::exception {
		public:
			SDLException(const std::string& msg) : message{ msg } {}
			std::string message;
		};

	}
}