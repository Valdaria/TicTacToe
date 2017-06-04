#include "Game.hpp"

#include "SplashState.hpp"

namespace sid{
	Game::Game ( unsigned int width, unsigned int height, std::string title){
		try{
			std::string t = title;
			_data->window.create ( sf::VideoMode ( width, height ), std::string(t));
			_data->machine.AddState ( StateRef ( new SplashState ( this->_data ) ) );
			this->Run ( );

		} catch ( const std::length_error e){
			std::cout<<"probleme ici"<<std::endl;
			std::cout<<title<<std::endl;
			std::cout<<e.what()<< std::endl;
		}

	}

	void Game::Run ( ){
		float newTime, frameTime, interpolation;
		float currentTime = this->_clock.getElapsedTime ( ).asSeconds();
		float accumulator = 0.0f;

		while ( this->_data->window.isOpen() ){
			this->_data->machine.ProcessStateChanges ( );

			newTime = this->_clock.getElapsedTime ( ).asSeconds();
			frameTime = newTime-currentTime;

			if ( frameTime>0.25f ){
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;
			while ( accumulator >= dt ){
				this->_data->machine.GetActiveState ( )->HandleInput ( );
				this->_data->machine.GetActiveState ( )->Update (dt );
				accumulator -= dt;
			}

			interpolation = accumulator/dt;
			this->_data->machine.GetActiveState ( )->Draw ( interpolation );

		}
	}
}