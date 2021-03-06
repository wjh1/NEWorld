/*
* NEWorld: A free game with similar rules to Minecraft.
* Copyright (C) 2016 NEWorld Team
*
* This file is part of NEWorld.
* NEWorld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* NEWorld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with NEWorld.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "chunkclient.h"

VertexArray ChunkClient::va(262144, VertexFormat(2, 3, 0, 3));
bool ChunkClient::mergeFace;

void ChunkClient::buildVertexArray()
{
    va.clear();
    if (mergeFace)
    {
        // TODO: merge face rendering
    }
    else
    {
        Vec3i::for_range(0, ChunkSize, [&](const Vec3i& pos)
        {
            //Vec3i worldpos = getPosition() + pos;

            BlockData curr = getBlock(pos);
            BlockData neighbors[6] =
            {
                pos.x == ChunkSize - 1 ? BlockData(0, 15, 0) : getBlock(Vec3i(pos.x + 1, pos.y, pos.z)),
                pos.x == 0 ? BlockData(0, 15, 0) : getBlock(Vec3i(pos.x - 1, pos.y, pos.z)),
                pos.y == ChunkSize - 1 ? BlockData(0, 15, 0) : getBlock(Vec3i(pos.x, pos.y + 1, pos.z)),
                pos.y == 0 ? BlockData(0, 15, 0) : getBlock(Vec3i(pos.x, pos.y - 1, pos.z)),
                pos.z == ChunkSize - 1 ? BlockData(0, 15, 0) : getBlock(Vec3i(pos.x, pos.y, pos.z + 1)),
                pos.z == 0 ? BlockData(0, 15, 0) : getBlock(Vec3i(pos.x, pos.y, pos.z - 1)),
            };

            // Right
            if (adjacentTest(curr, neighbors[0]))
            {
                va.setColor({ 0.5f, 0.5f, 0.5f });
                va.setTexture({ 0.0f, 0.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 1.0f, pos.z + 1.0f });
                va.setTexture({ 0.0f, 1.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 0.0f, pos.z + 1.0f });
                va.setTexture({ 1.0f, 1.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 0.0f, pos.z + 0.0f });
                va.setTexture({ 1.0f, 0.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 1.0f, pos.z + 0.0f });
            }

            // Left
            if (adjacentTest(curr, neighbors[1]))
            {
                va.setColor({ 0.5f, 0.5f, 0.5f });
                va.setTexture({ 0.0f, 0.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 1.0f, pos.z + 0.0f });
                va.setTexture({ 0.0f, 1.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 0.0f, pos.z + 0.0f });
                va.setTexture({ 1.0f, 1.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 0.0f, pos.z + 1.0f });
                va.setTexture({ 1.0f, 0.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 1.0f, pos.z + 1.0f });
            }

            // Top
            if (adjacentTest(curr, neighbors[2]))
            {
                va.setColor({ 1.0f, 1.0f, 1.0f });
                va.setTexture({ 0.0f, 0.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 1.0f, pos.z + 0.0f });
                va.setTexture({ 0.0f, 1.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 1.0f, pos.z + 1.0f });
                va.setTexture({ 1.0f, 1.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 1.0f, pos.z + 1.0f });
                va.setTexture({ 1.0f, 0.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 1.0f, pos.z + 0.0f });
            }

            // Bottom
            if (adjacentTest(curr, neighbors[3]))
            {
                va.setColor({ 1.0f, 1.0f, 1.0f });
                va.setTexture({ 0.0f, 0.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 0.0f, pos.z + 1.0f });
                va.setTexture({ 0.0f, 1.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 0.0f, pos.z + 0.0f });
                va.setTexture({ 1.0f, 1.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 0.0f, pos.z + 0.0f });
                va.setTexture({ 1.0f, 0.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 0.0f, pos.z + 1.0f });
            }

            // Front
            if (adjacentTest(curr, neighbors[4]))
            {
                va.setColor({ 0.7f, 0.7f, 0.7f });
                va.setTexture({ 0.0f, 0.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 1.0f, pos.z + 1.0f });
                va.setTexture({ 0.0f, 1.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 0.0f, pos.z + 1.0f });
                va.setTexture({ 1.0f, 1.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 0.0f, pos.z + 1.0f });
                va.setTexture({ 1.0f, 0.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 1.0f, pos.z + 1.0f });
            }

            // Back
            if (adjacentTest(curr, neighbors[5]))
            {
                va.setColor({ 0.7f, 0.7f, 0.7f });
                va.setTexture({ 0.0f, 0.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 1.0f, pos.z + 0.0f });
                va.setTexture({ 0.0f, 1.0f });
                va.addVertex({ pos.x + 1.0f, pos.y + 0.0f, pos.z + 0.0f });
                va.setTexture({ 1.0f, 1.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 0.0f, pos.z + 0.0f });
                va.setTexture({ 1.0f, 0.0f });
                va.addVertex({ pos.x + 0.0f, pos.y + 1.0f, pos.z + 0.0f });
            }
        });
    }
    m_buffer = VertexBuffer(va);
}
