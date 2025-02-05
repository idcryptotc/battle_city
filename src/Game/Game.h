#pragma once

#include <vec2.hpp>
#include <array>

namespace Game
{
	class Game
	{
	public:
		Game(const glm::ivec2& windowSize);
		
		~Game();

		void render();
		void update(uint64_t delta);
		void setKey(int key, int action);
		bool init() const;

	private:
		enum class EGamesState
		{
			Active,
			Pause,
		};

		static const int countKeys = 349;
		std::array<bool, countKeys> m_keys;
		EGamesState m_eCurrentGamesState;
		glm::ivec2 m_windowSize;
	};
}