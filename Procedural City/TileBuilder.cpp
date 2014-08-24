#include "TileBuilder.h"

ScriptedNodeBuilder TileBuilder::_flatBuilder;

ScriptedNodeBuilder TileBuilder::_houseBuilders[1];
ScriptedNodeBuilder TileBuilder::_skyScraperBuilders[1];
ScriptedNodeBuilder TileBuilder::_apartmentBuilders[1];

ScriptedNodeBuilder TileBuilder::_grass;

ScriptedNodeBuilder TileBuilder::_twoLaneRoadBuilder;
ScriptedNodeBuilder TileBuilder::_sixLaneRoadBuilder;
ScriptedNodeBuilder TileBuilder::_sixLaneCornerBuilder;

ScriptedNodeBuilder TileBuilder::_twoToSixTRoadBuilder;
ScriptedNodeBuilder TileBuilder::_sixToTwoTRoadBuilder;
ScriptedNodeBuilder TileBuilder::_sixToSixTRoadBuilder;

ScriptedNodeBuilder TileBuilder::_sixLaneIntersection;

void TileBuilder::initialize()
{
	_flatBuilder.load("models/flat_tile");

	_houseBuilders[0].load("models/house");
	_skyScraperBuilders[0].load("models/skyscraper");
	_apartmentBuilders[0].load("models/apartment/building");

	_grass.load("models/plants/grass");

	_twoLaneRoadBuilder.load("models/road/standard_two_lane");
	_sixLaneRoadBuilder.load("models/road/standard_six_lane");
	_sixLaneCornerBuilder.load("models/road/corner_six_lane");

	_twoToSixTRoadBuilder.load("models/road/2_6_T_intersection");
	_sixToTwoTRoadBuilder.load("models/road/6_2_T_intersection");
	_sixToSixTRoadBuilder.load("models/road/6_6_T_intersection");

	_sixLaneIntersection.load("models/road/6_lane_intersection");
}

TileBuilder::TileBuilder(irr::scene::ISceneManager* sceneManager)
	: _sceneManager(sceneManager), TILE_SIZE(32)
{
	_idPool = IDRequester::requestPool(4096);
	_tileSceneNode = sceneManager->addEmptySceneNode(sceneManager->getRootSceneNode(), _idPool.request());
}

//Flat
void TileBuilder::addFlat(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _flatBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

//Buildings
void TileBuilder::addHouse(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _houseBuilders[Random::nextInt(0,0)].build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setScale(irr::core::vector3df(10,10,10));
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

void TileBuilder::addSkyScraper(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _skyScraperBuilders[Random::nextInt(0,0)].build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

void TileBuilder::addApartment(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _apartmentBuilders[Random::nextInt(0,0)].build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

//Plants
void TileBuilder::addGrass(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _grass.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

//Roads
void TileBuilder::addTwoLaneRoad(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _twoLaneRoadBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

void TileBuilder::addSixLaneRoad(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _sixLaneRoadBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

void TileBuilder::addSixLaneCornerRoad(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _sixLaneCornerBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

//T-Intersections
void TileBuilder::addTwoToSixTRoad(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _twoToSixTRoadBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

void TileBuilder::addSixToTwoTRoad(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _sixToTwoTRoadBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

void TileBuilder::addSixToSixTRoad(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _sixToSixTRoadBuilder.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

//4-Way Intersections
void TileBuilder::addSixLaneIntersection(irr::core::vector3df position, float angle)
{
	irr::scene::ISceneNode* node = _sixLaneIntersection.build(_sceneManager, _tileSceneNode, _idPool.request());
	_tileSceneNode->addChild(node);
	node->setRotation(irr::core::vector3df(0,angle,0));
	node->setPosition(position);
	node->drop();
}

irr::scene::ISceneNode* TileBuilder::getNode()
{
	return _tileSceneNode;
}