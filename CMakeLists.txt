cmake_minimum_required(VERSION 3.15)
project(SpaceInvadersV2)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(SpaceInvadersV2 NONSDL/main.cpp NONSDL/Entity.cpp NONSDL/Entity.h NONSDL/PlayerShip.cpp NONSDL/PlayerShip.h SDL/SDLPlayerShip.cpp SDL/SDLPlayerShip.h SDL/SDLWindow.cpp SDL/SDLWindow.h SDL/SDLTexture.cpp SDL/SDLTexture.h NONSDL/AFactory.h NONSDL/Game.cpp NONSDL/Game.h SDL/SDLFactory.cpp SDL/SDLFactory.h SDLConstants.h NONSDL/PlayerInput.cpp NONSDL/PlayerInput.h SDL/SDLPlayerInput.cpp SDL/SDLPlayerInput.h NONSDL/Bullet.cpp NONSDL/Bullet.h SDL/SDLBullet.cpp SDL/SDLBullet.h GameConstants.h NONSDL/Enemy.cpp NONSDL/Enemy.h SDL/SDLEnemy.cpp SDL/SDLEnemy.h NONSDL/Projectile.cpp NONSDL/Projectile.h SDL/SDLProjectile.cpp SDL/SDLProjectile.h NONSDL/Timer.cpp NONSDL/Timer.h SDL/SDLTimer.cpp SDL/SDLTimer.h NONSDL/Window.cpp NONSDL/Window.h NONSDL/PBonus.cpp NONSDL/PBonus.h NONSDL/NBonus.cpp NONSDL/NBonus.h SDL/SDLPBonus.cpp SDL/SDLPBonus.h SDL/SDLNBonus.cpp SDL/SDLNBonus.h NONSDL/BonusEntity.cpp NONSDL/BonusEntity.h NONSDL/Sound.cpp NONSDL/Sound.h SDL/SDLSound.cpp SDL/SDLSound.h)
target_link_libraries(SpaceInvadersV2 ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)