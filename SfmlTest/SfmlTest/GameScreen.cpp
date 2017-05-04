#include "GameScreen.hpp"

void GameScreen::Update(sf::RenderWindow &window, GameState &GameState) {
	if (!isInitialzed)
		Init(&window);
	if (isInitialzed) {
		player.Move(map_size);
		move_view();
	}
}

void GameScreen::Draw() {
	if (isInitialzed) {
		for (auto &row : map_sprites) {
			for (auto &sprite : row) {
				game_window->draw(sprite);
			}
		}
		player.Draw(*game_window);
	}
}

void GameScreen::Init(sf::RenderWindow *window)
{
	game_window = window;
	TilesetManager tileset_manager;
	//Hier wird das SpriteSheet geladen
	//muss geladen werden sonst werden einfach nur weiße Flaechen angezeigt
	tileset_manager.loadTexture(tileset_texture);
	//So wird das ganze dann geladen
	//Das Texture-Objekt wird als Referenz übergeben und gefüllt
	//test = tileset_manager.getSprite(0, 0, tileset_texture);
	//test.setPosition(sf::Vector2f(0, 0));

	Map map = Map("Assets\\Maps\\map1.bmp", tileset_texture, &tileset_manager);
	map_size = sf::Vector2f(map.getMapSize());
	map_sprites = map.getMapSprites();

	player.setPosition(sf::Vector2f(600, 450));
	player.setSize(sf::Vector2f(20, 40));
	//TODO setSprite gefällt mir noch nicht so
	player.setSprite("Assets\\Entities\\Player.png");

	isInitialzed = true;
}

void GameScreen::move_view() {
	auto player_pos = player.getPosition();
	auto view_pos = view.getCenter();

	float top, left, bottom, right;
	top = (view_pos.y - (WINDOW_HEIGHT / 2)) + view_move_distance;
	left = (view_pos.x - (WINDOW_WIDTH / 2)) + view_move_distance;
	bottom = (view_pos.y + (WINDOW_HEIGHT / 2)) - view_move_distance;
	right = (view_pos.x + (WINDOW_WIDTH / 2)) - view_move_distance;

	//TODO Wenn der View bewegt wird bleiben die Debug angaben immer an der selben stelle

	if (player_pos.y <= top)
		view.move(0, -player.getVelocity());
	else if (player_pos.x <= left)
		view.move(-player.getVelocity(), 0);
	else if (player_pos.y >= bottom)
		view.move(0, player.getVelocity());
	else if (player_pos.x >= right)
		view.move(player.getVelocity(), 0);
	game_window->setView(view);
}