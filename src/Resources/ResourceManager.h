#pragma once

#include <string>
#include <memory>
#include <map>
#include <vector>

namespace RenderEngine
{
	class ShaderProgram;
	class Texture2D;
	class Sprite;
	class AnimatedSprite;
}

class ResourceManager
{
public:

	ResourceManager() = delete;
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager(const ResourceManager&&) = delete;

	~ResourceManager() = delete;

	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;

	static void setExecutiblePath(const std::string& executablePath);
	static void unloadAllResources();

	static std::shared_ptr<RenderEngine::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	static std::shared_ptr<RenderEngine::ShaderProgram> getShaderProgram(const std::string& shaderName);

	static std::shared_ptr<RenderEngine::Texture2D> loadTexture(const std::string& textureName, const std::string& texturePath);
	static std::shared_ptr<RenderEngine::Texture2D> getTexture(const std::string& textureName);

	static std::shared_ptr<RenderEngine::Sprite> loadSprite(
		const std::string& spriteName
		, const std::string& textureName
		, const std::string& shaderName
		, const unsigned int spriteWidth
		, const unsigned int spriteHeight
		, const std::string& subTextureName = "DefaultSubTexture");
	static std::shared_ptr<RenderEngine::Sprite> getSprite(const std::string& spriteName);

	static std::shared_ptr<RenderEngine::AnimatedSprite> loadAnimatedSprite(
		const std::string& animatedSpriteName
		, const std::string& textureName
		, const std::string& shaderName
		, const unsigned int animatedSpriteWidth
		, const unsigned int animatedSpriteHeight
		, const std::string& subTextureName = "DefaultSubTexture");
	static std::shared_ptr<RenderEngine::AnimatedSprite> getAnimatedSprite(const std::string& animatedSpriteName);

	static std::shared_ptr<RenderEngine::Texture2D> loadTextureAtlas(
		const std::string textureName
		, const std::string texturePath
		, std::vector<std::string> subTextures
		, const unsigned int subTextureWidth
		, const unsigned int subTextureHeight);

private:
	static std::string getFileString(const std::string& relativeFilePath);

	typedef std::map<const std::string, std::shared_ptr<RenderEngine::ShaderProgram>> ShaderProgramsMap;
	static ShaderProgramsMap m_shaderPrograms;

	typedef std::map<const std::string, std::shared_ptr<RenderEngine::Texture2D>> TexturesMap;
	static TexturesMap m_textures;

	typedef std::map<const std::string, std::shared_ptr<RenderEngine::Sprite>> SpritesMap;
	static SpritesMap m_sprites;

	typedef std::map<const std::string, std::shared_ptr<RenderEngine::AnimatedSprite>> AnimatedSpritesMap;
	static AnimatedSpritesMap m_animatedSprites;

	static std::string m_path;
};
