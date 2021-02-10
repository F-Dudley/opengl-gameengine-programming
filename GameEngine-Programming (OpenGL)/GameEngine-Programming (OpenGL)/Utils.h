#pragma once

#include <iostream>
#include <GL\glew.h>

const struct Utils {

	static void displayShaderError(GLuint _shaderID) {
		GLint _MsgLen = 0;

		glGetShaderiv(_shaderID, GL_INFO_LOG_LENGTH, &_MsgLen);

		if (_MsgLen > 1) {
			GLchar* _Msg = new GLchar[_MsgLen + 1];

			glGetShaderInfoLog(_shaderID, _MsgLen, NULL, _Msg);

			std::cerr << "---\nError Compiling Shader\nERROR: " << _Msg << std::endl;

			delete[] _Msg;
		}
	}
};