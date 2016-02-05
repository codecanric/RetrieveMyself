#include "AppDelegate.h"
#include "SceneEntrance.h"

#define DESKTOP_PLATFORM (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

#define ENABLE_FULLSCREEN 0

using namespace cocos2d;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {

}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (ENABLE_FULLSCREEN && DESKTOP_PLATFORM)
		glview = GLViewImpl::createWithFullScreen("RetrieveMyself");
#elif DESKTOP_PLATFORM
		glview = GLViewImpl::createWithRect("RetrieveMyself", Rect(0, 0, 960, 640));
#else
		glview = GLViewImpl::create("RetrieveMyself");
#endif
        director->setOpenGLView(glview);
    }
    director->getOpenGLView()->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);

#if (COCOS2D_DEBUG)
    // Turn on FPS display
    director->setDisplayStats(true);

    // Set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval((float)(1.0 / 60));
#endif

    // Create and run the entry scene
    director->runWithScene(SceneEntrance::create());

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// This function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
