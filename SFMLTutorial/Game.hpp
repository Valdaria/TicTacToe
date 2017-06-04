#pragma once

#include <memory>
#include <string>
#include <iostream>

#include "SFML\Graphics.hpp"
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace sid{

	struct GameData{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game{
		public:
			Game (unsigned int width, unsigned int height, std::string title );
			~Game ( ){};
		private:
			const float dt = 1.0f / 60.0f;
			sf::Clock _clock;
			GameDataRef _data = std::make_shared<GameData> ( );
			void Run ( );
	};

}

