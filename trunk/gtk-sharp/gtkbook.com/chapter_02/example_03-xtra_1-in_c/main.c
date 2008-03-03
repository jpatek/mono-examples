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
static void relief_property_changed (GObject *widget,
						 			 GParamSpec *property,
									 gpointer data);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *button;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  
  // Store data in the window, then use that data as the title
  g_object_set_data (G_OBJECT (window), "title", "c - Buttons");
  gtk_window_set_title (GTK_WINDOW (window), (char *)g_object_get_data(G_OBJECT (window), "title"));
  
  gtk_container_set_border_width (GTK_CONTAINER (window), 25);
  gtk_widget_set_size_request (window, 200, 100);

  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);

  /* Create a new button that has a mnemonic key of Alt+C. */
  button = gtk_button_new_with_mnemonic ("_Close");
  
  g_signal_connect (G_OBJECT (button), "notify::relief",
                    G_CALLBACK (relief_property_changed), NULL);
  
  gtk_button_set_relief (GTK_BUTTON (button), GTK_RELIEF_NONE);
  
  /* Connect the button to the clicked signal. The callback function recieves the
   * window followed by the button because the arguments are swapped. */
  g_signal_connect_swapped (G_OBJECT (button), "clicked",
                            G_CALLBACK (gtk_widget_destroy),
                            (gpointer) window);

  gtk_container_add (GTK_CONTAINER (window), button);
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}

// Print out that the btn.relief property changed
static void
relief_property_changed (GObject *widget,
						 GParamSpec *property,
						 gpointer data)
{
	g_message("The btn.relief property changed");
}

/* Stop the GTK+ main loop function. */
static void
destroy (GtkWidget *window,
         gpointer data)
{
  gtk_main_quit ();
}
