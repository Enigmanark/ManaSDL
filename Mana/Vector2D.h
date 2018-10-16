#pragma once
#ifndef __Vector2D__
#define __Vector2D__

class Vector2D {

public:

	Vector2D() {};
	~Vector2D() {};

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

private:

	float x;
	float y;
};
#endif // !__Vector2D__

