#ifndef _INFO_STR_H_
#define _INFO_STR_H_
#include <cocos2d.h>
#include <string>
/**
@brief	Define data files' path
*/
namespace InfoFilePath
{
	//plists
	const char plistCN[] = "plists/CN.plist";

	//fonts
	const char fontDefault[] = "fonts/NotoSansCJK-Regular.ttc";

	//pics
	const char picHelloWorld[] = "pics/HelloWorld.png";

}

namespace InfoStrKeyName
{
	const char CJKTest[] = "CJKTest";
}

/**
@brief	Define error codes.
*/
namespace InfoErr
{
	const char ERR_FILE_NOT_FOUND[] = "ERR_FILE_NOT_FOUND";
	const char ERR_NULL_POINTER[]	= "ERR_NULL_POINTER";
}

/**
@brief A tool to get strings from a pre-defined plist file.
*/
class plistStrReader
{
public:
	/**
	@brief Returns a shared instance of plistStrReader
	*/
	static plistStrReader* getInstance()
	{
		static plistStrReader instance;
		return &instance;
	}
	/**
	@brief Get a string according to the specified string KeyName
	@return A instance of string.
	It will return an empty string if the objects aren't string pointer or the key wasn't found.
	*/
	const std::string GetStrByKey(const std::string& KeyName)
	{
		return std::string(plistDic->valueForKey(KeyName)->getCString());
	}

private:
	plistStrReader()						// Constructor
	{
		plistDic = cocos2d::Dictionary::createWithContentsOfFile(InfoFilePath::plistCN);
	}
	plistStrReader(plistStrReader const&);	// Do not implement
	void operator=(plistStrReader const&);	// Do not implement
	cocos2d::Dictionary* plistDic;
};

#endif // _INFO_STR_H_
