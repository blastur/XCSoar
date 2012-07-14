/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2012 The XCSoar Project
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

#ifndef IGC_REPLAY_HPP
#define IGC_REPLAY_HPP

#include "Math/fixed.hpp"
#include "AbstractReplay.hpp"
#include "Replay/CatmullRomInterpolator.hpp"
#include "IO/FileLineReader.hpp"

#include <tchar.h>
#include <windef.h> /* for MAX_PATH */
#include <stdio.h>

struct GeoPoint;
class Angle;
struct IGCFix;

class IgcReplay: public AbstractReplay
{
  CatmullRomInterpolator cli;

  TCHAR file_name[MAX_PATH];
  NLineReader *reader;

protected:
  fixed t_simulation;

public:
  IgcReplay();

  virtual bool Update(fixed time_scale) gcc_override;
  void Stop();
  void Start();
  void SetFilename(const TCHAR *name);

protected:
  virtual bool UpdateTime(fixed time_scale);
  virtual void ResetTime();

  virtual void OnReset() = 0;
  virtual void OnStop() = 0;
  virtual void OnBadFile() = 0;
  virtual void OnAdvance(const GeoPoint &loc,
                         const fixed speed, const Angle bearing,
                         const fixed alt, const fixed baroalt, const fixed t) = 0;

  bool ScanBuffer(const char *buffer, IGCFix &fix);

  bool ReadPoint(IGCFix &fix);

private:
  bool OpenFile();
  void CloseFile();
};

#endif
