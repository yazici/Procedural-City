#include "GlslShader.h"

GlslShader::GlslShader()
{
	_isLoaded = false;
}

GlslShader::GlslShader(std::string fileName, irr::video::IGPUProgrammingServices* gpu, int type)
{
	load(fileName, gpu, type);
}

void GlslShader::load(std::string fileName, irr::video::IGPUProgrammingServices* gpu, int type)
{
	bool hasFrag = false;
	bool hasVert = false;
	std::string fragFile = "";
	std::string vertFile = "";
	
	if((type & Shader::TYPE_PIXEL) != 0)
	{
		fragFile = "shaders/glsl/";
		fragFile += fileName;
		fragFile += ".frag";

		hasFrag = true;
	}

	if((type & Shader::TYPE_VERT) != 0)
	{
		vertFile = "shaders/glsl/";
		vertFile += fileName;
		vertFile += ".vert";

		hasVert = true;
	}

	_materialType = (irr::video::E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterialFromFiles(
			hasVert ? vertFile.c_str() : 0, hasVert ? "main" : 0, irr::video::EVST_VS_1_1,
			hasFrag ? fragFile.c_str() : 0, hasFrag ? "main" : 0, irr::video::EPST_PS_1_1
		);

	_isLoaded = true;
}

void GlslShader::apply(irr::scene::ISceneNode* node)
{
	if(_isLoaded)
		node->setMaterialType(_materialType);
}