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

#include "settingsmenu.h"

SettingsMenu::SettingsMenu(UI::Core::Window * win)
{
    addChild(std::make_shared<UI::Controls::Button>("BTPlay", UI::Core::Margin::CenterCenter(200, 200, -32, 64), UI::Locale::Str("play"), [] {}));
    addChild(std::make_shared<UI::Controls::Button>("optionsbtn", UI::Core::Margin::CenterCenter(200, -3, -70, 102), UI::Locale::Str("option"), [] {}));
    addChild(std::make_shared<UI::Controls::Button>("quitbtn", UI::Core::Margin::CenterCenter(-3, 200, -70, 102), UI::Locale::Str("exit"), [] {}));
}