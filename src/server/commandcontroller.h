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
#ifndef COMMANDCONTROLLER_H_
#define COMMANDCONTROLLER_H_

#include <command.h>
#include <thread>
class CommandController
{
public:
    CommandController() { m_thread = std::thread([this] { mainLoop(); }); }
    ~CommandController() { m_threadRunning = false; m_thread.join(); }

    CommandController(const CommandController&) = delete;
    CommandController& operator=(const CommandController&) = delete;

    CommandMap& getCommandMap() { return m_commandMap; }

    void addCommand(std::string name, CommandInfo info, CommandHandleFunction func)
    {
        m_commandMap.insert({name, {info, func}});
    }

private:
    void mainLoop();
    CommandExecuteStat handleCommand(Command cmd);

    std::thread m_thread;
    bool m_threadRunning = true;
    CommandMap m_commandMap;
};

#endif //!COMMANDCONTROLLER_H_
