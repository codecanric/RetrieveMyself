#include "SceneEntrance.h"
#include "InfoStr.h"
using namespace cocos2d;

class LayerHelloWorld : public Layer
{
public:
	bool init();
	CREATE_FUNC(LayerHelloWorld);
};

bool LayerHelloWorld::init()
{
	if (!Layer::init()) {
		return false;
	}
	//Get window size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	// Add "HelloWorld" splash screen
	auto sprite = Sprite::create(InfoFilePath::picHelloWorld);
	// Position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// Add the sprite as a child to this layer
	addChild(sprite, 0);

	return true;
}

bool SceneEntrance::init()
{
	if (!Scene::init()){
		return false;
	}

	addChild(LayerHelloWorld::create());

	return true;
}
