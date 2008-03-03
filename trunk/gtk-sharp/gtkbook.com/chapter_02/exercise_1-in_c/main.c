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

static void destroy (GtkWidget*, gpointer);
static gboolean key_press_event (GtkWidget   *widget,
							   GdkEventKey *event,
							   gpointer     user_data);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *label;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Thomas");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_widget_set_size_request (window, 300, 100);
  
  // Make the window not resizeable
  gtk_window_set_resizable (GTK_WINDOW (window), FALSE);

  /* Connect the main window to the destroy and delete-event signals. */
  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);
                    
  g_signal_connect (G_OBJECT (window), "key-press-event",
  					G_CALLBACK (key_press_event), NULL);

  /* Create a new GtkLabel widget that is selectable. */
  label = gtk_label_new ("Wiest");
  gtk_label_set_selectable (GTK_LABEL (label), TRUE);

  /* Add the label as a child widget of the window. */
  gtk_container_add (GTK_CONTAINER (window), label);
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}

/* Stop the GTK+ main loop function. */
static void
destroy (GtkWidget *window,
         gpointer data)
{
  gtk_main_quit ();
}

// Swap the title and the label text
static gboolean
key_press_event (GtkWidget   *window,
			   GdkEventKey *event,
			   gpointer     user_data)
{
	GtkWidget *label = gtk_bin_get_child (GTK_BIN (window));
	const gchar *tmp_title = gtk_window_get_title (GTK_WINDOW (window));
	
	if (g_ascii_strcasecmp(tmp_title, "Thomas") == 0)
	{
		gtk_window_set_title (GTK_WINDOW (window), "Wiest");
		gtk_label_set_text (GTK_LABEL (label), "Thomas");
	}
	else
	{
		gtk_window_set_title (GTK_WINDOW (window), "Thomas");
		gtk_label_set_text (GTK_LABEL (label), "Wiest");
	}
}
