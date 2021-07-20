#pragma once
class Object : public Sprite
{
public:
	Object();
	Object(const string& textureFilePath);
	Object(const string& textureFilePath, const Vector2f& position);
	virtual ~Object() = default;

private:
	bool isActive = true;
	//bool hitBoxActive = true;

	//Vertex hitBox[5];

private:
	Texture* texture = nullptr;

	//debugBox Vertices
	Vertex* vertices = nullptr;
	Color boxColor = Color::Red;
	bool debugBox = true;
	//virtual void Init() = 0;

public:
	virtual void Destroy();

	void SetDebugBoxActive(bool isActive);
	void SetActive(bool isActive);

	void SetBoxColor(const Color& color);
	void SetBoxColor(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

