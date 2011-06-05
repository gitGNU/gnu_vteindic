"""
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
"""

#!/usr/bin/python

import os, string, sys

def scanheader(filename):
	definitions = {}
	file = open(filename, "r")
	if file:
		for line in file.readlines():
			if line[:12] == '#define GDK_':
				fields = string.split(line)
				fields[2] = string.lower(fields[2])
				if definitions.has_key(fields[2]):
					definitions[fields[2]] = definitions[fields[2]] + ", " + fields[1]
				else:
					definitions[fields[2]] = fields[1]
		file.close()
	for key in definitions.keys():
		print '\tcase %s: return \"%s\";' % (key, definitions[key])

print '\t/* this file is auto-generated -- do not edit */'

if len(sys.argv) > 1:
	for header in sys.argv[1:]:
		scanheader(header)
else:
	scanheader("/usr/include/gtk-2.0/gdk/gdkkeysyms.h")
