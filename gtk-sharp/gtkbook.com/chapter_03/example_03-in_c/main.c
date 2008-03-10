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

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *hpaned, *button1, *button2;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "c - Panes");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_widget_set_size_request (window, 225, 150);

  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);
  
  hpaned = gtk_hpaned_new ();
  button1 = gtk_button_new_with_label ("Resize");
  button2 = gtk_button_new_with_label ("Me!");
  
  g_signal_connect_swapped (G_OBJECT (button1), "clicked",
                            G_CALLBACK (gtk_widget_destroy), 
                            (gpointer) window);
  g_signal_connect_swapped (G_OBJECT (button2), "clicked",
                            G_CALLBACK (gtk_widget_destroy), 
                            (gpointer) window);
 
  /* Pack both buttons as the two children of the GtkHPaned widget. */ 
  gtk_paned_add1 (GTK_PANED (hpaned), button1);
  gtk_paned_add2 (GTK_PANED (hpaned), button2);

  gtk_container_add (GTK_CONTAINER (window), hpaned);
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}

static void
destroy (GtkWidget *window,
         gpointer data)
{
  gtk_main_quit ();
}
