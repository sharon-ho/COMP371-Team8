#pragma once
#include "Cube.h"

class AlphaNumeric
{
public:
	AlphaNumeric(int numOfCubes);
	AlphaNumeric(int numOfTopCubes, int numOfBotCubes);
	~AlphaNumeric();
	mat4 getModelMatrix();
	void updateBase(Cube * b);
	Cube * getBase();
	void updateBaseTop(Cube * b);
	Cube * getBaseTop();
	void traverse(mat4 mat, int transformation);
	void traverse(mat4 mat, Cube* current, int transformation); // 0 - TRANSLATION | 1 - ROTATION | 2 - SCALING
	void updateModelMatrix();
	void translateModel(mat4 t);
	void translateModelTop(mat4 t);
	void scaleModel(mat4 s);
	void rotateModel(mat4 r, GLuint modelMatrixLocation);
	void randomLocation(float x, float z);
	//void draw(GLuint modelMatrixLocation);

	void drawTop(GLuint modelMatrixLocation);

	void drawBottom(GLuint modelMatrixLocation);

	Cube* components;
	Cube* topComponents;
	Cube* bottomComponents;
	Cube* base;
	Cube* baseTop;
protected:
	mat4 modelMatrix = mat4(1.0f);
	mat4 translationMatrix = mat4(1.0f);
	mat4 scalingMatrix = mat4(1.0f);
	mat4 rotationMatrix = mat4(1.0f);
	int numberOfCubes;
	int numberOfTopCubes;
	int numberOfBotCubes;
};