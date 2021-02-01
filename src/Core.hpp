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

#ifndef CORE_HPP
#define CORE_HPP

#include "Controller.hpp"
#include "Interface.hpp"

class Core
{
	public:
		Core();
		~Core();
		bool Update();
		bool AddController(Controller *c);
		bool AddInterface(Interface *i);
	private:
		static const uint8_t _max_controllers = 12;
		Controller *_controller_store[_max_controllers];
		Vector<Controller*> _controllers;

		static const uint8_t _max_interfaces = 12;
		Interface *_interface_store[_max_interfaces];
		Vector<Interface*> _interfaces;

};

extern Core Spine;

#endif
