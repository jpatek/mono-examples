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
//   Thomas Wiest (tw-mono_examples_project@wiestfamily.org)
//
//--------------------------------------------------------------------------------



#include <gtk/gtk.h>

static void destroy (GtkWidget*, gpointer);
static gboolean delete_event (GtkWidget*, GdkEvent*, gpointer);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *label;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "c - Hello World!");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_widget_set_size_request (window, 400, 100);

  /* Connect the main window to the destroy and delete-event signals. */
  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);
  g_signal_connect (G_OBJECT (window), "delete_event",
                    G_CALLBACK (delete_event), NULL);

  /* Create a new GtkLabel widget that is selectable. */
  label = gtk_label_new ("Hello World");
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

/* Return FALSE to destroy the widget. By returning TRUE, you can cancel
 * a delete-event. This can be used to confirm quitting the application. */
static gboolean
delete_event (GtkWidget *window,
              GdkEvent *event,
              gpointer data)
{
  return FALSE;
}
