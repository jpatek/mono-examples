//--------------------------------------------------------------------------------
//
// Copyright (C) 2007 Andrew Krause
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
// Examples from the book:
//   Foundations of GTK+ Development
//
// Downloaded from:
//   http://gtkbook.com/
//
// Modifications by:
//   Thomas Wiest (tw-mono_examples_project@wiestfamily.org)//
//--------------------------------------------------------------------------------


#include <gtk/gtk.h>

int main (int argc,
          char *argv[])
{
  GtkWidget *window;

  /* Initialize GTK+ and all of its supporting libraries. */
  gtk_init (&argc, &argv);

  /* Create a new window, give it a title and display it to the user. */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "c - Hello World");
  gtk_widget_show (window);

  /* Hand control over to the main loop. */
  gtk_main ();
  return 0;
}
