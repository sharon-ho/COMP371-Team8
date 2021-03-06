#pragma once
#include "Cube.h"

class AlphaNumeric
{
public:
	AlphaNumeric(int numOfCubes);
	mat4 getModelMatrix();
	virtual void updateModelMatrix() = 0;
	void translateModel(mat4 t);
	void scaleModel(mat4 s);
	void rotateModel(mat4 r, GLuint modelMatrixLocation);
	void traverse(mat4 mat);
	void traverse(mat4 mat, Cube* current);
	void randomLocation(float x, float z);
	Cube* components;


	virtual void draw(GLuint modelMatrixLocation) = 0;
	~AlphaNumeric();

protected:
	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
	int numberOfCubes;
	
};