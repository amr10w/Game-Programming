#pragma once

#include "Assets.h"
#include "Scene.h"

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

class Scene;

typedef std::map<std::string, std::shared_ptr<Scene> > SceneMap;

class GameEngine
{
	sf::RenderWindow m_window;
	std::string m_currentScene;
	Assets m_assets;
	SceneMap m_scenesMap;
	bool m_running = true;

	void init(const std::string& path);
	void update();
	std::shared_ptr<Scene> currentScene();
	void SUserInput();

public:
	GameEngine(const std::string& path);

	bool isRunning()const;
	Assets getAssets()const;
	sf::RenderWindow getWindow();

	void run();
	void quit();
	void changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene);




	

	
};

