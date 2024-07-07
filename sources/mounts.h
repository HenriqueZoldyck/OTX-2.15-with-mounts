/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2019  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FS_MOUNTS_H_73716D11906A4C5C9F4A7B68D34C9BA6
#define FS_MOUNTS_H_73716D11906A4C5C9F4A7B68D34C9BA6

struct Mount
{
	Mount(uint16_t id, uint16_t clientId, std::string name, bool premium) :
		name(std::move(name)), clientId(clientId), id(id), premium(premium) {}

	std::string name;
	uint16_t clientId;
	uint16_t id;
	bool premium;
};

class Mounts
{
	public:
		static Mounts* getInstance()
		{
			static Mounts instance;
			return &instance;
		}

		bool loadFromXml();
		bool parseMountNode(xmlNodePtr p);
		Mount* getMountByID(uint8_t id);
		Mount* getMountByClientID(uint16_t clientId);

		const std::vector<Mount>& getMounts() const {
			return mounts;
		}

	private:
		std::vector<Mount> mounts;
};

#endif
