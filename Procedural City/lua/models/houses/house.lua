--[[
    Copyright (C) 2015 Panagiotis Roubatsis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
--]]

dofile("lua/lib/vectors.lua")

--Building functions
baseIndex = 0
function createQuad(x,y,z,upX,upY,upZ,rightX,rightY,rightZ)
	normalX,normalY,normalZ = normalize(crossProduct(upX,upY,upZ,rightX,rightY,rightZ))
	
	addVertex(x,y,z)
	addUV(0,0)
	addNormal(normalX,normalY,normalZ)
	
	addVertex(x+rightX,y+rightY,z+rightZ)
	addUV(1,0)
	addNormal(normalX,normalY,normalZ)
	
	addVertex(x+rightX+upX,y+rightY+upY,z+rightZ+upZ)
	addUV(1,1)
	addNormal(normalX,normalY,normalZ)
	
	addVertex(x+upX,y+upY,z+upZ)
	addUV(0,1)
	addNormal(normalX,normalY,normalZ)
	
	addTriangle(baseIndex + 0, baseIndex + 1, baseIndex + 2)
	addTriangle(baseIndex + 2, baseIndex + 3, baseIndex + 0)
	
	baseIndex = baseIndex + 4
end

function createTriangle(x,y,z,upX,upY,upZ,rightX,rightY,rightZ)
	normalX,normalY,normalZ = normalize(crossProduct(upX,upY,upZ,rightX,rightY,rightZ))
	
	addVertex(x,y,z)
	addUV(0,0)
	addNormal(normalX,normalY,normalZ)
	
	addVertex(x+rightX,y+rightY,z+rightZ)
	addUV(1,0)
	addNormal(normalX,normalY,normalZ)
	
	addVertex(x+upX+rightX/2,y+upY+rightY/2,z+upZ+rightZ/2)
	addUV(0.5,1)
	addNormal(normalX,normalY,normalZ)
	
	addTriangle(baseIndex + 0, baseIndex + 1, baseIndex + 2)
	
	baseIndex = baseIndex + 3
end

--4 Walls
createNode()
setTexture("bricks.red.tex")

createQuad(-0.5,0,0.5, 0,1,0, 1,0,0)		--Front Wall
createQuad(0.5,0,-0.5, 0,1,0, -1,0,0)	--Back Wall

createQuad(-0.5,0,-0.5, 0,1,0, 0,0,1)	--Left Wall
createQuad(0.5,0,0.5, 0,1,0, 0,0,-1)		--Right Wall

--Two Windows
createNode()
baseIndex = 0
setTexture("windows.window.tex")

createQuad(-0.35,0.62,0.501, 0,0.2,0, 0.2,0,0)	--Left Window
createQuad(0.15,0.62,0.501, 0,0.2,0, 0.2,0,0)	--Right Window

--Roof
createNode()
baseIndex = 0
setTexture("roof.tex")

createTriangle(-0.55,0.982,0.55, 0,0.5,-0.55, 1.1,0,0)	--Roof Front
createTriangle(0.55,0.982,-0.55, 0,0.5,0.55, -1.1,0,0)	--Roof Back
createTriangle(-0.55,0.982,-0.55, 0.55,0.5,0, 0,0,1.1)	--Roof Left
createTriangle(0.55,0.982,0.55, -0.55,0.5,0, 0,0,-1.1)	--Roof Right

createQuad(0.55,0.982,0.55, 0,0,-1.1, -1.1,0,0)			--Base of the roof

--Door
createNode()
baseIndex = 0
setVertexColor(0,0,150)

createQuad(-0.1,0,0.501, 0,0.4,0, 0.2,0,0)