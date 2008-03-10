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
		
		/* Stop the GTK+ main loop function. */
		static void DeleteEvent (object obj, DeleteEventArgs args)
		{
			Application.Quit ();
		}
		
		// Swap the title and the label text
		static void KeyPressEvent (object obj, KeyPressEventArgs args)
		{
			Window win = (Window)obj;
			
			if (win.Title == "Thomas")
			{
				// because of http://www.mail-archive.com/gtk-sharp-list@lists.ximian.com/msg01547.html
				// I can't use g_object_set for gtk#
				win.Title = "Wiest";
				((Label)win.Child).Text = "Thomas";
			}
			else
			{
				win.Title = "Thomas";
				((Label)win.Child).Text = "Wiest";
			}			
		}
		
		static void TitleChanged(object widget, GLib.NotifyArgs events)
		{
			Console.WriteLine("The win.title property changed");
		}
		
		public static void Main(string[] args)
		{	
			Window win;
			Label label;
			
			/* Initialize GTK+ and all of its supporting libraries. */
			Application.Init("main", ref args);
			
			/* Create a new window, give it a title and display it to the user. */
			win = new Window(WindowType.Toplevel);
			win.Title = "Thomas";
			
			// Get notified whenever the button's relief property is changed
			win.AddNotification("title", TitleChanged);
			
			win.Resizable = false;
			win.BorderWidth = 10;
			win.SetSizeRequest(300,100);
			
			/* Connect the main window to the destroy and delete-event signals. */
			// when this window is deleted, it'll run delete_event()
			win.DeleteEvent += DeleteEvent;
			
			win.KeyPressEvent += KeyPressEvent;
			
			/* Create a new GtkLabel widget that is selectable. */
			label = new Label("Wiest");
			label.Selectable = true;
			
			/* Add the label as a child widget of the window. */
			win.Add(label);
			
			// Show the window and the label
			win.ShowAll();			
			
			/* Hand control over to the main loop. */
			Application.Run();
		}
	}
}




















