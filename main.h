/****************************************************************************
 * Copyright (C) 2017 by Andres Caceres                                     *
 *                                                                          *
 * This file is part of Pomodoro                                            *
 *                                                                          *
 *   Pomodoro is free software: you can redistribute it and/or modify it         *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Pomodoro.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

/**
 * @file main.h
 * @author Sebastian Caceres
 * @date NULL
 * @brief File containing the funcion definitions of the pomodoro app.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

#include <gtk/gtk.h>
#include <string.h>


/**
 * @brief Basic structure that contains the window dimensions.
 */
typedef struct{
  int x, y;
} Screen_size;


typedef struct{
  int flag;
  int time;
  GtkWidget* textview;
  GtkWidget* label;

} Counter_data;
/**
 * @brief Simple function that transforms an integer into an array of characters...
 *
 * We receive the seconds as an integer, then we transform them to a string with the
 * following format: minutes:seconds
 * @verbatim like this@endverbatim
 * Example of usage
 * @code
 * GtkLabel* display = gtk_label_new();
 * gtk_label_set_text(get_minutes(1)); // now our label has "00:01"
 * @endcode
 * @param seconds int
 * @return gchar* that contains the structure of minutes:seconds.
 */
static gchar* get_minutes(int seconds);
static void show_time(gchar* tiempo);
