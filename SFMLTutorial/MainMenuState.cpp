#include <sstream>
#include <iostream>

#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"


namespace sid{
	MainMenuState::MainMenuState ( GameDataRef data ) : _data(data){
	}

	void MainMenuState::Init ( ){
		_data->assets.LoadTexture ( "Background", MAIN_MENU_BACKGROUND_FILEPATH );
		_data->assets.LoadTexture ( "Play Button", MAIN_MENU_PLAY_BUTTON );
		_data->assets.LoadTexture ( "Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER );
		_data->assets.LoadTexture ( "Game Title", MAIN_MENU_TITLE_PATH );

		_background.setTexture ( _data->assets.GetTexture ( "Background" ) );
		_playButton.setTexture ( _data->assets.GetTexture ( "Play Button" ) );
		_playButtonOuter.setTexture ( _data->assets.GetTexture ( "Play Button Outer" ) );
		_title.setTexture ( _data->assets.GetTexture ( "Game Title" ) );

		_playButton.setPosition ( ( SCREEN_WIDTH/2 )-( _playButton.getGlobalBounds ( ).width/2 ),
								  ( SCREEN_HEIGHT/2 )-( _playButton.getGlobalBounds ( ).height/2 ) );


		_playButtonOuter.setPosition ( ( SCREEN_WIDTH/2 )-( _playButtonOuter.getGlobalBounds ( ).width/2 ),
									   ( SCREEN_HEIGHT/2 )-( _playButtonOuter.getGlobalBounds ( ).height/2 ) );

		_title.setPosition ( ( SCREEN_WIDTH/2 )-( _title.getGlobalBounds ( ).width/2 ),
							_title.getGlobalBounds ( ).height*0.1  );

	}

	void MainMenuState::HandleInput ( ){
		sf::Event event;
		while ( _data->window.pollEvent(event) ){
			if ( sf::Event::Closed==event.type ){
				_data->window.close ( );
			}
			if ( _data->input.isSpriteClicked ( _playButton, sf::Mouse::Button::Left, _data->window ) ){
				std::cout<<"Go to Game Screen"<<std::endl;
			}
		}
	}

	void MainMenuState::Update ( float dt ){

	}

	void MainMenuState::Draw ( float dt ){
		_data->window.clear ( );
		_data->window.draw ( _background );
		_data->window.draw ( _playButton );
		_data->window.draw ( _playButtonOuter );
		_data->window.draw ( _title );
		_data->window.display ( );
	}
}


