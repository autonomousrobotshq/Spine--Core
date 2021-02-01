//
// Spine - Spine - MCU code for robotics.
// Copyright (C) 2019-2021 Codam Robotics
//
// This file is part of Spine.
//
// Spine is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Spine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Spine.  If not, see <http://www.gnu.org/licenses/>.
//

#include "Core.hpp"

Core::Core()
	: _controllers(_controller_store)
	, _interfaces(_interface_store)
{
}

Core::~Core()
{
}

bool Core::Update()
{
	bool error = false;
	for (Controller *c : _controllers) {
		if (! c->Update()) {
			error = true;
		}
	}
	for (Interface *i : _interfaces) {
		if (! i->Update()) {
			error = true;
		}
	}
	return (errors == 0);
}

bool Core::AddController(Controller *c)
{
	if (_controllers.size() < _max_controllers) {
		_controllers.push_back(c);
		return true;
	} else {
		return false;
	}
}

bool Core::AddInterface(Interface *i)
{
	if (_interfaces.size() < _max_interfaces) {
		_interfaces.push_back(c);
	} else {
		return false;
	}
}

Core Spine = Core();
