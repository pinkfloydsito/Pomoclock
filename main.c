#include "main.h"
#include <stdlib.h>
static gchar* get_minutes(int seconds){
  int minutes;
  gchar* display;
  if(seconds %60 >= 0){
    minutes = seconds/60;
    seconds = seconds%60;
    if(minutes>9 && seconds >9){
      display = g_strdup_printf("%d:%d", minutes, seconds);
    }else if (minutes>9 && seconds<10) {
      display = g_strdup_printf("%d:0%d", minutes, seconds);
    }else if (minutes<10 && seconds>9) {
      display = g_strdup_printf("0%d:%d", minutes, seconds);
    }else if (minutes<10 && seconds<10) {
      display = g_strdup_printf("0%d:0%d", minutes, seconds);
    }
  }else{
    minutes =  0;
    if (seconds<10) {
      display = g_strdup_printf("0%d:0%d", minutes, seconds);
    }else if (seconds>9) {
      display = g_strdup_printf("0%d:%d", minutes, seconds);
    }
  }
  return display;
}

/* Here we update the label in order to show the time that has been flowing. */
static void updateLabel(GtkLabel* label, int seconds){
}
static void start_counter(GtkWidget *btn, Counter_data* data){
  gchar* tiempo;
  g_print("starting/restarting counter\n");
  gtk_button_set_label((GtkButton*)btn, "Started counting");
  while(gtk_events_pending()) gtk_main_iteration();
  while(1){
    sleep(1);
    tiempo = get_minutes(data->time++);
    gtk_label_set_text((GtkLabel* )((Counter_data*) data)->label, tiempo);
    while(gtk_events_pending()) gtk_main_iteration();
  }
}

static void activate (GtkApplication* app,
          gpointer        user_data){
  GtkWidget *window;
  GtkWidget *parentBox; //box made in order to package all the widgets used in the app.

  GtkWidget *btn;
  GtkWidget *btn_box;
  GtkWidget *textview;
  GtkWidget *label_time;

  /* Counter_data counter_data; */
  Counter_data *counter_data = malloc(sizeof *counter_data);
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Pomodoro 0.1");
  gtk_window_set_default_size (GTK_WINDOW (window), ((Screen_size *) user_data)->x, ((Screen_size *) user_data)->y );
  parentBox = gtk_box_new(FALSE, 0);
  btn_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
  textview = gtk_text_view_new();
  label_time = gtk_label_new(NULL);

  counter_data->flag = 0; //we are just starting the counter.
  counter_data->textview = textview;
  counter_data->label = label_time;
  gtk_box_pack_start(GTK_BOX(parentBox), btn_box, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(parentBox), textview, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(parentBox), label_time, TRUE, TRUE, 0);

  btn = gtk_button_new_with_label("Start counting");
  g_signal_connect(btn, "clicked", G_CALLBACK(start_counter),counter_data);
  gtk_container_add(GTK_CONTAINER(btn_box), btn);

  gtk_container_add(GTK_CONTAINER(window), parentBox);

  gtk_widget_show_all (window);


}

int main (int argc, char **argv){

  /* Counter_data counter_data; */
  /* counter_data.flag = 0; //we are just starting the counter. */
  /* counter_data.test = "testing..."; */
  /* g_print("%d\n", ((gint)counter_data.flag)); */
  Screen_size size;
  size.x = 600;
  size.y = 480;
  GtkApplication *app;
  int status;
  app = gtk_application_new ("org.gtk.examples", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), &size);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

