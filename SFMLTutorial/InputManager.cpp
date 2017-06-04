#include "InputManager.hpp"

namespace sid{
	bool InputManager::isSpriteClicked ( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window ){
		if ( sf::Mouse::isButtonPressed ( button ) ){
			sf::IntRect	 tempRect ( object.getPosition ( ).x, object.getPosition ( ).y,
									(int)object.getGlobalBounds().width, (int)object.getGlobalBounds ( ).height );
			if ( tempRect.contains ( sf::Mouse::getPosition ( window ) ) ){
				return true;
			}
			return false;
		}
		return false;
	}	

	sf::Vector2i InputManager::GetMousePosition ( sf::RenderWindow &window ){
		return sf::Mouse::getPosition ( window );
	}
}