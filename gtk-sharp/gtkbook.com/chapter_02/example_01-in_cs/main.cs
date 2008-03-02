//--------------------------------------------------------------------------------
//
// Copyright (C) 2008 Thomas Wiest (tw-mono_examples_project@wiestfamily.org)
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//--------------------------------------------------------------------------------
//
// Converted from the examples in the book:
//   Foundations of GTK+ Development
//
// Downloaded from:
//   http://gtkbook.com/
//
//--------------------------------------------------------------------------------


using System;
using Gtk;

namespace example_01
{	
	public class example_01
	{		
		public static void Main(string[] args)
		{	
			Window win;
			
			/* Initialize GTK+ and all of its supporting libraries. */
			Application.Init();
			
			/* Create a new window, give it a title and display it to the user. */
			win = new Window(WindowType.Toplevel);
			win.Title = "cs - Hello World";
			win.Show();
			
			/* Hand control over to the main loop. */
			Application.Run();
		}
	}
}




















