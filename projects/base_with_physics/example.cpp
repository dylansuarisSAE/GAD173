#include "example.h"
#include "mainMenu.h"
#include "Level1.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{

	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	sceneManager.Addscene(new mainMenu());
	sceneManager.Addscene(new Level1());
	sceneManager.Load();

	

	return true;
}

void Example::update(float deltaT)
{
	// You need to update the physics system every game update

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && m_window.hasFocus())
	{
		sceneManager.Loadscene(0);
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Load"))
	{ 
		sceneManager.Loadscene(1);
		sceneManager.Load();
		//std::cout << "Level 1 loaded " << std::endl;
	}
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	ImGui::End();

	sceneManager.Update();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	sceneManager.Render(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

