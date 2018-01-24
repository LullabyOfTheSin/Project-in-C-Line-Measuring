#include "Interface.h"

void InterfaceInit(int argc, char *argv[])
{
    GtkWidget *okno;
    GtkWidget *image;

    gtk_init (&argc, &argv);

    okno=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    image=gtk_image_new_from_file("abc.png");
    gtk_container_add(GTK_CONTAINER(okno),image);
    gtk_widget_show(image);
    gtk_widget_show(okno);

    gtk_main ();
}
