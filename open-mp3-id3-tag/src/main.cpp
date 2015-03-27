/*
Copyright (C) 2012 Carlos Tse <copperoxide@gmail.com>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <QApplication>
#include "main_window.h"
#include "common.h"

extern char *PKGDATADIR;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString path = QCoreApplication::applicationDirPath();
	PKGDATADIR = new char[path.length() + 1];
	strcpy(PKGDATADIR, path.toLocal8Bit().data());
	std::cout << PKGDATADIR << std::endl;

	MainWindow w;
	w.show();

	return a.exec();
}
