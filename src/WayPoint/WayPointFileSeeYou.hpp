/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2011 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/


#ifndef WAYPOINTFILESEEYOU_HPP
#define WAYPOINTFILESEEYOU_HPP

#include "WayPointFile.hpp"

class WayPointFileSeeYou: 
  public WayPointFile 
{
public:
  WayPointFileSeeYou(const TCHAR* file_name, const int _file_num):
    WayPointFile(file_name, _file_num) {}

protected:
  /**
   * Parses a SeeYou waypoint file line
   * @see parseLine()
   * @see http://data.naviter.si/docs/cup_format.pdf
   */
  bool parseLine(const TCHAR* line, const unsigned linenum,
                 Waypoints &way_points);

  bool IsWritable() { return false; }

private:
  static void appendStringWithSeperator(tstring &dest, const TCHAR *src,
                                        const TCHAR seperator=' ');
  static bool parseAngle(const TCHAR* src, Angle& dest, const bool lat);
  static bool parseAltitude(const TCHAR* src, fixed& dest);
  static bool parseDistance(const TCHAR* src, fixed& dest);
  static bool parseFlags(const TCHAR* src, WaypointFlags& dest);
  static bool parseStyle(const TCHAR* src, WaypointFlags& dest);
};

#endif
