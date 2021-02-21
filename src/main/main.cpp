/* ============================================================
* QuiteRSS is a open-source cross-platform RSS/Atom news feeds reader
* Copyright (C) 2011-2021 QuiteRSS Team <quiterssteam@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
* ============================================================ */
#include "globals.h"
#include "mainapplication.h"
#include "logfile.h"
#if defined(Q_OS_WIN)
#include <windows.h>
#endif

int main(int argc, char **argv)
{
  if (globals.logFileOutput_) {
#if defined(HAVE_QT5)
    qInstallMessageHandler(LogFile::msgHandler);
#else
    qInstallMsgHandler(LogFile::msgHandler);
#endif
  }

#if QT_VERSION >= QT_VERSION_CHECK(5, 13, 0)

#elif QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#elif QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  qputenv("QT_DEVICE_PIXEL_RATIO", "auto");
#endif

  MainApplication app(argc, argv);

  if (app.isClosing())
    return 0;

  return app.exec();
}
